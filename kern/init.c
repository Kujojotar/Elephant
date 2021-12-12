#include "init.h"
#include "print.h"
#include "interrupt.h"
#include "timer.h"
#include "memory.h"
#include "thread.h"
#include "console.h"
#include "keymap.h"
#include "tss.h"
#include "syscall-init.h"

void init_all(){
    put_str("init_all\n");
    idt_init();
    mem_init();
    timer_init();
    thread_init();
    console_init();
    keyboard_init();
    tss_init();
    syscall_init();
}
