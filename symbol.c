struct elem
{
    char *nombre;
    struct elem *siguiente;
};

struct elem *identificadoresDefinidos = NULL;

struct elem *estaDefinido(char *nuevoIdentificador)
{
    struct elem *aux = identificadoresDefinidos;
    while(identificadoresDefinidos != NULL)
    {
        if(strcmp(aux->nombre, nuevoIdentificador))
        {
            //Esta definido
            return aux;
        }
        aux = aux->siguiente;
    }
    //No esta definido
    return NULL;
}

void push(elem *pila, char *identificador)
{
    elem aux = new elem();
    aux.nombre = identificador;
    aux.sgte = pila;
    pila = &aux;
}
