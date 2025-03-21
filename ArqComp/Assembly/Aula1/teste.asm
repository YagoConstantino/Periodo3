%include "io.inc"
; Não funciona pq essa biblioteca io.inc nao esta instalada
section .data
    num1 DD 30
    num2 DD 50
    num3 DD 60
    soma DD 00
    sub  DD 00

section .text
    global _start

_start:
    mov eax, [num1]
    mov ebx, [num2]
    mov ecx, [num3]

    add eax, ebx
    mov [soma], eax    

    sub eax, ecx
    mov [sub], eax

    PRINT_UDEC 4,[soma]
    NEWLINE
    PRINT_UDEC 4,[sub]

    mov eax , 0
    ret