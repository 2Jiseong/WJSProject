INCLUDE = /home/ljs/Emb_sw/project/WJSProject/include
OBJECT = insert.o
OUTPUT = libmyfuncs.a
.PHONY = clean

$(OUTPUT) : $(OBJECT)
	ar rv $(OUTPUT) $(OBJECT)
insert.o : insert.c
	gcc -c -I$(INCLUDE) insert.c -o insert.o

clean:
	rm *.o $(OUTPUT)
