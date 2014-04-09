#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "common.h"
#include "arch.h"



int ReadFile(char *, char *);

char eatWhiteSpace (char c, FILE * filePtr);

char eatComments(char c, FILE * filePtr);

char * checkAlpha (char c, FILE * filePtr);

char * checkNum (char c, FILE * filePtr);

int checkWord (char * word);

int checkLabel (char * word, lList * theList);

int bitWiseOp(char *, char, unsigned int, char, unsigned int, char *);

int returnLabels(char * fileName, lList * theList);

unsigned int codemonPvp(char * filename1, unsigned int pvp);

int ReadCodemon (char *, char *, char *);

int testServer();