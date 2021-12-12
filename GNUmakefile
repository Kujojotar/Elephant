CC=gcc

ASM=nasm
ASM+= -f elf -o

CC+= -Wall -I lib/ -I kern/ -I userprog/ -I device/ -I thread/ -I . -fno-builtin
CC+= -c -o
bitmap.o:
	$(CC) obj/bitmap.o ./kern/bitmap.c
tss.o:
	$(CC) obj/tss.o ./userprog/tss.c
memory.o:
	$(CC) obj/memory.o ./kern/memory.c

switch.o:
	$(ASM) obj/switch.o ./thread/switch.S

keyboard.o:
	$(CC) obj/keyboard.o ./device/keyboard.c

string.o:
	$(CC) obj/string.o ./lib/string.c

print.o:
	$(ASM) obj/print.o ./lib/print.S

kernel.o:
	$(ASM) obj/kernel.o ./kern/kernel.S	
sync.o:
	$(CC) obj/sync.o thread/sync.c
console.o:
	$(CC) obj/console.o device/console.c

ioqueue.o:
	$(CC) obj/ioqueue.o device/ioqueue.c

timer.o:
	$(CC) obj/timer.o ./device/timer.c

process.o:
	$(CC) obj/process.o ./userprog/process.c
thread.o:
	$(CC) obj/thread.o ./thread/thread.c

list.o:
	$(CC) obj/list.o ./lib/list.c

init.o:
	$(CC) obj/init.o ./kern/init.c

syscall.o:
	$(CC) obj/syscall.o ./lib/syscall.c

syscall-init.o:
	$(CC) obj/syscall-init.o ./userprog/syscall-init.c

stdio.o:
	$(CC) obj/stdio.o ./lib/stdio.c

main.o:
	$(CC) obj/main.o ./kern/main.c

interrupt.o:
	$(CC) obj/interrupt.o ./kern/interrupt.c

debug.o:
	$(CC)  obj/debug.o kern/debug.c

create: string.o print.o kernel.o init.o main.o interrupt.o timer.o debug.o bitmap.o memory.o thread.o list.o switch.o console.o sync.o tss.o keyboard.o ioqueue.o process.o syscall.o syscall-init.o stdio.o
	ld -Ttext 0xc0001500 -e main obj/main.o obj/init.o obj/interrupt.o obj/timer.o obj/kernel.o obj/print.o obj/debug.o obj/memory.o obj/bitmap.o obj/string.o obj/thread.o obj/list.o obj/switch.o obj/console.o obj/sync.o obj/keyboard.o obj/ioqueue.o obj/tss.o obj/process.o obj/syscall.o obj/syscall-init.o obj/stdio.o -o obj/kernel.bin -Map obj/kernel.map
write: 
	dd if=/home/niejian/Desktop/kernel/obj/kernel.bin of=/home/niejian/Desktop/bochs/hd60M.img bs=512 seek=9 count=200 conv=notrunc  

clean:
	@rm obj/*.o 
	@rm obj/*.bin
