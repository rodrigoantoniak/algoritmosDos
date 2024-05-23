#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cola.h"

int iniciar(cola *c)
{
    if (c == NULL)
    {
        return 1;
    }
    c->cantidad = 0;
    c->valores = NULL;
    return 0;
}

int enfilar(cola *c, int x)
{
    if (c == NULL)
    {
        return 1;
    }
    c->valores = (int *)realloc(
        c->valores,
        ++(c->cantidad) * sizeof(int)
    );
    memmove(c->valores + 1, c->valores, (c->cantidad-1) * sizeof(int));
    c->valores[0] = x;
    return 0;
}

int *desfilar(cola *c)
{
    if (c == NULL)
    {
        return NULL;
    }
    if (c->cantidad == 0)
    {
        return NULL;
    }
    int *retorno = (int *)malloc(sizeof(int));  
    *retorno = c->valores[--(c->cantidad)];
    if (c->cantidad)
    {
        c->valores = (int *)realloc(
            c->valores,
            c->cantidad * sizeof(int)
        );
    }
    else {
        free(c->valores);
        c->valores = NULL;
    }
    return retorno;
}

bool estaVacia(cola c)
{
    return (c.cantidad == 0);
}

void liberar(cola *c)
{
    if (c == NULL)
    {
        return;
    }
    free(c->valores);
    c->cantidad = 0;
}

char* cadena(cola c)
{
    if (c.cantidad == 0)
    {
        return NULL;
    }
    unsigned int n;
    char *numero = NULL;
    char *cadena = (char *)malloc(sizeof(char));
    *cadena = '\0';
    for (unsigned int i = c.cantidad-1; i > 0; --i)
    {
        n = 1 + c.valores[i] / 10;
        numero = (char *)malloc((n+3) * sizeof(char));
        // En snprintf, el tamaño máximo es excluyente
        snprintf(numero, (n+4) * sizeof(char), "%d > ", c.valores[i]);
        cadena = (char *)realloc(
            cadena,
            (strlen(cadena)+strlen(numero)) * sizeof(char)
        );
        strcat(cadena, numero);
        free(numero);
    }
    n = 1 + c.valores[0] / 10;
    numero = (char *)malloc(n * sizeof(char));
    // En snprintf, el tamaño máximo es excluyente
    snprintf(numero, (n+1) * sizeof(char), "%d", c.valores[0]);
    cadena = (char *)realloc(
        cadena,
        (strlen(cadena)+strlen(numero)) * sizeof(char)
    );
    strcat(cadena, numero);
    free(numero);
    return cadena;
}
