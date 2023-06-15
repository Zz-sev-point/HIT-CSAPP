
phase5.o:     file format elf32-i386


Disassembly of section .text:

00000000 <transform_code>:
   0:	f3 0f 1e fb          	endbr32 
   4:	55                   	push   %ebp
   5:	89 e5                	mov    %esp,%ebp
   7:	8b 45 0c             	mov    0xc(%ebp),%eax
   a:	8b 04 85 00 00 00 00 	mov    0x0(,%eax,4),%eax
//0d 0a01 映射到MWePKR
  11:	83 e0 07             	and    $0x7,%eax
  14:	83 f8 07             	cmp    $0x7,%eax
  17:	77 64                	ja     7d <transform_code+0x7d>
  19:	8b 04 85 c0 00 00 00 	mov    0xc0(,%eax,4),%eax
//*1c 0501 映射到MWePKR
  20:	3e ff e0             	notrack jmp *%eax
  23:	f7 55 08             	notl   0x8(%ebp)
  26:	eb 59                	jmp    81 <transform_code+0x81>
  28:	8b 45 0c             	mov    0xc(%ebp),%eax
  2b:	8b 04 85 00 00 00 00 	mov    0x0(,%eax,4),%eax
//2e 0a01 映射到MWePKR
  32:	83 e0 03             	and    $0x3,%eax
  35:	89 c1                	mov    %eax,%ecx
  37:	d3 7d 08             	sarl   %cl,0x8(%ebp)
  3a:	eb 45                	jmp    81 <transform_code+0x81>
  3c:	8b 45 0c             	mov    0xc(%ebp),%eax
  3f:	8b 04 85 00 00 00 00 	mov    0x0(,%eax,4),%eax
//*42 0a01 映射到MWePKR
  46:	f7 d0                	not    %eax
  48:	21 45 08             	and    %eax,0x8(%ebp)
  4b:	eb 34                	jmp    81 <transform_code+0x81>
  4d:	8b 45 0c             	mov    0xc(%ebp),%eax
  50:	8b 04 85 00 00 00 00 	mov    0x0(,%eax,4),%eax
//53 0a01 映射到MWePKR
  57:	c1 e0 08             	shl    $0x8,%eax
  5a:	09 45 08             	or     %eax,0x8(%ebp)
  5d:	eb 22                	jmp    81 <transform_code+0x81>
  5f:	8b 45 0c             	mov    0xc(%ebp),%eax
  62:	8b 04 85 00 00 00 00 	mov    0x0(,%eax,4),%eax
//65 0a01 映射到MWePKR
  69:	31 45 08             	xor    %eax,0x8(%ebp)
  6c:	eb 13                	jmp    81 <transform_code+0x81>
  6e:	8b 45 0c             	mov    0xc(%ebp),%eax
  71:	8b 04 85 00 00 00 00 	mov    0x0(,%eax,4),%eax
//74 0a01 映射到MWePKR
  78:	89 45 08             	mov    %eax,0x8(%ebp)
  7b:	eb 04                	jmp    81 <transform_code+0x81>
  7d:	f7 5d 08             	negl   0x8(%ebp)
  80:	90                   	nop
  81:	8b 45 08             	mov    0x8(%ebp),%eax
  84:	5d                   	pop    %ebp
  85:	c3                   	ret    

00000086 <generate_code>:
  86:	f3 0f 1e fb          	endbr32 
  8a:	55                   	push   %ebp
  8b:	89 e5                	mov    %esp,%ebp
  8d:	83 ec 10             	sub    $0x10,%esp
  90:	8b 45 08             	mov    0x8(%ebp),%eax
  93:	a2 00 00 00 00       	mov    %al,0x0
//*94 0d01 映射到CODE
  98:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
  9f:	eb 1f                	jmp    c0 <generate_code+0x3a>
  a1:	0f b6 05 00 00 00 00 	movzbl 0x0,%eax
//a4 0d01 映射到CODE
  a8:	0f be c0             	movsbl %al,%eax
  ab:	ff 75 fc             	pushl  -0x4(%ebp)
  ae:	50                   	push   %eax
  af:	e8 fc ff ff ff       	call   b0 <generate_code+0x2a>
//b0 0e02 映射到transform_code
  b4:	83 c4 08             	add    $0x8,%esp
  b7:	a2 00 00 00 00       	mov    %al,0x0
//b8 0d01 映射到CODE
  bc:	83 45 fc 01          	addl   $0x1,-0x4(%ebp)
  c0:	8b 45 fc             	mov    -0x4(%ebp),%eax
  c3:	83 f8 0e             	cmp    $0xe,%eax
  c6:	76 d9                	jbe    a1 <generate_code+0x1b>
  c8:	90                   	nop
  c9:	90                   	nop
  ca:	c9                   	leave  
  cb:	c3                   	ret    

