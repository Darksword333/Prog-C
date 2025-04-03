CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
LDLIBS=-lm
RM=rm -f
OBJ=prog.o image.o matrice.o ti.o
EXE=prog
# Pour produire le fichier exécutable
$(EXE):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
# Pour produire les fichiers objets
prog.o:tp9ex.c ti.h
	$(CC) $(CFLAGS) -c tp9ex.c -o prog.o
ti.o:ti.c ti.h
	$(CC) $(CFLAGS) -c ti.c
image.o:image.c image.h
	$(CC) $(CFLAGS) -c image.c
matrice.o:matrice.c matrice.h
	$(CC) $(CFLAGS) -c matrice.c
# Pour effacer les objets et les exécutables
clean:
	$(RM) $(OBJ) $(EXE)