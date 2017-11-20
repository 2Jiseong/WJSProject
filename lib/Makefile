INCLUDE = /home/ljs/Emb_sw/project/WJSProject/include
OBJECT = insert.o add.o show.o
OUTPUT = libmyfuncs.a
.PHONY = clean

$(OUTPUT) : $(OBJECT)
	ar rv $(OUTPUT) $(OBJECT)
insert.o : insert.c
	gcc -c -I$(INCLUDE) insert.c -o insert.o

add.o : add.c
	gcc -c -I$(INCLUDE) add.c -o add.o

show.o : show.c
	gcc -c -I$(INCLUDE) show.c -o show.o

clean:
	rm *.o $(OUTPUT)
