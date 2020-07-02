
#\author: Serradj Elhadi

CFLAGS = -O2 -Wall -g
CC = gcc
LDLIBS = -lX11

vpath %.o obj/
vpath %.c src/
vpath %.h include/
vpath main /bin


all : main

main : main.o  StrEcc.o pile.o
	$(CC) $(CFLAGS) -o $@ obj/main.o obj/StrEcc.o obj/pile.o $(LDLIBS)
	mv $@ bin/.
	
matrice.o : matrice.h color.h pile.h

pile.o : pile.h

color.o : color.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -Iinclude $(LDLIBS)
	mv $@ obj/

#gendoc : 
#	 doxygen -g 
	
exedoc :
	 doxygen Doxyfile

clean :
	rm -rf obj/*.o bin/* main

	

