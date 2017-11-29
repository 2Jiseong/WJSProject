INCLUDE = /home/ljs/Emb_sw/project/WJSProject/include
OBJECT = insert.o add.o show.o del.o test.o help.o
OUTPUT = libmyfuncs.a
.PHONY = clean

$(OUTPUT) : $(OBJECT)
	ar rv $(OUTPUT) $(OBJECT)
insert.o : insert.c
	gcc -c -I$(INCLUDE) insert.c -o insert.o

add.o : add.c
	gcc -c -I$(INCLUDE) add.c -o add.o

del.o : del.c
	gcc -c -I$(INCLUDE) del.c -o del.o

show.o : show.c
	gcc -c -I$(INCLUDE) show.c -o show.o

test.o : test.c
	gcc -c -I$(INCLUDE) test.c -o test.o

help.o : help.c
	gcc -c -I$(INCLUDE) help.c -o help.o

clean:
	rm *.o $(OUTPUT)
