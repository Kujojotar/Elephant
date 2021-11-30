#include "print.h"
int main(void){
    put_str("I am kernel");
    put_char('\n');
    put_int(0);
    put_char('\n');
    put_int(9);
    put_char('\n');
    put_int(0x00021a3f);
    put_char('\n');
    put_int(0xffee3219);
    while(1);
    return 0;
}
