CC=gcc
FLAGS=-Wall	-g



all:	connections
		


#dynamic
connections:	main.o libmylib.so
			$(CC) $(FLAGS)	-o connections main.o ./libmylib.so
		
#creating dynamic lib .so
libmylib.so:	my_mat.o
				$(CC)	-shared	-o	libmylib.so	my_mat.o	

main.o:	main.c my_mat.h
			$(CC)	$(FLAGS) -c main.c

my_mat.o:	my_mat.c my_mat.h 
		$(CC)	$(FLAGS) -c my_mat.c




.PHONY:	clean

clean:	
	rm -f	*.o	connections	*.a	*.so