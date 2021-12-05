CC=gcc

ASM=nasm
ASM+= -f elf -o

CC+= -Wall -I lib/ -I kern/ -I device/ -I thread/ -I . -fno-builtin
CC+= -c -o
bitmap.o:
	$(CC) obj/bitmap.o ./kern/bitmap.c

memory.o:
	$(CC) obj/memory.o ./kern/memory.c

switch.o:
	$(ASM) obj/switch.o ./thread/switch.S

string.o:
	$(CC) obj/string.o ./lib/string.c

print.o:
	$(ASM) obj/print.o ./lib/print.S

kernel.o:
	$(ASM) obj/kernel.o ./kern/kernel.S	

timer.o:
	$(CC) obj/timer.o ./device/timer.c

thread.o:
	$(CC) obj/thread.o ./thread/thread.c

list.o:
	$(CC) obj/list.o ./lib/list.c

init.o:
	$(CC) obj/init.o ./kern/init.c

main.o:
	$(CC) obj/main.o ./kern/main.c

interrupt.o:
	$(CC) obj/interrupt.o ./kern/interrupt.c

debug.o:
	$(CC)  obj/debug.o kern/debug.c

create: string.o print.o kernel.o init.o main.o interrupt.o timer.o debug.o bitmap.o memory.o thread.o list.o switch.o
	ld -Ttext 0xc0001500 -e main obj/main.o obj/print.o obj/init.o obj/bitmap.o obj/string.o obj/interrupt.o obj/timer.o obj/kernel.o obj/list.o obj/switch.o obj/memory.o obj/thread.o obj/debug.o -o obj/kernel.bin -Map obj/kernel.map
write: 
	dd if=/home/niejian/Desktop/kernel/obj/kernel.bin of=/home/niejian/Desktop/bochs/hd60M.img bs=512 seek=9 count=200 conv=notrunc  

clean:
	@rm obj/*.o 
	@rm obj/*.bin
