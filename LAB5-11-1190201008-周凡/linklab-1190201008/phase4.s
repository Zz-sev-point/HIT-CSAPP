
phase4.o:     file format elf32-i386


Disassembly of section .text:

00000000 <do_phase>:
   0:	f3 0f 1e fb          	endbr32 
   4:	55                   	push   %ebp
   5:	89 e5                	mov    %esp,%ebp
   7:	83 ec 28             	sub    $0x28,%esp
   a:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
  10:	89 45 f4             	mov    %eax,-0xc(%ebp)
  13:	31 c0                	xor    %eax,%eax
  15:	c7 45 e9 4d 43 45 4f 	movl   $0x4f45434d,-0x17(%ebp)
  1c:	c7 45 ed 53 56 4e 46 	movl   $0x464e5653,-0x13(%ebp)
  23:	66 c7 45 f1 5a 48    	movw   $0x485a,-0xf(%ebp)
  29:	c6 45 f3 00          	movb   $0x0,-0xd(%ebp)
  2d:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
  34:	e9 e3 00 00 00       	jmp    11c <do_phase+0x11c>
  39:	8d 55 e9             	lea    -0x17(%ebp),%edx
  3c:	8b 45 e4             	mov    -0x1c(%ebp),%eax
  3f:	01 d0                	add    %edx,%eax
  41:	0f b6 00             	movzbl (%eax),%eax
  44:	88 45 e3             	mov    %al,-0x1d(%ebp)
  47:	0f be 45 e3          	movsbl -0x1d(%ebp),%eax
  4b:	83 e8 41             	sub    $0x41,%eax
  4e:	83 f8 19             	cmp    $0x19,%eax
  51:	0f 87 b1 00 00 00    	ja     108 <do_phase+0x108>
  57:	8b 04 85 00 00 00 00 	mov    0x0(,%eax,4),%eax
  5e:	3e ff e0             	notrack jmp *%eax
  61:	c6 45 e3 5a          	movb   $0x5a,-0x1d(%ebp)
  65:	e9 9e 00 00 00       	jmp    108 <do_phase+0x108>
  6a:	c6 45 e3 49          	movb   $0x49,-0x1d(%ebp)
  6e:	e9 95 00 00 00       	jmp    108 <do_phase+0x108>
  73:	c6 45 e3 5b          	movb   $0x5b,-0x1d(%ebp)
  77:	e9 8c 00 00 00       	jmp    108 <do_phase+0x108>
  7c:	c6 45 e3 63          	movb   $0x63,-0x1d(%ebp)
  80:	e9 83 00 00 00       	jmp    108 <do_phase+0x108>
  85:	c6 45 e3 35          	movb   $0x35,-0x1d(%ebp)
  89:	eb 7d                	jmp    108 <do_phase+0x108>
  8b:	c6 45 e3 32          	movb   $0x32,-0x1d(%ebp)
  8f:	eb 77                	jmp    108 <do_phase+0x108>
  91:	c6 45 e3 39          	movb   $0x39,-0x1d(%ebp)
  95:	eb 71                	jmp    108 <do_phase+0x108>
  97:	c6 45 e3 30          	movb   $0x30,-0x1d(%ebp)
  9b:	eb 6b                	jmp    108 <do_phase+0x108>
  9d:	c6 45 e3 43          	movb   $0x43,-0x1d(%ebp)
  a1:	eb 65                	jmp    108 <do_phase+0x108>
  a3:	c6 45 e3 7a          	movb   $0x7a,-0x1d(%ebp)
  a7:	eb 5f                	jmp    108 <do_phase+0x108>
  a9:	c6 45 e3 33          	movb   $0x33,-0x1d(%ebp)
  ad:	eb 59                	jmp    108 <do_phase+0x108>
  af:	c6 45 e3 3c          	movb   $0x3c,-0x1d(%ebp)
  b3:	eb 53                	jmp    108 <do_phase+0x108>
  b5:	c6 45 e3 36          	movb   $0x36,-0x1d(%ebp)
  b9:	eb 4d                	jmp    108 <do_phase+0x108>
  bb:	c6 45 e3 50          	movb   $0x50,-0x1d(%ebp)
  bf:	eb 47                	jmp    108 <do_phase+0x108>
  c1:	c6 45 e3 31          	movb   $0x31,-0x1d(%ebp)
  c5:	eb 41                	jmp    108 <do_phase+0x108>
  c7:	c6 45 e3 48          	movb   $0x48,-0x1d(%ebp)
  cb:	eb 3b                	jmp    108 <do_phase+0x108>
  cd:	c6 45 e3 6b          	movb   $0x6b,-0x1d(%ebp)
  d1:	eb 35                	jmp    108 <do_phase+0x108>
  d3:	c6 45 e3 76          	movb   $0x76,-0x1d(%ebp)
  d7:	eb 2f                	jmp    108 <do_phase+0x108>
  d9:	c6 45 e3 42          	movb   $0x42,-0x1d(%ebp)
  dd:	eb 29                	jmp    108 <do_phase+0x108>
  df:	c6 45 e3 3b          	movb   $0x3b,-0x1d(%ebp)
  e3:	eb 23                	jmp    108 <do_phase+0x108>
  e5:	c6 45 e3 58          	movb   $0x58,-0x1d(%ebp)
  e9:	eb 1d                	jmp    108 <do_phase+0x108>
  eb:	c6 45 e3 5a          	movb   $0x5a,-0x1d(%ebp)
  ef:	eb 17                	jmp    108 <do_phase+0x108>
  f1:	c6 45 e3 38          	movb   $0x38,-0x1d(%ebp)
  f5:	eb 11                	jmp    108 <do_phase+0x108>
  f7:	c6 45 e3 37          	movb   $0x37,-0x1d(%ebp)
  fb:	eb 0b                	jmp    108 <do_phase+0x108>
  fd:	c6 45 e3 50          	movb   $0x50,-0x1d(%ebp)
 101:	eb 05                	jmp    108 <do_phase+0x108>
 103:	c6 45 e3 34          	movb   $0x34,-0x1d(%ebp)
 107:	90                   	nop
 108:	0f be 45 e3          	movsbl -0x1d(%ebp),%eax
 10c:	83 ec 0c             	sub    $0xc,%esp
 10f:	50                   	push   %eax
 110:	e8 fc ff ff ff       	call   111 <do_phase+0x111>
 115:	83 c4 10             	add    $0x10,%esp
 118:	83 45 e4 01          	addl   $0x1,-0x1c(%ebp)
 11c:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 11f:	83 f8 09             	cmp    $0x9,%eax
 122:	0f 86 11 ff ff ff    	jbe    39 <do_phase+0x39>
 128:	83 ec 0c             	sub    $0xc,%esp
 12b:	6a 0a                	push   $0xa
 12d:	e8 fc ff ff ff       	call   12e <do_phase+0x12e>
 132:	83 c4 10             	add    $0x10,%esp
 135:	90                   	nop
 136:	8b 45 f4             	mov    -0xc(%ebp),%eax
 139:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 140:	74 05                	je     147 <do_phase+0x147>
 142:	e8 fc ff ff ff       	call   143 <do_phase+0x143>
 147:	c9                   	leave  
 148:	c3                   	ret    
