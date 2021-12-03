#ifndef __KERNEL_DEBUG_H
#define __KERNEL_DEBUG_H
void panic_spin(char* filename,int line,const char* func);

//_VA_ARGS_ represent variable params number,and ... represent va_args
#define PANIC() panic_spin(__FILE__, __LINE__, __func__)

#ifdef NDBUG
    #define ASSERT(CONDITION) ((void)0)
#else
    #define ASSERT(CONDITION) \
    if(CONDITION){}else{ \
        PANIC(); \
    }
#endif /*__NDEBUG */

#endif /*__KERNEL_DEBUG_H*/
