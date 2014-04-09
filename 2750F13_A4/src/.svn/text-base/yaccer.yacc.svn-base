%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "labelList.h"
	#include "CodeParser.h"
	
	extern int yylineno;
	extern FILE * yyin;
	extern char* labelarray [50];
	extern int linearray[50];
	
	extern char * saveFilePath;
	
	int yylex(void);
	//int yyparse(void);
	
	int errorFlag = 0;
	
	int LabelCheck(char *, int);
	int checkValid(char *, char);
	int normalize(int);
/*	int main()
	{
		yyparse();
		return 0;
	}
*/		
	void yyerror(const char* str)
	{
		fprintf(stderr, "%s on line: %d\n", str, yylineno);
	}
	
	
	
%}

%union 
{
	int ival;
	char cval;
	char * sval;
}

%token COMMA SEMI COLON PLUS MINUS MUL DIV MOD EQUAL LB RB
%token <cval> AT
%token <cval> HASH
%token <cval> DOLLAR
%token <cval> ARROW
%token <sval> BGIN
%token <sval> LABEL
%token <sval> OPCODE
%token <ival> NUMBER

%type <cval> aMode
%type <ival> term
%type <ival> factor
%type <ival> expression

%%

prog:
	 start instructs				{printf("Charlie\n\n"); fflush(stdout);}
   ;


start:
	 BGIN aMode NUMBER SEMI						{printf("%s%c %d;\n", $1, $2, $3);fflush(stdout); bitWiseOp($1,$2,$3,'$',0,saveFilePath);}
	 ;

instructs:
		 instructs instruct
	   | instruct
	   ;

instruct:																	    /*String | String Char Int Char Int*/
		 LABEL COLON OPCODE aMode expression COMMA aMode expression SEMI		{$5 = normalize($5); $8 = normalize($8); if(strcmp("JMP",$3) == 0 || strcmp("JMN",$3) == 0 || strcmp("JMZ",$3) == 0){if($4 == '#'){printf("ERROR! No '#' allowed! %d\n\n",yylineno);}} bitWiseOp($3, $4, $5, $7, $8, saveFilePath); printf("%s: %s %c%d, %c%d;\n", $1, $3, $4, $5, $7, $8); }
	   | LABEL COLON OPCODE aMode expression COMMA expression SEMI				{$5 = normalize($5); $7 = normalize($7); if(strcmp("JMP",$3) == 0 || strcmp("JMN",$3) == 0 || strcmp("JMZ",$3) == 0){if($4 == '#'){printf("ERROR! No '#' allowed! %d\n\n",yylineno);}} bitWiseOp($3, $4, $5, '$', $7, saveFilePath); printf("%s: %s %c%d, %d;\n", $1, $3, $4, $5, $7);}
	   | LABEL COLON OPCODE expression COMMA aMode expression SEMI				{$4 = normalize($4); $7 = normalize($7); bitWiseOp($3, '$', $4, $6, $7, saveFilePath); printf("%s: %s %d, %c%d;\n", $1, $3, $4, $6, $7);}
	   | LABEL COLON OPCODE aMode expression SEMI								{$5 = normalize($5); if(checkValid($3,$4) == -1) {printf("Error w/ numFields!\n");}else if(checkValid($3,$4) == -2){printf("ERROR! No '#' allowed! %d\n\n",yylineno);} bitWiseOp($3, $4, $5, '$', 0, saveFilePath); printf("%s: %s %c%d;\n", $1, $3, $4, $5); }
	   | LABEL COLON OPCODE expression COMMA expression SEMI	   				{$4 = normalize($4); $6 = normalize($6); bitWiseOp($3, '$', $4, '$', $6, saveFilePath); printf("%s: %s %d, %d;\n", $1, $3, $4, $6); }
	   | LABEL COLON OPCODE expression SEMI										{$4 = normalize($4); if(checkValid($3,'X') == -1){printf("Error w/ numFields!\n");}else if(checkValid($3,'X') == -2){printf("ERROR! No '#' allowed! %d\n\n",yylineno);} bitWiseOp($3, '$', $4, '$', 0, saveFilePath); printf("%s: %s %d;\n", $1, $3, $4); }
	   | LABEL COLON OPCODE SEMI												{if(checkValid($3,'X') == -1){printf("Error w/ numFields!\n");} bitWiseOp($3, '$', 0, '$', 0, saveFilePath); printf("%s: %s;\n", $1, $3);}
	   | OPCODE aMode expression COMMA aMode expression SEMI					{$3 = normalize($3); $6 = normalize($6); if(strcmp("JMP",$1) == 0 ||strcmp("JMN",$1) == 0 || strcmp("JMZ",$1) == 0){if($2 == '#'){printf("ERROR! No '#' allowed! %d\n\n",yylineno);}} bitWiseOp($1, $2, $3, $5, $6, saveFilePath); printf("%s %c%d, %c%d;\n", $1, $2, $3, $5, $6); }
	   | OPCODE aMode expression COMMA expression SEMI							{$3 = normalize($3); $5 = normalize($5); if(strcmp("JMP",$1) == 0 || strcmp("JMN",$1) == 0 || strcmp("JMZ",$1) == 0){if($2 == '#'){printf("ERROR! No '#' allowed! %d\n\n",yylineno);}} bitWiseOp($1, $2, $3, '$', $5, saveFilePath); printf("%s %c%d, %d;\n", $1, $2, $3, $5); }
	   | OPCODE expression COMMA aMode expression SEMI							{$2 = normalize($2); $5 = normalize($5); bitWiseOp($1, '$', $2, $4, $5, saveFilePath); printf("%s %d, %c%d;\n", $1, $2, $4, $5);}
	   | OPCODE expression COMMA expression SEMI	   							{$2 = normalize($2); $4 = normalize($4); bitWiseOp($1, '$', $2, '$', $4, saveFilePath); printf("%s %d, %d;\n", $1, $2, $4); }
	   | OPCODE aMode expression SEMI											{$3 = normalize($3); if(checkValid($1,$2) == -1){printf("Error w/ numFields!\n");}else if(checkValid($1,$2) == -2){printf("ERROR! No '#' allowed! %d\n\n",yylineno);} bitWiseOp($1, $2, $3, '$', 0, saveFilePath); printf("%s %c%d;\n", $1, $2, $3); }
	   | OPCODE expression SEMI													{if(checkValid($1,'X') == -1){printf("Error w/ numFields!\n");} $2 = normalize($2); bitWiseOp($1, '$', $2, '$', 0, saveFilePath); printf("%s %d;\n", $1, $2);}
	   | OPCODE SEMI															{if(checkValid($1,'X') == -1){printf("Error w/ numFields!\n");} bitWiseOp($1, '$', 0, '$', 0, saveFilePath); printf("%s;\n", $1); }
	   ;

