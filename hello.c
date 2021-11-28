#include <stdio.h>

int main() {
    int a = 5;
    printf("hello world\n");
    return 0;
}

/** objdump -h a.out
 Idx Name          Size      VMA               LMA               File off  Algn
  1 .note.ABI-tag 00000020  0000000000400254  0000000000400254  00000254  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  2 .note.gnu.build-id 00000024  0000000000400274  0000000000400274  00000274  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  3 .gnu.hash     0000001c  0000000000400298  0000000000400298  00000298  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .dynsym       00000090  00000000004002b8  00000000004002b8  000002b8  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  5 .dynstr       00000073  0000000000400348  0000000000400348  00000348  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  6 .gnu.version  0000000c  00000000004003bc  00000000004003bc  000003bc  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  7 .gnu.version_r 00000020  00000000004003c8  00000000004003c8  000003c8  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  8 .rela.dyn     00000060  00000000004003e8  00000000004003e8  000003e8  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  9 .rela.plt     00000018  0000000000400448  0000000000400448  00000448  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 10 .init         0000001b  0000000000400460  0000000000400460  00000460  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 11 .plt          00000020  0000000000400480  0000000000400480  00000480  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 12 .text         00000185  00000000004004a0  00000000004004a0  000004a0  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 13 .fini         0000000d  0000000000400628  0000000000400628  00000628  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 14 .rodata       0000001c  0000000000400638  0000000000400638  00000638  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 15 .eh_frame_hdr 0000003c  0000000000400654  0000000000400654  00000654  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 16 .eh_frame     000000e8  0000000000400690  0000000000400690  00000690  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 17 .init_array   00000008  0000000000600e00  0000000000600e00  00000e00  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 18 .fini_array   00000008  0000000000600e08  0000000000600e08  00000e08  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 19 .dynamic      000001d0  0000000000600e10  0000000000600e10  00000e10  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 20 .got          00000020  0000000000600fe0  0000000000600fe0  00000fe0  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 21 .got.plt      00000020  0000000000601000  0000000000601000  00001000  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 22 .data         00000004  0000000000601020  0000000000601020  00001020  2**0
                  CONTENTS, ALLOC, LOAD, DATA
 23 .bss          00000004  0000000000601024  0000000000601024  00001024  2**0
                  ALLOC
 24 .comment      0000002c  0000000000000000  0000000000000000  00001024  2**0
                  CONTENTS, READONLY
 25 .gnu.build.attributes 00001b60  0000000000a01028  0000000000a01028  00001050  2**2
                  CONTENTS, READONLY
 * 

 ---
objdump -d a.out 

a.out:     file format elf64-x86-64

Disassembly of section .init:

0000000000400460 <_init>:
  400460:       f3 0f 1e fa             endbr64 
  400464:       48 83 ec 08             sub    $0x8,%rsp
  400468:       48 8b 05 81 0b 20 00    mov    0x200b81(%rip),%rax        # 600ff0 <__gmon_start__>
  40046f:       48 85 c0                test   %rax,%rax
  400472:       74 02                   je     400476 <_init+0x16>
  400474:       ff d0                   callq  *%rax
  400476:       48 83 c4 08             add    $0x8,%rsp
  40047a:       c3                      retq   

Disassembly of section .plt:

0000000000400480 <.plt>:
  400480:       ff 35 82 0b 20 00       pushq  0x200b82(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400486:       ff 25 84 0b 20 00       jmpq   *0x200b84(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40048c:       0f 1f 40 00             nopl   0x0(%rax)

0000000000400490 <puts@plt>:
  400490:       ff 25 82 0b 20 00       jmpq   *0x200b82(%rip)        # 601018 <puts@GLIBC_2.2.5>
  400496:       68 00 00 00 00          pushq  $0x0
  40049b:       e9 e0 ff ff ff          jmpq   400480 <.plt>

Disassembly of section .text:

00000000004004a0 <_start>:
  4004a0:       f3 0f 1e fa             endbr64 
  4004a4:       31 ed                   xor    %ebp,%ebp
  4004a6:       49 89 d1                mov    %rdx,%r9
  4004a9:       5e                      pop    %rsi
  4004aa:       48 89 e2                mov    %rsp,%rdx
  4004ad:       48 83 e4 f0             and    $0xfffffffffffffff0,%rsp
  4004b1:       50                      push   %rax
  4004b2:       54                      push   %rsp
  4004b3:       49 c7 c0 20 06 40 00    mov    $0x400620,%r8
  4004ba:       48 c7 c1 b0 05 40 00    mov    $0x4005b0,%rcx
  4004c1:       48 c7 c7 86 05 40 00    mov    $0x400586,%rdi
  4004c8:       ff 15 1a 0b 20 00       callq  *0x200b1a(%rip)        # 600fe8 <__libc_start_main@GLIBC_2.2.5>
  4004ce:       f4                      hlt    

00000000004004cf <.annobin_init.c>:
  4004cf:       90                      nop

00000000004004d0 <_dl_relocate_static_pie>:
  4004d0:       f3 0f 1e fa             endbr64 
  4004d4:       c3                      retq   

00000000004004d5 <.annobin__dl_relocate_static_pie.end>:
  4004d5:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
  4004dc:       00 00 00 
  4004df:       90                      nop

00000000004004e0 <deregister_tm_clones>:
  4004e0:       48 8d 3d 41 0b 20 00    lea    0x200b41(%rip),%rdi        # 601028 <__TMC_END__>
  4004e7:       48 8d 05 3a 0b 20 00    lea    0x200b3a(%rip),%rax        # 601028 <__TMC_END__>
  4004ee:       48 39 f8                cmp    %rdi,%rax
  4004f1:       74 15                   je     400508 <deregister_tm_clones+0x28>
  4004f3:       48 8b 05 e6 0a 20 00    mov    0x200ae6(%rip),%rax        # 600fe0 <_ITM_deregisterTMCloneTable>
  4004fa:       48 85 c0                test   %rax,%rax
  4004fd:       74 09                   je     400508 <deregister_tm_clones+0x28>
  4004ff:       ff e0                   jmpq   *%rax
  400501:       0f 1f 80 00 00 00 00    nopl   0x0(%rax)
  400508:       c3                      retq   
  400509:       0f 1f 80 00 00 00 00    nopl   0x0(%rax)

0000000000400510 <register_tm_clones>:
  400510:       48 8d 3d 11 0b 20 00    lea    0x200b11(%rip),%rdi        # 601028 <__TMC_END__>
  400517:       48 8d 35 0a 0b 20 00    lea    0x200b0a(%rip),%rsi        # 601028 <__TMC_END__>
  40051e:       48 29 fe                sub    %rdi,%rsi
  400521:       48 c1 fe 03             sar    $0x3,%rsi
  400525:       48 89 f0                mov    %rsi,%rax
  400528:       48 c1 e8 3f             shr    $0x3f,%rax
  40052c:       48 01 c6                add    %rax,%rsi
  40052f:       48 d1 fe                sar    %rsi
  400532:       74 14                   je     400548 <register_tm_clones+0x38>
  400534:       48 8b 05 bd 0a 20 00    mov    0x200abd(%rip),%rax        # 600ff8 <_ITM_registerTMCloneTable>
  40053b:       48 85 c0                test   %rax,%rax
  40053e:       74 08                   je     400548 <register_tm_clones+0x38>
  400540:       ff e0                   jmpq   *%rax
  400542:       66 0f 1f 44 00 00       nopw   0x0(%rax,%rax,1)
  400548:       c3                      retq   
  400549:       0f 1f 80 00 00 00 00    nopl   0x0(%rax)

0000000000400550 <__do_global_dtors_aux>:
  400550:       f3 0f 1e fa             endbr64 
  400554:       80 3d c9 0a 20 00 00    cmpb   $0x0,0x200ac9(%rip)        # 601024 <_edata>
  40055b:       75 13                   jne    400570 <__do_global_dtors_aux+0x20>
  40055d:       55                      push   %rbp
  40055e:       48 89 e5                mov    %rsp,%rbp
  400561:       e8 7a ff ff ff          callq  4004e0 <deregister_tm_clones>
  400566:       c6 05 b7 0a 20 00 01    movb   $0x1,0x200ab7(%rip)        # 601024 <_edata>
  40056d:       5d                      pop    %rbp
  40056e:       c3                      retq   
  40056f:       90                      nop
  400570:       c3                      retq   
  400571:       0f 1f 44 00 00          nopl   0x0(%rax,%rax,1)
  400576:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
  40057d:       00 00 00 

0000000000400580 <frame_dummy>:
  400580:       f3 0f 1e fa             endbr64 
  400584:       eb 8a                   jmp    400510 <register_tm_clones>

0000000000400586 <main>:
  400586:       55                      push   %rbp
  400587:       48 89 e5                mov    %rsp,%rbp
  40058a:       48 83 ec 10             sub    $0x10,%rsp
  40058e:       c7 45 fc 05 00 00 00    movl   $0x5,-0x4(%rbp)
  400595:       bf 48 06 40 00          mov    $0x400648,%edi
  40059a:       e8 f1 fe ff ff          callq  400490 <puts@plt>
  40059f:       b8 00 00 00 00          mov    $0x0,%eax
  4005a4:       c9                      leaveq 
  4005a5:       c3                      retq   
  4005a6:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
  4005ad:       00 00 00 

00000000004005b0 <__libc_csu_init>:
  4005b0:       f3 0f 1e fa             endbr64 
  4005b4:       41 57                   push   %r15
  4005b6:       49 89 d7                mov    %rdx,%r15
  4005b9:       41 56                   push   %r14
  4005bb:       49 89 f6                mov    %rsi,%r14
  4005be:       41 55                   push   %r13
  4005c0:       41 89 fd                mov    %edi,%r13d
  4005c3:       41 54                   push   %r12
  4005c5:       4c 8d 25 34 08 20 00    lea    0x200834(%rip),%r12        # 600e00 <__frame_dummy_init_array_entry>
  4005cc:       55                      push   %rbp
  4005cd:       48 8d 2d 34 08 20 00    lea    0x200834(%rip),%rbp        # 600e08 <__init_array_end>
  4005d4:       53                      push   %rbx
  4005d5:       4c 29 e5                sub    %r12,%rbp
  4005d8:       48 83 ec 08             sub    $0x8,%rsp
  4005dc:       e8 7f fe ff ff          callq  400460 <_init>
  4005e1:       48 c1 fd 03             sar    $0x3,%rbp
  4005e5:       74 1f                   je     400606 <__libc_csu_init+0x56>
  4005e7:       31 db                   xor    %ebx,%ebx
  4005e9:       0f 1f 80 00 00 00 00    nopl   0x0(%rax)
  4005f0:       4c 89 fa                mov    %r15,%rdx
  4005f3:       4c 89 f6                mov    %r14,%rsi
  4005f6:       44 89 ef                mov    %r13d,%edi
  4005f9:       41 ff 14 dc             callq  *(%r12,%rbx,8)
  4005fd:       48 83 c3 01             add    $0x1,%rbx
  400601:       48 39 dd                cmp    %rbx,%rbp
  400604:       75 ea                   jne    4005f0 <__libc_csu_init+0x40>
  400606:       48 83 c4 08             add    $0x8,%rsp
  40060a:       5b                      pop    %rbx
  40060b:       5d                      pop    %rbp
  40060c:       41 5c                   pop    %r12
  40060e:       41 5d                   pop    %r13
  400610:       41 5e                   pop    %r14
  400612:       41 5f                   pop    %r15
  400614:       c3                      retq   

0000000000400615 <.annobin___libc_csu_fini.start>:
  400615:       66 66 2e 0f 1f 84 00    data16 nopw %cs:0x0(%rax,%rax,1)
  40061c:       00 00 00 00 

0000000000400620 <__libc_csu_fini>:
  400620:       f3 0f 1e fa             endbr64 
  400624:       c3                      retq   

Disassembly of section .fini:

0000000000400628 <_fini>:
  400628:       f3 0f 1e fa             endbr64 
  40062c:       48 83 ec 08             sub    $0x8,%rsp
  400630:       48 83 c4 08             add    $0x8,%rsp
  400634:       c3                      retq   
 */