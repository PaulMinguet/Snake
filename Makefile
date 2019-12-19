### VARIABLES ###
 
CC = gcc
CFLAGS = -Wall \
         -ansi \
         -pedantic

EXE = snake
OFILES = menu.o \
		 jeu.o \
         main.o \
         serpent.o \
         chargement.o 
 
### BUT PAR DEFAUT ###
 
but : ${EXE}
 
### REGLES ESSENTIELLES ###
 
jeu.o : jeu.h serpent.h

menu.o : menu.h
 
main.o : jeu.h menu.h jeu.h

chargement.o : jeu.h

serpent.o : serpent.h
 
${EXE} : ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES} -lgraph
 
### REGLES OPTIONNELLES ###
 
clean :
	-rm -f ${OFILES}
 
mrproper : clean but

run : snake
	./snake

 
### BUTS FACTICES ###
 
.PHONY : but clean mrproper
 
### FIN ###