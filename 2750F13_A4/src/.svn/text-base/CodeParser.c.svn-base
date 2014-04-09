#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <libgen.h>
#include <ctype.h>
#include "common.h"
#include "arch.h"
#include "labelList.h"
#include "CodeParser.h"


/*This should probably return a struct for the runTest function
That means I return the hex value from bitwise function,
I count the instructions, I use the filename,
and I take care of begin and label*/

/*Send label too?
No, the label is used in future instructions...
So store the value, then that way we have a function that checks for it in the future.
The value is the count at which it was read.
So create a function that reads in labels, store in list, and return list.
Perhaps call this function before the while loop.
The returned list checks each field... FUCK!
*/

int ReadFile( char * fileName, char * pathTo)
{
	/*VARIABLES*/
	FILE *filePtr;
	
	lList * theList;
	lNode * tempFree = NULL;
	
	int wordType;
	unsigned int numFlip;
	unsigned int fOne;
	unsigned int fTwo;
	unsigned int labelValue;
	int numFields;
	int labelTrue;
	int iCount;
	int yy = 0;
	
	char c;
	char temp_aMode = ')';
	char aMode1 = ']';
	char aMode2 = '[';
	
	char * tempWord;
	char * tempOp;
	char * tempNum;
	
	numFields = 0;
	wordType = 0;
	numFlip = 0x0;
	labelTrue = 0;
	iCount = 0;
	temp_aMode = '$';
	//tempWord = malloc(sizeof(char)* 20);
	tempOp = NULL;
	tempNum = NULL;
	
	//tempNum = malloc(sizeof(char)*20);
	//tempOp = malloc(sizeof(char)*10);
	
	theList = createList();	
	returnLabels(fileName, theList);
	/*printList(theList);*/
	
	filePtr = NULL;
	filePtr = fopen(fileName,"r");
		
	if (filePtr == NULL)
 	{
			printf("Error opening file. \n");/*Makes sure file can open, if not there is some sort of error.*/
	}
	else
	{
		while((c = fgetc(filePtr)) != EOF)
		{
			/*printf("#%c#",c);*/
			/*EATING WHITE SPACE!!!
			Calls the whitespace function
			*/

			if(c == ' ' || c == '\t' || c == '\n')
			{
				c = eatWhiteSpace(c, filePtr);
			/*	printf("WhiteSpace: .%c.\n", c);	*/
			}

			/*ADRESS MODES
			Sets address mode to a temporary holder, 
			this allows for control of each address mode
			as to not get them mixed up.
			*/
			if(c == '@' || c == '<' || c == '#' || c == '$')
			{
				temp_aMode = c;
			/*	printf("Access? %c\n",temp_aMode);*/
			}
			
			/*EATING COMMENTS!!!
			Calls comment function
			*/
			if(c == '%')
			{
				c = eatComments(c, filePtr);
			/*	printf("Comments: -%c-\n", c);
			*/
			}
			
			
			/*ALPHA CASE
			Calls the checkAlpha function, 
			takes the returned string and checks the type via checkWord.
			THe returned int determines what type of string it is.
			*/
			
			//printf("After loop %d\n\n\n", iCount);
			if(isalpha(c) != 0)
			{
				/*printf("\nALPHA Case: *%c*\n", c);*/
				//tempWord = malloc(sizeof(char)* 20);
				tempWord = checkAlpha(c, filePtr);
				wordType = checkLabel(tempWord, theList);
				/*printf("C after checkAlpha: %c\n",c);
				printf("Alpha String: ~%s~ WordType: %d\n", tempWord, wordType);*/
			
				if (wordType > 0)
				{
					labelValue = wordType;
					
					/*removeColon = strlen(tempWord) -1;
					strncpy(tempLabel, tempWord, removeColon);*/
					/*printf("LABEL: %s.\n\n",tempLabel);*/
					labelTrue = 1;
				}
				else if(wordType == -1)
				{
					tempOp = malloc(sizeof(char)*strlen(tempWord)+1);
					strcpy(tempOp, tempWord);
				/*	printf("OPERATION: %s.\n\n", tempOp);*/
				}
				else if(wordType == -3)
				{
					/*printf("PARSE ERROR! NOT A VALID STRING!\n");*/
					exit(0);
					/*printf("!! %s !!\n\n", tempWord);*/
				}
				free(tempWord);
			}
			
			
			/*"-" CASE
			Sets a unsigned int (numFlip) to the max num value 4096 (or 0x1000)
			This is used to help with the negative numbers.
			if numFlip is != 0 then it takes the fields number value
			and makes it equal to numFlip - current number vale.
			*/
			if(c == '-')
			{
				numFlip = 0x1000;
			}
			
			/*DIGIT CASE
			Creates a string comprised of digits by calling checkNum
			*/
			if(isdigit(c) != 0)
			{
				/*printf("\nDIGIT CASE: #_%c_#\n",c);*/
				//someTemp = malloc(sizeof(char)*20);
				tempNum = checkNum(c, filePtr);
				//tempNum = someTemp;
				/*printf("Digit String: #_%s_#\n", tempNum);
				printf("C after DIGIT CASE: %c\n",c);
				*/
				//printf("called: %d\n", yy);
				yy++;
				//someFlag = 1;
			}
			
			/*"," CASE
			Takes the current value of tempNum and converts it to an unsigned int in base 16 and puts it in fOne
			if numFlip is != 0 then it takes fOne's value
			and makes it equal to numFlip - fOne.
			*/
			if(c == ',')
			{	
				if(tempNum == NULL && labelTrue == 1)
				{
					fOne = labelValue;
				}
				else
				{
					fOne = strtoul(tempNum, NULL, 10);
					free(tempNum);
					tempNum = NULL;	
				}
				if(numFlip != 0x0)
				{
					fOne = numFlip - fOne;
					numFlip = 0x0;
				}
				/*printf("Field 1: %d\n", fOne);*/
				/*Two numFields expected*/
				numFields = 2;
				/*Now we can conclude that aMode1 has been picked.*/
				aMode1 = temp_aMode;
				temp_aMode = '$';
				/*printf("aMode1 Set to: %c\n",aMode1);*/
			}
			
			/*E.O.I. CASE*/
			if(c == ';')
			{
				/*If: Takes the current value of tempNum and converts it to an unsigned int in base 16 and puts it in fOne
				if numFlip is != 0 then it takes fTwo's value
				and makes it equal to numFlip - fTwo
				Else: it does the same operation for except for fOne.*/
				
				
				if(numFields == 2)
				{
					if(tempNum == NULL && labelTrue == 1)
					{
						fTwo = labelValue;
					}
					else
					{
						fTwo = strtoul(tempNum, NULL, 10);	
						free(tempNum);
						tempNum = NULL;
					}
					if(numFlip != 0x0)
					{
						fTwo = numFlip - fTwo;
						numFlip = 0x0;
					}
				/*	printf("Field 2: %d\n\n\n", fTwo);*/
					
				}
				else
				{
					if(tempNum == NULL && labelTrue == 1)
					{
						fOne = labelValue;
					}
					else
					{
						fOne = strtoul(tempNum, NULL, 10);
						free(tempNum);
						tempNum = NULL;	
					}
					if(numFlip != 0x0)
					{
						fOne = numFlip - fOne;
						numFlip = 0x0;
					}
				/*	printf("Field 1: %d\n", fOne);*/
					fTwo = 0;
				}
				numFlip = 0x0;
				
				
				/*If: Checks the addressMode of aMode1 and if it already has a value, and number of fields == 2 
				then it sets the value of aMode2 to whatever temp_aMode may be.
				Else-If: aMode1 doesn't have a value, and number of fields == 2, then aMode1 = '$' and aMode2 = temp_aMode
				Else-If: number of fields != 2, then the ',' case hasn't occured and thus only aMode1 gets a value.
				*/
				if((aMode1 == '@' || aMode1 == '<' || aMode1 == '$' || aMode1 == '#') && (numFields == 2))
				{
					aMode2 = temp_aMode;
				}
				else if((aMode1 != '@' || aMode1 != '<' || aMode1 != '$' || aMode1 != '#') && (numFields == 2))
				{
					aMode2 = temp_aMode;
					aMode1 = '$';
				}
				else if(numFields != 2)
				{
					if(temp_aMode == '\0')
					{
						temp_aMode = '$';
					}
					aMode1 = temp_aMode;
					aMode2 = '#';
				}
				/*printf("aMode2 Set to: %c\n",aMode2);*/
				
				if(wordType == -2)
				{
					aMode1 = '#';
					aMode2 = '#';
				}
				
				/*printf("BeginValue: %u\nfTwo: %u\naMode1: %c\naMode2: %c\n", fOne, fTwo, aMode1, aMode2);*/
				
				/*Prints the Label, or Doesn't...*/
				/*if(labelTrue == 1 && wordType > 0)
				{
					printf("\n\n************************\n");
					printf("The OpCommand: %s\n", tempOp);
					printf("Field1: .%c. %d, Field2: .%c. %d\n", aMode1, fOne, aMode2, fTwo);
					printf("iCount: %d\n", iCount);
					printf("************************\n\n");
				}
				else if(labelTrue == 1)
				{
					printf("\n\n************************\n");
					printf("The OpCommand: %s\n", tempOp);
					printf("Field1: .%c. %d, Field2: .%c. %d\n", aMode1, fOne, aMode2, fTwo);
					printf("iCount: %d\n", iCount);
					printf("************************\n\n");
				}
				else if(labelTrue == 0 && wordType == -1)
				{
					printf("\n\n************************\n");
					printf("The OpCommand: %s\n", tempOp);
					printf("Field1: .%c. %d, Field2: .%c. %d\n", aMode1, fOne, aMode2, fTwo);
					printf("iCount: %d\n", iCount);
					printf("************************\n\n");
				}*/
				
				//printf("WTF before??\n\n");
				/*Makes sure the Operation has a value*/
				if(tempOp != NULL)
				{
					if(strcmp(tempOp, "JMP") == 0 || strcmp(tempOp, "JMN") == 0 || strcmp(tempOp, "JMZ") == 0)
					{
						if(aMode1 == '#')
						{
							printf("!ERROR!\n!WARNING!: First field cannot have an Immediate Addressing Mode!\n");
							exit(0);
						}
					}	
				}
				else
				{
					bitWiseOp("begin", aMode1, fOne, aMode2, fTwo, pathTo);
				}
				
				/*CALLING BITWISE OPERATION*/
				if((labelTrue == 0 || labelTrue == 1) && (wordType >= -1))
				{
					bitWiseOp(tempOp, aMode1, fOne, aMode2, fTwo, pathTo);	
					free(tempOp);
				}
				//printf("EXITS!!!?!?!\n\n");
			//	printf("%s, %c, %u, %c, %u\n", tempOp, aMode1, fOne, aMode2, fTwo);
				/*Clearing Values for next Instruction*/
				/*if(tempOp != NULL)
				{
					free(tempOp);	
				}*/
				aMode1 = '\0';
				aMode2 = '\0';
				temp_aMode = '\0';
				fOne = 0x0;
				fTwo = 0x0;	
				labelTrue = 0;
				labelValue = 0;	
				numFields = 0;
				iCount++;
				
				
			}/*End IF*/	
				
						
		}/*End While*/
		
		tempFree = theList->head->next;
		while(tempFree->next != NULL)
		{
			free(tempFree->string);
			tempFree = tempFree->next;
			free(tempFree->prev);
		}
		if(tempFree->next == NULL)
		{
			free(tempFree->string);
			free(tempFree);
		}
		free(theList->head->string);
		free(theList->head);
		free(theList);
		
		fclose(filePtr);
	}
	return 0;
}

