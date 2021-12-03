#include "print.h"
#include "init.h"
#include "memory.h"
#include "debug.h"
int main(void){
    put_str("I am kernel\n");
    init_all();
    mem_init();
    put_str("finish mem init\n");
    void* addr = get_kernel_pages(3);
    put_str("\n get_kernel_page start vaddr is:0x");put_int((int)addr);put_char('\n');
    while(1);
    return 0;
}
