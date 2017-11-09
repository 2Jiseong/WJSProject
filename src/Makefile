LIB = /home/ljs/Emb_sw/project/WJSProject/lib
INCLUDE = /home/ljs/Emb_sw/project/WJSProject/include
.PHONY = clean

main : main.o
	gcc -o main -L $(LIB) main.o -lmyfuncs
main.o : main.c
	gcc -g -c -I $(INCLUDE) main.c -o main.o
clean:
	rm *.o main
