global increment
section .text

increment:
    ; Function begin
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]

    ; Function body
    inc eax

    ; Function end
    mov esp, ebp
    pop ebp
    ret
    