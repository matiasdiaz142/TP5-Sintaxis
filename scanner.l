%{
#include <stdio.h>
#include "parser.h"
#include <string.h>
char str[60];
%}
numero [0-9]
letra [a-zA-Z]
otros [[:punct:]]{-}[(),;:=*/+-]
%option header-file="scanner.h"
%option outfile="scanner.c"
%option nounput
%option noinput
%option yylineno
%%
"//".*$           ;
"programa"            return PROGRAMA;
"fin"             return FIN;
"leer"             return LEER;
"escribir"            return ESCRIBIR;
"variables"             return VARIABLES;
"codigo"            return CODIGO;
"definir"             return DEFINIR;
"("             return '(';
")"             return ')';
","             return ',';
";"             return ';';
":="          return ASIGNACION;
"*"            return '*';
"/"            return '/';
"+"           return '+';
"-"            return '-';
{letra}+({letra}|{numero})*           {yylval = strdup(yytext); return IDENTIFICADOR;}
{numero}+            {yylval = strdup(yytext); return CONSTANTE;}
{letra}+({letra}|{numero})*{otros}+({numero}|{otros}|{letra})*            {yylexerrs++; sprintf(str, "Error lexico: identificador invalido: %s", yytext);yyerror(str);}
{numero}+{letra}+({numero}|{letra})*            {yylexerrs++;sprintf(str, "Error lexico: constante con sufijo invalido: %s", yytext);yyerror(str);}
{otros}+      {yylexerrs++;sprintf(str, "Error lexico: cadena desconocida: %s", yytext);yyerror(str);}
.|[[:space:]]    			;
%%
