/*
TP5 - 2017
Trabajo Practico Nº 4
Grupo 09
Integrantes:
1.Álvarez, Pérez Mariano - 160.190-8
2.Diaz, Matias - 157.243-0
3.Postigo, Nicolás - 155.692-7
4.Reggiardo, Juan José - 147.915-5
*/
#include "scanner.h"
#include "parser.h"
int yylexerrs = 0;
int yynerrs = 0;
int semanticErrs = 0;
int main() {
	switch( yyparse() ){
	case 0:
		puts("Compilacion terminada con exito");
		printf("Errores sintacticos: %d - Errores lexicos: %d - Errores semanticos: %d\n", yynerrs, yylexerrs, semanticErrs);
		return 0;
	case 1:
		printf("Errores de compilacion\n");
		printf("Errores sintacticos: %d - Errores lexicos: %d - Errores semanticos: %d\n", yynerrs, yylexerrs, semanticErrs);
		return 1;
	case 2:
		puts("Memoria insuficiente"); return 2;
	}
	return 0;
}
/* Informa la ocurrencia de un error. */
void yyerror(const char *s){
	printf("linea #%d: %s\n", yylineno, s);
	return;
}