/*COMMENTS:
Eats comments until it hits a new line character value.
Pre: a char, and a filePtr
Post: returns the last c value the filePtr was pointing to

*/
char eatComments(char c, FILE * filePtr)
{		
	
	while(c != '\n')
	{
		/*printf("C = --%c--\n", c);*/
		c = fgetc(filePtr);
	}
	if( c == '\n')
	{
		return c;
	}
	
	return c;
}

/*WHITESPACE:
Eats whitespace until it hits a non-whitespace value.
Pre: a char, and a filePtr
Post: returns the last c value the filePtr was pointing to
*/
char eatWhiteSpace (char c, FILE * filePtr)
{

	while (c == ' ' || c == '\t' || c == '\n')
	{
		/*printf("C = .%c.\n", c);*/
		c = fgetc(filePtr);
	}
	if(c != ' ')
	{
		return c;
	}
	return c;
}

/*ALPHA:
Takes the current c value in readFile(), 
and traverses through the file until it finds a non-alpha.
Returns a string to readFile().
Pre: a char, and a filePtr.
Post: returns a string full of alphas.
*/
char * checkAlpha(char c, FILE * filePtr)
{
	char * string;
	int i;
	i = 0;
	string = malloc(sizeof(char)*20);
	
	while(isalpha(c) != 0)
	{
	/*	printf("C = ~%c~\n", c);*/
		string[i] = c;
		i++;
		/*printf("I value: %d\n", i);*/
		c = fgetc(filePtr);
	}
	/*if(isdigit(c) != 0)
	{
		printf("Parse ERROR! No digits allowed in Labels or OpCommands!\n");
	}*/
	if(c == ':')
	{
		string[i] = c;
		string[i+1] = '\0';
	}
	else if (c == '@')
	{
		string[i] = c;
		string[i+1] = '\0';
	}
	else
	{
		string[i] = '\0';
	}
	ungetc(c,filePtr);
	return string;
}

