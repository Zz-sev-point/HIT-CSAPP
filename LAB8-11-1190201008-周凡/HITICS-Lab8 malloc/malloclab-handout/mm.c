/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 *
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "1190201008",
    /* First member's full name */
    "Zhou Fan",
    /* First member's email address */
    "434696317@qq.com",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

/* Basic constants and macros */
/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) ((((size) + (DSIZE - 1)) / (DSIZE)) * (DSIZE)) //对齐
#define WSIZE 4
#define DSIZE 8
#define INITCHUNKSIZE (1 << 4)
#define CHUNKSIZE (1 << 4)
#define MAX_LEN 16

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#define PACK(size, alloc) ((size) | (alloc))

/* Read and write a word at address p */
#define GET(p) (*(size_t *)(p))
#define PUT(p, val) (*(size_t *)(p) = (val))

/* Read the size and allocated fields from address p */
#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp) ((char *)(bp)-WSIZE)
#define FTRP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)

/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(((char *)(bp)-WSIZE)))
#define PREV_BLKP(bp) ((char *)(bp)-GET_SIZE(((char *)(bp)-DSIZE)))

#define SET_PTR(p, bp) (*(unsigned int *)(p) = (unsigned int)(bp))

#define PRED_PTR(bp) ((char *)(bp))
#define SUCC_PTR(bp) ((char *)(bp) + WSIZE)

#define PRED(bp) (*(char **)(bp))
#define SUCC(bp) (*(char **)(SUCC_PTR(bp)))

// Functions
static void *extend_heap(size_t size);
static void *coalesce(void *ptr);
static void *place(void *ptr, size_t asize);
static void insert_node(void *ptr, size_t size);
static void delete_node(void *ptr);
int mm_check();

// Global variables
static char *heap_listp; //第一个block的指针
void *Lists[MAX_LEN]; // 分离的空闲链表

/*
 * mm_init - initialize the malloc package.
 */
int mm_init(void)
{
    for(int i=0;i<MAX_LEN;i++)
        Lists[i] = NULL;
    if((heap_listp = mem_sbrk(4 * WSIZE))==NULL)
        return -1;
    PUT(heap_listp, 0);//对齐
    PUT(heap_listp + (1 * WSIZE), PACK(DSIZE, 1));//序言块设置
    PUT(heap_listp + (2 * WSIZE), PACK(DSIZE, 1));
    PUT(heap_listp + (3 * WSIZE), PACK(0, 1));//结尾块设置
    if(extend_heap(INITCHUNKSIZE)==NULL)//初始化扩展
        return -1;
    return 0;
}

