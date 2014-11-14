#CC=clang
CC=/usr/local/Cellar/gcc/4.9.1/bin/gcc-4.9

LIBS=-O3 -I/usr/local/include/glib-2.0/ -I/usr/local/lib/glib-2.0/include -L/usr/local/lib -lglib-2.0
CFLAGS=-g

 FILES=$(wildcard *.c)
# FILES=Q1.c Q5.c
# FILES=Q2.c

default: compile

compile:
	for file in $(FILES); 															   \
	do 																				   \
		output=`echo $$file | cut -d'.' -f1`".out"; 								   \
		$(CC) $(CFLAGS) $(LIBS) $$file -o $$output; 								   \
	done

clean:
	rm *.c *.out
