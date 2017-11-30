extern int semanticErrs;
int variblesTemp = 0;

void definirIdentificador(char *nuevoIdentificador)
{
    if(estaDefinido(nuevoIdentificador) != NULL)
    {
        char str[60];
        sprintf("Error Semantico: variable con multiples definiciones: %s\n", nuevoIdentificador);
        yyerror(str);
        semanticErrs++;
    }
    else
    {
        printf("Declare %s,Integer\n", nuevoIdentificador);
        push(identificadoresDefinidos, nuevoIdentificador);
    }
}

int invocarIdentificador(char *nuevoIdentificador)
{
    struct elem aux = estaDefinido(nuevoIdentificador);
    if(aux == NULL)
    {
        char str[60];
        sprintf("Error Semantico: variable no definida: %s\n", nuevoIdentificador);
        yyerror(str);
        semanticErrs++;
        return NULL;
    }
    return aux;
}

char *hacerOperacion(char *operador, char *exp1, char *exp2)
{
    char *aux = malloc(10);
    variblesTemp++;
    sprintf(aux, "Temp#%d", variblesTemp);
    definirIdentificador(aux);
    printf("%s %s,%s,%s\n", operador, exp1, exp2, aux);
    return aux;
}

void writeIdentificador(char *identificador)
{
    if(invocarIdentificador(identificador) != NULL) printf("Write %s,Integer\n", identificador);
}

void reedIdentificador(char *identificador)
{
    if(invocarIdentificador(identificador) != NULL) printf("Reed %s,Integer\n", identificador);
}

void asignarIdentificador(char *identificador, char *valor)
{
    if(invocarIdentificador(identificador) != NULL) printf("Store %s,%s\n", valor, identificador);
}
