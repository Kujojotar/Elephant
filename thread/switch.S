[bits 32]
section .text
global switch_to
switch_to:
    ;------------- preserve context of the tmp thread ----------------;
    ;ret address
    push esi
    push edi
    push ebx
    push ebp
    mov eax, [esp+20]
    mov [eax], esp 

    ;------------- return to the state of next thread ----------------;
    mov eax, [esp+24]
    mov esp, [eax]
    
    pop ebp
    pop ebx
    pop edi
    pop esi
    ret