/*WORD Check:
Takes a string and checks for an '@', ':', or if the string is an Operation Command
Pre: A char*
Post: Returns an int, either 0, 1, or -1.
*/
int checkWord (char * word)
{
	char c;
	c = word[strlen(word)-1];
	/*printf("C: .%c.\n",c);*/
	if(c == '@')
	{
		return 0;	
	}
	else if(c == ':')
	{
		return 1;
	} 
	else if (strlen(word) == 3)
	{
		return 2;
	}
	/*Not begin, label or OpCmd*/
	return -1;
}


int checkLabel (char * word, lList * theList)
{
	lNode*temp;	
	char c;
	
	temp = theList->head;
	c = word[strlen(word)-1];
	if(isalpha(word[strlen(word)-1]) == 0)
	{
		word[strlen(word)-1] = '\0';
	}

	/*printf("C: .%c.\n",c);*/
	while(temp != NULL)
	{
		if(strcasecmp(word,"begin") == 0)
		{
				return -2;
		}
		else if(strcmp(word,temp->string) == 0)
		{
			return temp->line;
		}
		temp = temp->next;
	}
	if (strlen(word) == 3)
	{
		return -1;
	}
	/*Not begin, label or OpCmd*/
	return -3;
}

/*DIGIT:
Takes the current c value in readFile(), 
and traverses through the file until it finds a non-digit.
Returns a string to the readFile().
Pre: a char and a filePtr
Post: Returns a string full of digits.
*/

