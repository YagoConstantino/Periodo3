section .data
    msg db "%d", 0
    newline db 10, 0

section .bss
    result resb 10

section.text
    extern printf
    global _start

_start:
    mov EAX, 50
    mov EBX, 51

    add EAX, EBX

    sub EAX, 99

    ; ---- Chamada da função printf ----
    ; Empilha os argumentos na ordem reversa (de trás para frente)
    push eax            ; Empilha o valor de sub (EAX)
    push msg            ; Empilha o formato "%d"
    call printf         ; Chama a função printf
    add esp, 8          ; Limpa a pilha (2 argumentos x 4 bytes cada)   

    mov eax, 0
    ret