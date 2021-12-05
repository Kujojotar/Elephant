#include "print.h"
#include "init.h"
#include "memory.h"
#include "debug.h"
#include "thread.h"
#include "interrupt.h"
void k_thread_a(void* arg);
void k_thread_b(void* arg);

int main(void){
    put_str("I am kernel\n");
    init_all();
    mem_init();
    /*------------- chapter 8:test here ---------------------*/
    /*put_str("finish mem init\n");
    //void* addr = get_kernel_pages(3);
    //put_str("\n get_kernel_page start vaddr is:0x");put_int((int)addr);put_char('\n');
    */
    /*------------- chapter 9:test here --------------------*/
    thread_start("k_thread_a", 31, k_thread_a, "argA ");
    thread_start("k_thread_a", 8, k_thread_a, "argB ");
    intr_enable();
    while(1){
       put_str("Main ");
    }
    return 0;
}

void k_thread_a(void* arg){
    char* parm = arg;
    while(1){
        put_str(parm);
    }
}

void k_thread_b(void* arg){
    char* parm = arg;
    while(1){
        put_str(parm);
    }
}

