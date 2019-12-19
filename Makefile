### VARIABLES ###
 
CC = gcc
CFLAGS = -Wall \
         -ansi 
         

EXE = snake
OFILES = ./jeu/jeu.o \
		 ./jeu/serpent.o \
         ./main.o \
         ./menu/menu.o \
         ./menu/chargement.o 
 
### BUT PAR DEFAUT ###
 
but : ${EXE}
 
### REGLES ESSENTIELLES ###
 
jeu.o : ./jeu/jeu.h ./jeu/serpent.h

menu.o : ./menu/menu.h
 
main.o : ./jeu/jeu.h ./menu/menu.h ./jeu/serpent.h

chargement.o : ./jeu/jeu.h

serpent.o : ./jeu/serpent.h
 
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