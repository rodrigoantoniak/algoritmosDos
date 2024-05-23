#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pila.h"

int iniciar(pila *p)
{
    if (p == NULL)
    {
        return 1;
    }
    p->cantidad = 0;
    p->valores = NULL;
    return 0;
}

int apilar(pila *p, int x)
{
    if (p == NULL)
    {
        return 1;
    }
    p->valores = (int *)realloc(
        p->valores,
        ++(p->cantidad) * sizeof(int)
    );
    p->valores[p->cantidad - 1] = x;
    return 0;
}

int *desapilar(pila *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (p->cantidad == 0)
    {
        return NULL;
    }
    int *retorno = (int *)malloc(sizeof(int));  
    *retorno = p->valores[--(p->cantidad)];
    if (p->cantidad)
    {
        p->valores = (int *)realloc(
            p->valores,
            p->cantidad * sizeof(int)
        );
    }
    else {
        free(p->valores);
        p->valores = NULL;
    }
    return retorno;
}

bool estaVacia(pila p)
{
    return (p.cantidad == 0);
}

void liberar(pila *p)
{
    if (p == NULL)
    {
        return;
    }
    free(p->valores);
    p->cantidad = 0;
}

char* cadena(pila p)
{
    if (p.cantidad == 0)
    {
        return NULL;
    }
    unsigned int n;
    char *numero = NULL;
    char *cadena = (char *)malloc(sizeof(char));
    *cadena = '\0';
    for (unsigned int i = p.cantidad-1; i > 0; --i)
    {
        n = 1 + p.valores[i] / 10;
        numero = (char *)malloc((n+3) * sizeof(char));
        // En snprintf, el tamaño máximo es excluyente
        snprintf(numero, (n+4) * sizeof(char), "%d < ", p.valores[i]);
        cadena = (char *)realloc(
            cadena,
            (strlen(cadena)+strlen(numero)) * sizeof(char)
        );
        strcat(cadena, numero);
        free(numero);
    }
    n = 1 + p.valores[0] / 10;
    numero = (char *)malloc(n * sizeof(char));
    // En snprintf, el tamaño máximo es excluyente
    snprintf(numero, (n+1) * sizeof(char), "%d", p.valores[0]);
    cadena = (char *)realloc(
        cadena,
        (strlen(cadena)+strlen(numero)) * sizeof(char)
    );
    strcat(cadena, numero);
    free(numero);
    return cadena;
}
