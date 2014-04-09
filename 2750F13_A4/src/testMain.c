#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "arch.h"
#include "labelList.h"
#include "CodeParser.h"


int main (int argc, char * argv[])
{
		char one [120] = "poopfart/Dwarf_Imp_dF.cm";
		char two [120] = "Dwarf_Imp_dF.cm";
		
		char cd1 [120] = "Dwarf_Imp_dF.codemon";
		char cd2 [120] = "SQL-rtle.codemon";
		
		ReadCodemon(one,"3", NULL);
		
		//testServer();
		//ReadCodemon(cd1, cd2, "3");
	return 0;
}


/*

char * one;
char * two;

one = NULL;
two = NULL;

one = malloc(sizeof(char)* 200);
two = malloc(sizeof(char)* 200);

strcpy(one, "SQL-rtle.cm");
strcpy(two, "SQL-rtle.cm");

*/