;Uso de GPT
section .data                    ; Segmento de dados
    msg db "Resultado: ", 0      ; Mensagem inicial
    len equ $ - msg              ; Calcula o tamanho da mensagem
    buffer db "0000000000", 0    ; Buffer para armazenar o número convertido

section .bss                     ; Segmento não inicializado
    num resb 10                  ; Reserva espaço para armazenar o número

section .text                    ; Segmento de código
    global _start                ; Ponto de entrada do programa

_start:
    ; 1. Soma os números
    mov eax, 7                   ; Primeiro número (EAX = 7)
    mov ebx, 5                   ; Segundo número (EBX = 5)
    add eax, ebx                 ; Soma (EAX = 7 + 5 = 12)

    ; 2. Mostrar "Resultado: "
    mov eax, 4                   ; syscall: write
    mov ebx, 1                   ; saída padrão (stdout)
    mov ecx, msg                 ; Endereço da mensagem
    mov edx, len                 ; Tamanho da mensagem
    int 0x80                     ; Chamar o kernel

    ; 3. Converter número (EAX) para string (decimal)
    mov ecx, 10                  ; Base decimal
    mov edi, buffer + 9          ; Última posição do buffer
    mov byte [edi], 0            ; Finalizador de string (NULL)

convert_loop:
    xor edx, edx                 ; Limpar EDX (necessário para a divisão)
    div ecx                      ; EAX ÷ 10 → EAX = quociente, EDX = resto
    add dl, '0'                  ; Converter dígito para ASCII
    dec edi                      ; Voltar uma posição no buffer
    mov [edi], dl                ; Armazenar o caractere
    test eax, eax                ; EAX == 0? (verifica se terminou)
    jnz convert_loop             ; Se não, repetir o loop

    ; 4. Escrever o número convertido na tela
    mov eax, 4                   ; syscall: write
    mov ebx, 1                   ; saída padrão (stdout)
    mov ecx, edi                 ; Endereço do número convertido
    mov edx, buffer + 10         ; Calcula o tamanho do número
    sub edx, ecx                 ; Comprimento do número
    int 0x80                     ; Chamar o kernel

    ; 5. Finalizar o programa (sys_exit)
    mov eax, 1                   ; syscall: exit
    xor ebx, ebx                 ; Código de saída 0 (sucesso)
    int 0x80                     ; Chamar o kernel
