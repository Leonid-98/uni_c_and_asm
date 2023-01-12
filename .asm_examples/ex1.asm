global main
extern printf

section .data
hello: db 'My string: %d', 0x0A, 0

section .text

main:
    mov eax, 17
    push eax

    push hello

    call printf

    pop ebx
    pop ebx
    ; or add esp, 8 (4 byte each)

    mov eax, 0
    ret



