CFLAGS = -c -ansi -Wall -pedantic

mystring_ptrs_demo: mystring_ptrs.o main.o
	gcc main.o mystring_ptrs.o -o mystring_ptrs_demo

mystring_ars_demo: mystring_ars.o main.o
	gcc main.o mystring_ars.o -o mystring_ars_demo

main.o: main.c mystring.h
	gcc $(CFLAGS) main.c

mystring_ptrs.o: mystring_ptrs.c mystring.h
	gcc $(CFLAGS) mystring_ptrs.c

mystring_ars.o: mystring_ars.c mystring.h
	gcc $(CFLAGS) mystring_ars.c

clean:
	rm -f *.o mystring_ptrs_demo mystring_ars_demo