char * checkNum(char c, FILE * filePtr)
{
	char * string;
	int i;
	i = 0;
	string = malloc(sizeof(char)*20);
	while(isdigit(c) != 0)
	{
		string[i] = c;
		/*printf("C = #_%c_#\n", c);*/
		i++;
		c = fgetc(filePtr);
	}
	string[i] = '\0';
	ungetc(c,filePtr);
	
	return (string);
	/*printf("C value before end of function: #_%c_#\n",c);*/
		
}

/*BIT WISE OPERATION:
Takes the a string, 2 chars and 2 unsigned ints (both ints are in base 16)
Converts the char* and 2 chars to there appropriate hex values, 
then creates a 32bit unsigned hex, which is then read out to stdout.
Pre: a char*, 2 chars, 2 unsigned ints in base 16.
Post: returns a int to confirm completion.

*/

int bitWiseOp(char *opCmd, char aMode1, unsigned int fOne, char aMode2, unsigned int fTwo, char * pathTo)
{
	//char ** iArray;
	char * iArray[] = {"DAT", "MOV", "ADD", "SUB", "MUL", "DIV", "MOD", "SWP" , "JMP", "JMZ", "JMN", "CMP", "SET", "CLR", "FRK", "NOP"};
	char codemonEx [8];
	
	unsigned int hexArray [16];
	
	unsigned int opHex;
	unsigned int a1Hex;
	unsigned int a2Hex;
	
	unsigned int iValue;
	unsigned int newValue;
	unsigned int clearOp;
	unsigned int set;
	
	
	int size;
	int i;
	int cut;
	
	FILE *filePtr;
	filePtr = NULL;
	i = 0;
	
	//printf("C before:pathTo = %s\n", pathTo);
	
	cut = strlen(pathTo) - 3;
	
	
	codemonEx[0] = pathTo[cut + 1];
	codemonEx[1] = pathTo[cut + 2];
	codemonEx[2] = pathTo[cut + 3];
	codemonEx[3] = pathTo[cut + 4];
	codemonEx[4] = pathTo[cut + 5];
	codemonEx[5] = pathTo[cut + 6];
	codemonEx[6] = pathTo[cut + 7];
	codemonEx[7] = pathTo[cut + 8];
	
	
	//printf("C: codemonEx: %s\n\n",codemonEx);
	
	//printf("C:pathTo[cut] = %c\n", pathTo[cut]);
	if(strcmp(codemonEx,"cm") == 0)
	{
		i = cut ;
		pathTo[i+1] = 'c';
		pathTo[i+2] = 'o';
		pathTo[i+3] = 'd';
		pathTo[i+4] = 'e';
		pathTo[i+5] = 'm';
		pathTo[i+6] = 'o';
		pathTo[i+7] = 'n';
		pathTo[i+8] = '\0';
		//printf("C:pathTo = %s\n", pathTo);
	}

	
	
	
	
	
	
/*	iArray = malloc(sizeof(char*)*16);
	

	
	while(size<16)
	{
		iArray[size] = malloc(sizeof(char)*4);
		size++;
	}
	size--;
	iArray[0] = "DAT";
	iArray[1] = "MOV";
	iArray[2] = "ADD";
	iArray[3] = "SUB";
	iArray[4] = "MUL";
	iArray[5] = "DIV";
	iArray[6] = "MOD";
	iArray[7] = "SWP";
	iArray[8] = "JMP";
	iArray[9] = "JMZ";
	iArray[10] = "JMN"; 
	iArray[11] = "CMP";
	iArray[12] = "SET";
	iArray[13] = "CLR";
	iArray[14] = "FRK";
	iArray[15] = "NOP";*/
	
	//printf("Rick James bitch!!!!\n\n\n\n\n");
	
	hexArray[0] = 0x0;
	hexArray[1] = 0x1;
	hexArray[2] = 0x2;
	hexArray[3] = 0x3;
	hexArray[4] = 0x4;
	hexArray[5] = 0x5;
	hexArray[6] = 0x6;
	hexArray[7] = 0x7;
	hexArray[8] = 0x8;
	hexArray[9] = 0x9;
	hexArray[10] = 0xA;
	hexArray[11] = 0xB;
	hexArray[12] = 0xC;
	hexArray[13] = 0xD;
	hexArray[14] = 0xE;
	hexArray[15] = 0xF;
	
		
	if(aMode1 == '#')
	{
		a1Hex = 0x0;
	}
	else if(aMode1 == '$')
	{
		a1Hex = 0x1;
	}
	else if(aMode1 == '@')
	{
		a1Hex = 0x2;
	}
	else if(aMode1 == '<')
	{
		a1Hex = 0x3;
	}
	
	if(aMode2 == '#')
	{
		a2Hex = 0x0;
	}
	else if(aMode2 == '$')
	{
		a2Hex = 0x1;
	}
	else if(aMode2 == '@')
	{
		a2Hex = 0x2;
	}
	else if(aMode2 == '<')
	{
		a2Hex = 0x3;
	}
	//printf("Rick James bitch!!!!\n\n\n\n\n");
	
	size = 0;
	while(size<16)
	{
		//printf("iArray[%d]: %s\n\n", size, iArray[size]);
		//fflush(stdout);
		if(strncmp(opCmd,iArray[size], 3) == 0)
		{
			opHex = hexArray[size];
			/*printf("OpCmdString: %s OpCmdHex: %X\n", iArray[size] ,opHex);*/
		}
		else if(strcmp(opCmd,"begin") == 0)
		{
			
			newValue = fOne;
			//printf("fopen w+\n\n");
			filePtr = fopen(pathTo,"w+");
			if (filePtr == NULL)
 			{
				printf("Error opening file. \n");/*Makes sure file can open, if not there is some sort of error.*/
			}
			else
			{
				fflush(filePtr);
				fwrite(&newValue, sizeof(unsigned int), 1, filePtr);
				fclose(filePtr);
			}
			return 0;
		}
		size++;
	}
	
	
	size = 15;
	/*while(size>0)
	{
		printf("WTWFTFTW\n\n\n");
		free(iArray[size]);
		size--;
	}
	free(iArray);
	*/
	
	
	/* # = 0x0, $ = 0x1, @ = 0x2, < = 0x3*/
	/*
	printf("a1Hex: %X. fOneHEX: %X.\n", a1Hex, fOne);
	printf("a2Hex: %X. fTwoHEX: %X.\n\n", a2Hex, fTwo);
	*/
	/*Initialize Values*/
	iValue = 0x00000000;
	newValue = iValue;
	set = opHex;
	clearOp = 0x00000000;
	
	/*First Byte*/
	set = set << 28;
	newValue = newValue | set;
	/*printf("Value after first Byte: %X\n", newValue);*/
	
	/*Second Byte: Address Mode 1*/
	iValue = newValue;
	set = a1Hex;
	
	set = set << 26;
	newValue = newValue | set;
	/*printf("Value after Address Mode 1: %X\n", newValue);*/
	
	/*Second Byte - Fifth Byte: Field Num 1*/
	iValue = newValue;
	set = fOne;
	
	set = set << 14;
	
	newValue = newValue | set;
	/*printf("Value after Field Num 1: %X\n", newValue);*/
	
	/*Fifth Byte: Address Mode 2*/
	iValue = newValue;
	set = a2Hex;
	
	set = set << 12;
	newValue = newValue | set;
	/*printf("Value after Address Mode 2: %X\n", newValue);*/
	
	/*Sixth Byte - Eighth Byte: Filed Num 2*/
	iValue = newValue;
	set = fTwo;
	
	/*printf("Set: %X\n",set);*/
	newValue = newValue | set;
	/*printf("Final Value: %X\n\n", newValue);*/
	
	/*printf("The fWrite: ");*/
	//printf("fopen a\n\n");
	filePtr = fopen(pathTo,"a+");
	fseek(filePtr,0,SEEK_END);
	if (filePtr == NULL)
 	{
		printf("Error opening file. \n");/*Makes sure file can open, if not there is some sort of error.*/
	}
	else
	{
		fflush(filePtr);
		fwrite(&newValue, sizeof(unsigned int), 1, filePtr);
		fclose(filePtr);
	}
	/*printf(".\n");*/
	
	return 0;
}

