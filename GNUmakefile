CC=gcc

ASM=nasm
ASM+= -f elf -o

CC+= -I ./lib -I . -fno-builtin
CC+= -c -o
print.o:
	$(ASM) obj/print.o lib/print.S

kernel.o:
	$(ASM) obj/kernel.o kernel.S	

timer.o:
	$(CC) obj/timer.o timer.c

init.o:
	$(CC) obj/init.o init.c

main.o:
	$(CC) obj/main.o main.c

interrupt.o:
	$(CC) obj/interrupt.o interrupt.c

create: print.o kernel.o init.o main.o interrupt.o timer.o
	ld -Ttext 0xc0001500 -e main -o obj/kernel.bin obj/main.o obj/init.o obj/interrupt.o obj/print.o obj/kernel.o obj/timer.o

write: 
	dd if=/home/niejian/Desktop/kernel/obj/kernel.bin of=/home/niejian/Desktop/bochs/hd60M.img bs=512 seek=9 count=200 conv=notrunc  

clean:
	@rm obj/*.o 
	@rm obj/*.bin
