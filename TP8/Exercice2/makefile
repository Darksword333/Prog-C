CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
LDLIBS=-lm
RM=rm -f
OBJ=prog.o image.o matrice.o
EXE=prog
# Pour produire le fichier exécutable
$(EXE):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
# Pour produire les fichiers objets
prog.o:tp8ex2.c image.h
	$(CC) $(CFLAGS) -c tp8ex2.c -o prog.o
image.o:image.c image.h
	$(CC) $(CFLAGS) -c image.c
matrice.o:matrice.c matrice.h
	$(CC) $(CFLAGS) -c matrice.c
# Pour effacer les objets et les exécutables
clean:
	$(RM) $(OBJ) $(EXE)