int returnLabels(char * fileName, lList * theList)
{ 
	
	FILE * filePtr;
	
	int labelOr;
	int remove;
	int lineCount;
	int labelTrue;
		
	char t;
	char * label;
	char * begin;
	char * tempLabel;
	
	lineCount = 0;
	
//	tempLabel = malloc(sizeof(char)*20);
		
	labelOr = 0;
	labelTrue = 0;
	
	
	filePtr = NULL;
	filePtr = fopen(fileName,"r");
	
	//printf("fileName in returnLabels: %s\n\n", fileName);
	
	if (filePtr == NULL)
 	{
			printf("Error opening file. \n");/*Makes sure file can open, if not there is some sort of error.*/
	}
	else
	{
		while((t = fgetc(filePtr)) != EOF)
		{
			
			/*printf("#%c#",c);*/
			/*EATING WHITE SPACE!!!
			Calls the whitespace function
			*/
			if(t == ' ' || t == '\t' || t == '\n')
			{
				t = eatWhiteSpace(t, filePtr);
			/*	printf("WhiteSpace: .%c.\n", c);	*/
			}
			
			/*EATING COMMENTS!!!
			Calls comment function
			*/
			if(t == '%')
			{
				t = eatComments(t, filePtr);
			/*	printf("Comments: -%c-\n", c);
			*/
			}
			
			/*Find Label*/
			if(isalpha(t) != 0)
			{
				tempLabel = checkAlpha(t, filePtr);
				labelOr = checkWord(tempLabel);
				remove = strlen(tempLabel) -1;
				
				if(labelOr == 0)
				{
					//begin = malloc(sizeof(char)*strlen(tempLabel)-1);
					//strncpy(begin, tempLabel, strlen(tempLabel)-1);
					begin = tempLabel;
					begin[remove] = '\0';
					//printf("BEGIN: %s.\n\n",begin);
				}
				else if (labelOr == 1)
				{
					//label = malloc(sizeof(char)*removeColon);
					//strncpy(label, tempLabel, removeColon);
					//printf("LABEL: %s.\n\n",tempLabel);
					label = tempLabel;
					label[remove] = '\0';
					labelTrue = 1;
				}
				else if (labelOr > 1 && labelTrue == 1)
				{
					//tempLabel[0] = '~';
				}
			}
			
			if(t == ';')
			{				
				if(labelOr == 0)
				{
					addNode(theList, begin, lineCount);
					//free(begin);
				}
				else if(labelTrue == 1)
				{
					addNode(theList, label, lineCount);
					free(label);
				}
				lineCount++;				
				labelTrue = -1;
				free(tempLabel);
				tempLabel = NULL;
			}
		}
	
		//printf("FilePTR: %p \nfilename: %s\n\n\n\n\n\n", filePtr, fileName);
		fflush(stdout);
		fclose(filePtr);	
	}
	return 0;
}



