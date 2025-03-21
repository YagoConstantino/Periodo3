section .data
    msg db 'Ola Meu Belo e Gentil Mundo Cruel!!!', 0xA;
    len equ $ - msg;

section .text
    global _start ;

_start:
    ; Syscall: write(fd,buf,count)
    mov eax, 4 ;
    mov ebx, 1;
    mov ecx, msg ;
    mov edx, len;
    int 0x80 ;

    ; Syscall: exit(status)
    mov eax, 1;
    xor ebx, ebx ;
    int 0x80;        