expression:
		 expression PLUS term						{$$ = ($1 + $3);}
	   | expression MINUS term						{$$ = ($1 - $3);}
	   | term 										{$$ = $1;}
	   ;
term: 
	 term MUL factor								{$$ = $1 * $3;}
   | term DIV factor								{$$ = $1 / $3;}
   | term MOD factor								{$$ = $1 % $3;}
   | factor											{$$ = $1;}
   ;
   
factor:
	 NUMBER											{$$ = $1;}
   | MINUS NUMBER									{$$ = $2 * -1;}
   | LABEL											{$$ = LabelCheck($1, 1);}
   | MINUS LABEL									{$$ = LabelCheck($2, -1);}
   | LB expression RB								{$$ = $2;}
   | MINUS LB expression RB							{$$ = $3 * -1;}
   ;
		 
aMode:
	 AT											{$$ = '@';}
   | HASH										{$$ = '#';}
   | DOLLAR										{$$ = '$';}
   | ARROW										{$$ = '<';}
   ;



%%

int normalize(int num)
{
	if(num >= 0 && num < 4096)
	{
		printf("In bounds %d\n", num);
		return num;
	}
	else if(num < 0)
	{
		printf("Less than %d\n", num);
		while(num < 0)
		{
			num = num + 4096;
		}
		printf("RESULT Less: %d\n\n", num);
		return num;
	}
	else if(num > 0)
	{
		printf("Greater than %d\n", num);
		while(num > 4096)
		{
			num = num - 4096;
		}
		printf("RESULT Greater: %d\n\n", num);
		return num;
	}
	
	printf("UMMMM %d\n", num);
	return -1;
}

int checkValid(char * opcmd, char aM)
{
	
	if(strcmp("SWP",opcmd) == 0 || strcmp("CMP",opcmd) == 0 || strcmp("MOD",opcmd) == 0 || strcmp("DIV",opcmd) == 0 || strcmp("MUL",opcmd) == 0  || strcmp("SUB",opcmd) == 0 || strcmp("ADD",opcmd) == 0 || strcmp("MOV",opcmd) == 0 )
	{
		return -1;
	}
	else if((strcmp("JMN",opcmd) == 0 || strcmp("JMZ",opcmd) == 0) && (aM == '#'))
	{
		return -2;
	}
	
	
	return 1;
}


int LabelCheck(char * label, int pn)
{
	//NEED TO DO NEGATIVE LABEL TOO!!
	int count = 0;
	int value = 0;
	/*int x = 0;
	for(x = 0; x<50; x++)
	{
		printf("%d\n",linearray[x]);
	}*/
	
	while(count < 50)
	{
		//printf("Current Label: %s\n", labelarray[count]);
		if(strcmp(label,labelarray[count]) == 0)
		{
			//printf("Count: %d\n",count);
			value = linearray[count];
			value = value * pn;
			//printf("Value: %d\n", value);
			if(value == 0)
			{
				return -7777;
			}
			return value;
		}
		else
		{
			count++;
		}
	}
	return 1;
}