unsigned int codemonPvp(char * filename1, unsigned int pvp)
{
	FILE * filePtr;
	
	unsigned int begin;
	unsigned int instruction;
	unsigned int i;
	unsigned int returnVal = 1337;
	int p = 0;
	int y = 0;
	char * ptr;
	
	struct Codemon_pkg * codemon1 = NULL;
	codemon1 = malloc(sizeof(struct Codemon_pkg));
	
	begin = 0;
	instruction = 0;
	
	i = 0;
	filePtr = NULL;

	filePtr = fopen(filename1, "r");
	
	y = strlen(filename1);
	
	while(y > 0)
	{
		printf("~%c~\n",filename1[y]);
		if(filename1[y] == '/')
		{
		//	printf("%s\n", filename1);
		//	printf("Current +1 %c\n", filename1[y+1]);
			ptr = &filename1[y+1];
		//	printf("PTR: %s\n", ptr);
			break;
		}
		else
		{
			printf("%d\n",y);
			y--;
		}
	}
	
	strcpy(codemon1->name,ptr);
	//strcpy(codemon1->name,filename1);
	
	if(fread(&begin,sizeof(unsigned int),1,filePtr) == 1)
	{
		codemon1->begin	= begin;
	}

	while(fread(&instruction,sizeof(unsigned int),1,filePtr) == 1)
	{
		codemon1->program [i] = instruction;
		/*printf("~Instruction[%d]: .%X.\n",i, instruction);*/
		i++;		
	}
	
	codemon1->lines = i;
	fclose(filePtr);	
	filePtr = NULL;
	
	/*Print 1*/
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Codemon Struct:\n\n");
	printf("Name: .%s.\n",codemon1->name);
	printf("Program: \n");
	while(p < codemon1->lines)
	{
		printf("Instruction[%d]: .%X.\n", p, codemon1->program[p]);
		p++;
	}
	printf("Lines: .%u.\n", codemon1->lines);
	printf("Begin: .%d.\n", codemon1->begin);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	
	p = 0;
	
	
	returnVal = runPvP(codemon1, pvp);
	
	free(codemon1);
	
	return returnVal;
}





