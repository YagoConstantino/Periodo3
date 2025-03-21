section .note.GNU-stack


section .data
    num1 DW 3           ; Define num1 como 3 (32 bits)
    num2 DW 6           ; Define num2 como 6 (32 bits)
    res DD 0            ; Espaço para armazenar o resultado

section .text
    global main

main:
    ; Carregar valores em EAX e EBX
    mov EAX, [num1]     ; Move o valor de num1 para EAX
    mov EBX, [num2]     ; Move o valor de num2 para EBX
    add EAX, EBX        ; Soma EAX + EBX

    ; Armazena o resultado em 'res'
    mov [res], EAX     

    ; Finaliza o programa
    mov EAX, 0
    ret