/*
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
    void *ptr = NULL;
    size_t ext_size;
    int i = 0;
    if(size==0)
        return NULL;
    if(size<=DSIZE)
        size = 2 * DSIZE;
    else
        size = ALIGN(size + DSIZE);
    size_t asize = size;
    while(i < MAX_LEN){
        if(i==MAX_LEN-1 || (asize<=1) && (Lists[i]!=NULL)){
            ptr = Lists[i];
            while((ptr!=NULL) && (size>GET_SIZE(HDRP(ptr))))
                ptr = PRED(ptr);
            if(ptr!=NULL)
                break;
        }
        asize >>= 1;
        i++;
    }
    if(ptr == NULL){
	ext_size = MAX(size, CHUNKSIZE);
        if((ptr = extend_heap(ext_size)) == NULL)
            return NULL;
    }
    ptr = place(ptr, size);
    mm_check();
    return ptr;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr)
{
    size_t size = GET_SIZE(HDRP(ptr));
    PUT(HDRP(ptr), PACK(size, 0));
    PUT(FTRP(ptr), PACK(size, 0));
    insert_node(ptr, size);
    coalesce(ptr);
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
    void *newptr = ptr;
    size_t copySize = size;
    int remaining, extend;
    if(size == 0)
        return NULL;
    if(copySize <= DSIZE)
        copySize = 2 * DSIZE;
    else
        copySize = ALIGN(size + DSIZE);
    remaining = GET_SIZE(HDRP(ptr)) - copySize;
    if(remaining < 0){
        if(!GET_SIZE(HDRP(NEXT_BLKP(ptr)))){
            extend = MAX(-remaining, CHUNKSIZE);
            if(extend_heap(extend) == NULL)
                return NULL;
            remaining += extend;
            delete_node(NEXT_BLKP(ptr));
            PUT(HDRP(ptr), PACK(copySize + remaining, 1));
            PUT(FTRP(ptr), PACK(copySize + remaining, 1));
        }
        else if(!GET_ALLOC(HDRP(NEXT_BLKP(ptr)))){
            remaining = GET_SIZE(HDRP(ptr)) + GET_SIZE(HDRP(NEXT_BLKP(ptr))) - copySize;
            if(remaining < 0){
                newptr = mm_malloc(copySize - DSIZE);
                memcpy(newptr, ptr, MIN(size, copySize));
                mm_free(ptr);
            }
            else{
                delete_node(NEXT_BLKP(ptr));
                PUT(HDRP(ptr), PACK(copySize + remaining, 1));
                PUT(FTRP(ptr), PACK(copySize + remaining, 1));
            }
        }
        else{
            newptr = mm_malloc(copySize - DSIZE);
            memcpy(newptr, ptr, MIN(size, copySize));
            mm_free(ptr);
        }
    }
    mm_check();
    return newptr;
}

//扩展堆
static void *extend_heap(size_t size)
{
    char *ptr;
    size = ALIGN(size);
    if((ptr = mem_sbrk(size)) == (void *)-1)
        return NULL;
    PUT(HDRP(ptr), PACK(size, 0));
    PUT(FTRP(ptr), PACK(size, 0));
    PUT(HDRP(NEXT_BLKP(ptr)), PACK(0, 1));
    insert_node(ptr, size);
    mm_check();
    return coalesce(ptr);
}

//插入节点
static void insert_node(void *ptr, size_t size)
{
    int i = 0;
    void *search_ptr = NULL, *insert_ptr = NULL;
    //查找合适的链表
    while((i<MAX_LEN-1) && (size>1)){
        size >>= 1;
        i++;
    }
    search_ptr = Lists[i];
    //查找合适的插入位置
    while((search_ptr!=NULL) && (size>GET_SIZE(HDRP(search_ptr)))){
        insert_ptr = search_ptr;
        search_ptr = PRED(search_ptr);
    }
    //将ptr插入到search_ptr(前驱)和insert_ptr(后继)之间
    if(search_ptr!=NULL){
        //前驱后继都不为空
        if(insert_ptr!=NULL){
            SET_PTR(PRED_PTR(ptr), search_ptr);
            SET_PTR(SUCC_PTR(search_ptr), ptr);
            SET_PTR(SUCC_PTR(ptr), insert_ptr);
            SET_PTR(PRED_PTR(insert_ptr), ptr);
        }
        //后继为空
        else{
            SET_PTR(PRED_PTR(ptr), search_ptr);
            SET_PTR(SUCC_PTR(search_ptr), ptr);
            SET_PTR(SUCC_PTR(ptr), NULL);
            Lists[i] = ptr;
        }
    }
    else{
        //前驱为空
        if(insert_ptr!=NULL){
            SET_PTR(PRED_PTR(ptr), NULL);
            SET_PTR(SUCC_PTR(ptr), insert_ptr);
            SET_PTR(PRED_PTR(insert_ptr), ptr);
        }
        //前驱后继都为空
        else{
            SET_PTR(PRED_PTR(ptr), NULL);
            SET_PTR(SUCC_PTR(ptr), NULL);
            Lists[i] = ptr;
        }
    }
}

//删除节点
static void delete_node(void *ptr)
{
    int i = 0;
    size_t size = GET_SIZE(HDRP(ptr));
    //查找合适的链表
    while((i<MAX_LEN-1) && (size>1)){
        size >>= 1;
        i++;
    }
    if(PRED(ptr)!=NULL){
        if(SUCC(ptr)!=NULL){
            SET_PTR(PRED_PTR(SUCC(ptr)), PRED(ptr));
            SET_PTR(SUCC_PTR(PRED(ptr)), SUCC(ptr));
        }
        else{
            SET_PTR(SUCC_PTR(PRED(ptr)), NULL);
            Lists[i] = PRED(ptr);
        }
    }
    else{
        if(SUCC(ptr)!=NULL)
            SET_PTR(PRED_PTR(SUCC(ptr)), NULL);
        else
            Lists[i] = NULL;
    }
    mm_check();
}

//合并块
static void *coalesce(void *ptr)
{
    size_t prev_alloc = GET_ALLOC(HDRP(PREV_BLKP(ptr)));
    size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(ptr)));
    size_t size = GET_SIZE(HDRP(ptr));
    if(prev_alloc && next_alloc)
        return ptr;
    else if(prev_alloc && !next_alloc){
        delete_node(ptr);
        delete_node(NEXT_BLKP(ptr));
        size += GET_SIZE(HDRP(NEXT_BLKP(ptr)));
        PUT(HDRP(ptr), PACK(size, 0));
        PUT(FTRP(ptr), PACK(size, 0));
    }
    else if(!prev_alloc && next_alloc){
        delete_node(ptr);
        delete_node(PREV_BLKP(ptr));
        size += GET_SIZE(HDRP(PREV_BLKP(ptr)));
        PUT(HDRP(PREV_BLKP(ptr)), PACK(size, 0));
        PUT(FTRP(ptr), PACK(size, 0));
        ptr = PREV_BLKP(ptr);
    }
    else{
        delete_node(ptr);
        delete_node(PREV_BLKP(ptr));
        delete_node(NEXT_BLKP(ptr));
        size += (GET_SIZE(HDRP(PREV_BLKP(ptr))) + GET_SIZE(HDRP(NEXT_BLKP(ptr))));
        PUT(HDRP(PREV_BLKP(ptr)), PACK(size, 0));
        PUT(FTRP(NEXT_BLKP(ptr)), PACK(size, 0));
        ptr = PREV_BLKP(ptr);
    }
    insert_node(ptr, size);
    return ptr;
}

//在ptr对应的块中放置asize大小的数据
//如果剩余空闲空间至少为最小块则拆分
static void *place(void *ptr, size_t asize)
{
    size_t full_size = GET_SIZE(HDRP(ptr));
    size_t remaining = full_size - asize;
    delete_node(ptr);
    if(remaining <= 2 * DSIZE){
        PUT(HDRP(ptr), PACK(full_size, 1));
        PUT(FTRP(ptr), PACK(full_size, 1));
    }
    else if(asize >= 110){
        PUT(HDRP(ptr), PACK(remaining, 0));
        PUT(FTRP(ptr), PACK(remaining, 0));
        PUT(HDRP(NEXT_BLKP(ptr)), PACK(asize, 1));
        PUT(FTRP(NEXT_BLKP(ptr)), PACK(asize, 1));
        insert_node(ptr, remaining);
        return NEXT_BLKP(ptr);
    }
    else{
        PUT(HDRP(ptr), PACK(asize, 1));
        PUT(FTRP(ptr), PACK(asize, 1));
        PUT(HDRP(NEXT_BLKP(ptr)), PACK(remaining, 0));
        PUT(FTRP(NEXT_BLKP(ptr)), PACK(remaining, 0));
        insert_node(NEXT_BLKP(ptr), remaining);
    }
    return ptr;
}

//检查堆的一致性
int mm_check()
{
    void *ptr;
    int count = 0, cnt = 0;
    for(int i=0;i<MAX_LEN;i++){
        ptr = Lists[i];
        if(ptr==NULL)
            continue;
        //遍历链表中的所有块
        while(ptr!=NULL){
            //检验是否有相邻的空闲块没有合并
            if(!GET_ALLOC(HDRP(NEXT_BLKP(ptr))) || !GET_ALLOC(HDRP(PREV_BLKP(ptr)))){
                printf("Some adjacent blocks are unmerged!");
                return 0;
            }
            //检验空闲链表中的块是否都处于free状态
            if(!GET_ALLOC(HDRP(ptr))){
                printf("Certain block in the list is not free!");
                return 0;
            }
            count++;//记录链表中的块总数
            ptr = PREV_BLKP(ptr);
        }
    }
    ptr = heap_listp + DSIZE;
    while(GET_SIZE(HDRP(ptr))>0){
        if(GET_ALLOC(HDRP(ptr)))
            cnt++;//记录空闲块总个数
        ptr = NEXT_BLKP(ptr);
    }
    //检验是否所有空闲块都在链表中
    if(count!=cnt){
        printf("Not every block is in the list!");
        return 0;
    }
    return 1;
}