int ReadCodemon(char * filename1, char * filename2, char * limit)
{
	FILE * filePtr;
		
	unsigned int begin;
	unsigned int instruction;
	unsigned int i;
	unsigned int newLimit = 0;
	unsigned int returnVal = 1337;
	char * ptr;
	char * ptr2;
	int p = 0;
	int y = 0;
	int yy = 0;
	
	struct Codemon_pkg * codemon1 = NULL;
	struct Codemon_pkg * codemon2 = NULL;
	codemon1 = malloc(sizeof(struct Codemon_pkg));
	//nameChange = malloc(sizeof(char)*120);
	
	begin = 0;
	instruction = 0;
	
	if(limit == NULL)
	{
		/*printf("Filename2: %s\n", filename2);*/
		newLimit = strtoul(filename2, NULL, 10);
	}
	
	i = 0;
	filePtr = NULL;
	
	y = strlen(filename1);
	
	while(y > 0)
	{
		//printf("~%c~\n",filename1[y]);
		if(filename1[y] == '/')
		{
		//	printf("%s\n", filename1);
		//	printf("Current +1 %c\n", filename1[y+1]);
			ptr = &filename1[y+1];
		//	printf("PTR: %s\n", ptr);
			break;
		}
		else
		{
			//printf("%d\n",y);
			y--;
		}
	}
	
	
	printf("After this...\n");
	fflush(stdout);
	
	filePtr = fopen(filename1, "r");
	
	strcpy(codemon1->name,ptr);
	//printf("Codename: %s\n",codemon1->name);
	//strcpy(codemon1->name,filename1);
	
	if(fread(&begin,sizeof(unsigned int),1,filePtr) == 1)
	{
		codemon1->begin	= begin;
	}

	while(fread(&instruction,sizeof(unsigned int),1,filePtr) == 1)
	{
		codemon1->program [i] = instruction;
		/*printf("~Instruction[%d]: .%X.\n",i, instruction);*/
		i++;		
	}
	
	codemon1->lines = i;
	fclose(filePtr);	
	filePtr = NULL;
	
	if(limit != NULL)
	{	
		codemon2 = malloc(sizeof(struct Codemon_pkg));
		newLimit = strtoul(limit, NULL, 10);
		
		i = 0;
		instruction = 0x0;
		begin = 0x0;
		
		filePtr = fopen(filename2, "r");
		
		
		yy = strlen(filename2);
	
		while(yy > 0)
		{
			//printf("~%c~\n",filename2[yy]);
			if(filename2[yy] == '/')
			{
			//	printf("%s\n", filename1);
			//	printf("Current +1 %c\n", filename1[y+1]);
				ptr2 = &filename2[yy+1];
			//	printf("PTR: %s\n", ptr);
				break;
			}
			else
			{
				//printf("%d\n",yy);
				yy--;
			}
		}
		
		strcpy(codemon2->name,ptr2);
		//strcpy(codemon2->name,filename2);
		
		if(fread(&begin,sizeof(unsigned int),1,filePtr) == 1)
		{
			codemon2->begin	= begin;
		}
	
		while(fread(&instruction,sizeof(unsigned int),1,filePtr) == 1)
		{
			codemon2->program [i] = instruction;
			/*printf("~Instruction: %X\n", codemon2->program[i]);*/
			i++;		
		}
		codemon2->lines = i;
		fclose(filePtr);
		filePtr = NULL;
	}
	
	
	/*Print 1*/
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Codemon Struct:\n\n");
	printf("Name: .%s.\n",codemon1->name);
	printf("Program: \n");
	while(p < codemon1->lines)
	{
		printf("Instruction[%d]: .%X.\n", p, codemon1->program[p]);
		p++;
	}
	printf("Lines: .%u.\n", codemon1->lines);
	printf("Begin: .%d.\n", codemon1->begin);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	
	p = 0;
	
	/*Print 2*/
	if(codemon2 != NULL)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Codemon Struct:\n\n");
		printf("Name: .%s.\n",codemon2->name);
		printf("Program: \n");
		while(p < codemon2->lines)
		{
			printf("Instruction[%d]: .%X.\n", p, codemon2->program[p]);
			p++;
		}
		printf("Lines: .%u.\n", codemon2->lines);
		printf("Begin: .%X.\n", codemon2->begin);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
	else
	{
		printf("codemon2 is NULL\n\n");
	}
	
	returnVal = runTest(codemon1, codemon2, newLimit);

	//printf("Return: %u\n", returnVal);
	free(codemon1);
	free(codemon2);
	
	
	return returnVal;
	
}

int testServer()
{ 
	struct Codemon_pkg * test;
	unsigned int returnVal = 1337;
	test = malloc(sizeof(struct Codemon_pkg));
	
	
	strcpy(test->name, "new");
	test->program[0] = 0x00000000;
	test->lines = 1;
	test->begin = 0;
	
	returnVal = runTest(test, NULL, 2);
	
	return 0;
}

