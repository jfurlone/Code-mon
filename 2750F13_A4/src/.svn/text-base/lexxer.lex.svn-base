%{

#include "y.tab.h"

int count = 0;
char* labelarray [50];
int linearray [50];

%}


%option yylineno

opcommands 		(DAT|MOV|ADD|SUB|MUL|DIV|MOD|SWP|JMP|JMZ|JMN|CMP|SET|CLR|FRK|NOP)
comment_eater	!(.)*
whitespace		[\t\n ]
numbers			[0-9]+
labels			[a-z]+


%%

{whitespace}	{}
{comment_eater}	{}

"@"				{return AT;}
"#"				{return HASH;}
"$"				{return DOLLAR;}
"<"				{return ARROW;}
";"				{return SEMI;}
":"				{return COLON;}
","				{return COMMA;}
\+				{return PLUS;}
\-				{return MINUS;}
\*				{return MUL;}
"/"				{return DIV;}
"%"				{return MOD;}
"="				{return EQUAL;}
"("				{return LB;}
")"				{return RB;}

"begin"			{yylval.sval = strdup(yytext); 
				return BGIN;}
				
{opcommands}	{yylval.sval = strdup(yytext);
				return OPCODE;}
				
{labels}		{yylval.sval = strdup(yytext);
				labelarray[count] = strdup(yytext);
				linearray[count] = yylineno-1;
				count++;
				return LABEL;}
				
{numbers}		{yylval.ival = atoi(yytext);
				return NUMBER;}


%%






