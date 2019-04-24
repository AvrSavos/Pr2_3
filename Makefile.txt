all: second

second: source.o entity.o 
	gcc source.o entity.o -o second

source.o: Source.c
	gcc -c Source.c

entity.o: Entity.c
	gcc -c Entity.c
	
clean:
	rm -rf *.o second