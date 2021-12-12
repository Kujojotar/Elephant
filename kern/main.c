#include "print.h"
#include "init.h"
#include "memory.h"
#include "debug.h"
#include "thread.h"
#include "interrupt.h"
#include "console.h"
#include "process.h"
#include "list.h"
#include "syscall.h"
#include "stdio.h"

void k_thread_a(void* arg);
void k_thread_b(void* arg);
void u_prog_a();
void u_prog_b();
//int test_var_a = 0,test_var_b = 0;
int prog_a_pid = 0, prog_b_pid = 0;

int main(void){
    put_str("I am kernel\n");
    init_all();
    /*------------- chapter 8:test here ---------------------*/
    /*put_str("finish mem init\n");
    //void* addr = get_kernel_pages(3);
    //put_str("\n get_kernel_page start vaddr is:0x");put_int((int)addr);put_char('\n');
    */
    /*------------- chapter 9:test here --------------------*/
    intr_enable();
    process_execute(u_prog_a, "user_prog_a");
    process_execute(u_prog_b, "user_prog_b");
    thread_start("k_thread_a", 31, k_thread_a, "argA ");
    thread_start("k_thread_b", 31, k_thread_b, "argB ");
    while(1){
       //console_put_str("Main ");
    }
    return 0;
}

void k_thread_a(void* arg){
    char* parm = arg;
    void* addr1 = sys_malloc(256);
    void* addr2 = sys_malloc(255);
    void* addr3 = sys_malloc(254);
    /*console_put_str(" thread_a malloc addr:0x");
    console_put_int((int)addr1);
    console_put_char(',');
    console_put_int((int)addr2);
    console_put_char(',');
    console_put_int((int)addr3);
    console_put_char('\n');
    */
    printf(" thread_a malloc addr:0x%x,0x%x,0x%x\n", (int)addr1, (int)addr2, (int)addr3);
   
    int cpu_delay = 100000;
    while(cpu_delay-- > 0);
    sys_free(addr1);
    sys_free(addr2);
    sys_free(addr3);
    while(1){
        //console_put_str("v_a:0x");
        //console_put_int(test_var_a);
        //console_put_str(parm);
    }
}

void k_thread_b(void* arg){
    char* parm = arg;
    void* addr1 = sys_malloc(256);
    void* addr2 = sys_malloc(255);
    void* addr3 = sys_malloc(254);
/*
    console_put_str(" thread_b malloc addr:0x");
    console_put_int((int)addr1);
    console_put_char(',');
    console_put_int((int)addr2);
    console_put_char(',');
    console_put_int((int)addr3);
    console_put_char('\n');
*/
    printf(" thread_b malloc addr:0x%x,0x%x,0x%x\n", (int)addr1, (int)addr2, (int)addr3);

    int cpu_delay = 100000;
    while(cpu_delay-- > 0);
    sys_free(addr1);
    sys_free(addr2);
    sys_free(addr3);

    while(1){
        //console_put_str("v_b:0x");
        //console_put_int(test_var_b);
        //console_put_str(parm);
    }
}

void u_prog_a(){
    void* addr1 = malloc(256);
    void* addr2 = malloc(255);
    void* addr3 = malloc(254);
    printf(" prog_a malloc addr:0x%x,0x%x,0x%x\n", (int)addr1, (int)addr2, (int)addr3);

    int cpu_delay = 100000;
    while(cpu_delay-- > 0);
    free(addr1);
    free(addr2);
    free(addr3);
    while(1){    
//    test_var_a++;
    }
}

void u_prog_b(){
    void* addr1 = malloc(256);
    void* addr2 = malloc(255);
    void* addr3 = malloc(254);
    printf(" prog_b malloc addr:0x%x,0x%x,0x%x\n", (int)addr1, (int)addr2, (int)addr3);

    int cpu_delay = 100000;
    while(cpu_delay-- > 0);
    free(addr1);
    free(addr2);
    free(addr3);
    while(1){
    //    test_var_b++;
    }
}
