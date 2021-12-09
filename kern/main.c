#include "print.h"
#include "init.h"
#include "memory.h"
#include "debug.h"
#include "thread.h"
#include "interrupt.h"
#include "console.h"
#include "process.h"
#include "list.h"

void k_thread_a(void* arg);
void k_thread_b(void* arg);
void u_prog_a();
void u_prog_b();
int test_var_a = 0,test_var_b = 0;

int main(void){
    put_str("I am kernel\n");
    init_all();
    /*------------- chapter 8:test here ---------------------*/
    /*put_str("finish mem init\n");
    //void* addr = get_kernel_pages(3);
    //put_str("\n get_kernel_page start vaddr is:0x");put_int((int)addr);put_char('\n');
    */
    /*------------- chapter 9:test here --------------------*/
    console_put_int(list_len(get_ready_list()));
    console_put_char('\n');
    thread_start("k_thread_a", 31, k_thread_a, "argA ");
    thread_start("k_thread_b", 8, k_thread_b, "argB ");
    process_execute(u_prog_a, "user_prog_a");
    process_execute(u_prog_b, "user_prog_b");
    intr_enable();
    //console_put_int(list_len(get_ready_list()));
    //console_put_char('\n');
    while(1){
       //console_put_str("Main ");
    }
    return 0;
}

void k_thread_a(void* arg){
    char* parm = arg;
    while(1){
        console_put_str("v_a:0x");
        console_put_int(test_var_a);
        //console_put_str(parm);
    }
}

void k_thread_b(void* arg){
    char* parm = arg;
    while(1){
        console_put_str("v_b:0x");
        console_put_int(test_var_b);
        //console_put_str(parm);
    }
}

void u_prog_a(){
    while(1){
        test_var_a++;
    }
}

void u_prog_b(){
    while(1){
        test_var_b++;
    }
}
