project: main.o matrixBuilder.o getMax.o getAlign.o
	 gcc -o project main.o matrixBuilder.o getMax.o getAlign.o

main.o:	main.c matrixBuilder.h getAlign.h
	gcc -c main.c

matrixBuilder.o: matrixBuilder.c getMax.h
		 gcc -c matrixBuilder.c

getMax.o: getMax.c 
	  gcc -c getMax.c

getAlign.o: getAlign.c matrixBuilder.h getMax.h
	   gcc -c getAlign.c

clean:
	rm -f *.o project
