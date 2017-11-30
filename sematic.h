#ifndef SEMANTIC_H
#define SEMANTIC_H

int variblesTemp;
void definirIdentificador(char *nuevoIdentificador);
int invocarIdentificador(char *nuevoIdentificador);
char *hacerOperacion(char *operador, char *exp1, char *exp2);
void writeIdentificador(char *identificador);
void reedIdentificador(char *identificador);
void asignarIdentificador(char *identificador, char *valor);

#endif
