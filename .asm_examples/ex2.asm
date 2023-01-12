global main
extern printf

section .data
hello: db 'My string: %d', 0x0A, 0

section .text

main:
    mov ecx, 10


    loop:
        push ecx ; save ecx, because printf will affect that value

        push hello
        call printf
        add esp, 4 ; compensate push of the printf function

        pop ecx ; pop ecx back
        dec ecx
        jne loop ; loop compared to the ecx register
    

    mov eax, 0
    ret



