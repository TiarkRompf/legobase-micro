# CC=clang
# CC=/usr/local/Cellar/gcc/4.9.1/bin/gcc-4.9
CC=/usr/bin/gcc-4.9

LIBS=-O3 `pkg-config --cflags --libs glib-2.0` -L/usr/lib
CFLAGS=-g

 FILES=$(wildcard *.c)
# FILES=Q1.c Q5.c
# FILES=Q1.c Q2.c Q3.c

default: compile

compile:
	for file in $(FILES); 															   \
	do 																				   \
		output=`echo $$file | cut -d'.' -f1`".out"; 								   \
		$(CC) $(CFLAGS) $(LIBS) $$file -o $$output; 								   \
	done

clean:
	rm *.c *.out
