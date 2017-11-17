INCLUDE = /home/ljs/Emb_sw/project/WJSProject/include
OBJECT = insert.o add.o
OUTPUT = libmyfuncs.a
.PHONY = clean

$(OUTPUT) : $(OBJECT)
	ar rv $(OUTPUT) $(OBJECT)
insert.o : insert.c
	gcc -c -I$(INCLUDE) insert.c -o insert.o

add.o : add.c
	gcc -c -I$(INCLUDE) word.c -o word.o

clean:
	rm *.o $(OUTPUT)