000000cc <encode>:
  cc:	f3 0f 1e fb          	endbr32 
  d0:	55                   	push   %ebp
  d1:	89 e5                	mov    %esp,%ebp
  d3:	83 ec 18             	sub    $0x18,%esp
  d6:	83 ec 0c             	sub    $0xc,%esp
  d9:	ff 75 08             	pushl  0x8(%ebp)
  dc:	e8 fc ff ff ff       	call   dd <encode+0x11>
//dd 1102 映射到strlen
  e1:	83 c4 10             	add    $0x10,%esp
  e4:	89 45 f4             	mov    %eax,-0xc(%ebp)
  e7:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
  ee:	eb 5c                	jmp    14c <encode+0x80>
  f0:	8b 55 f0             	mov    -0x10(%ebp),%edx
  f3:	8b 45 08             	mov    0x8(%ebp),%eax
  f6:	01 d0                	add    %edx,%eax
  f8:	0f b6 00             	movzbl (%eax),%eax
  fb:	0f be c0             	movsbl %al,%eax
  fe:	0f b6 90 00 00 00 00 	movzbl 0x0(%eax),%edx
//*101 0b01 映射到uBePoV
 105:	0f b6 05 00 00 00 00 	movzbl 0x0,%eax
//*108 0d01 映射到CODE
 10c:	89 d1                	mov    %edx,%ecx
 10e:	31 c1                	xor    %eax,%ecx
 110:	8b 55 f0             	mov    -0x10(%ebp),%edx
 113:	8b 45 08             	mov    0x8(%ebp),%eax
 116:	01 d0                	add    %edx,%eax
 118:	83 e1 7f             	and    $0x7f,%ecx
 11b:	89 ca                	mov    %ecx,%edx
 11d:	88 10                	mov    %dl,(%eax)
 11f:	8b 55 f0             	mov    -0x10(%ebp),%edx
 122:	8b 45 08             	mov    0x8(%ebp),%eax
 125:	01 d0                	add    %edx,%eax
 127:	0f b6 00             	movzbl (%eax),%eax
 12a:	3c 1f                	cmp    $0x1f,%al
 12c:	7e 0f                	jle    13d <encode+0x71>
 12e:	8b 55 f0             	mov    -0x10(%ebp),%edx
 131:	8b 45 08             	mov    0x8(%ebp),%eax
 134:	01 d0                	add    %edx,%eax
 136:	0f b6 00             	movzbl (%eax),%eax
 139:	3c 7f                	cmp    $0x7f,%al
 13b:	75 0b                	jne    148 <encode+0x7c>
 13d:	8b 55 f0             	mov    -0x10(%ebp),%edx
 140:	8b 45 08             	mov    0x8(%ebp),%eax
 143:	01 d0                	add    %edx,%eax
 145:	c6 00 20             	movb   $0x20,(%eax)
 148:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 14c:	8b 45 f0             	mov    -0x10(%ebp),%eax
 14f:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 152:	7c 9c                	jl     f0 <encode+0x24>
 154:	8b 45 f4             	mov    -0xc(%ebp),%eax
 157:	c9                   	leave  
 158:	c3                   	ret    

00000159 <do_phase>:
 159:	f3 0f 1e fb          	endbr32 
 15d:	55                   	push   %ebp
 15e:	89 e5                	mov    %esp,%ebp
 160:	83 ec 08             	sub    $0x8,%esp
 163:	68 d1 00 00 00       	push   $0xd1
 168:	e8 fc ff ff ff       	call   169 <do_phase+0x10>
//169 0f02 映射到generate_code
 16d:	83 c4 04             	add    $0x4,%esp
 170:	83 ec 0c             	sub    $0xc,%esp
 173:	68 00 00 00 00       	push   $0x0
//*174 0c01 映射到BUF
 178:	e8 fc ff ff ff       	call   179 <do_phase+0x20>
//*179 1002 映射到encode
 17d:	83 c4 10             	add    $0x10,%esp
 180:	83 ec 0c             	sub    $0xc,%esp
 183:	68 00 00 00 00       	push   $0x0
//184 0c01 映射到BUF
 188:	e8 fc ff ff ff       	call   189 <do_phase+0x30>
//189 1302 映射到puts
 18d:	83 c4 10             	add    $0x10,%esp
 190:	90                   	nop
 191:	c9                   	leave  
 192:	c3                   	ret    
