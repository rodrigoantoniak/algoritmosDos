#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

int agregar(lista *l, int x)
{
    if (l == NULL)
    {
        return -1;
    }
    if (*l != NULL)
    {
        struct nodo *aux = *l;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = (struct nodo *)malloc(sizeof(struct nodo));
        aux->siguiente->valor = x;
        aux->siguiente->siguiente = NULL;
    }
    else
    {
        *l = (struct nodo *)malloc(sizeof(struct nodo));
        (*l)->valor = x;
        (*l)->siguiente = NULL;
    }
    return 0;
}

int insertar(lista *l, int x, unsigned int n)
{
    if (l == NULL)
    {
        return -1;
    }
    struct nodo *aux = *l;
    unsigned int i = 0;
    struct nodo *ante = NULL;
    while ((aux != NULL) && (i < n))
    {
        ante = aux;
        aux = aux->siguiente;
        ++i;
    }
    if (i < n)
    {
        return 1;
    }
    struct nodo *nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevo->valor = x;
    nuevo->siguiente = aux;
    if (ante != NULL)
    {
        ante->siguiente = nuevo;
    }
    else
    {
        *l = nuevo;
    }
    return 0;
}

int eliminar(lista *l, unsigned int n)
{
    if (l == NULL)
    {
        return -1;
    }
    struct nodo *aux = *l;
    if (n == 0)
    {
        if (aux == NULL)
        {
            return 1;
        }
        *l = aux->siguiente;
        free(aux);
        return 0;
    }
    unsigned int i = 0;
    struct nodo *ante = NULL;
    while ((aux->siguiente != NULL) && (i <= n))
    {
        ante = aux;
        aux = aux->siguiente;
        ++i;
    }
    if (i <= n)
    {
        return 1;
    }
    ante->siguiente = aux->siguiente;
    free(aux);
    return 0;
}

resultado buscar(lista l, int x)
{
    if (l == NULL)
    {
        return NULL;
    }
    resultado retorno = (resultado)malloc(
        sizeof(struct coincidencias)
    );
    retorno->lugares = NULL;
    retorno->cantidad = 0;
    struct nodo *aux = l;
    unsigned int i = 0;
    while (aux != NULL)
    {
        if (aux->valor == x)
        {
            retorno->lugares = (unsigned int *)realloc(
                retorno->lugares,
                ++(retorno->cantidad) * sizeof(unsigned int)
            );
            retorno->lugares[retorno->cantidad - 1] = i;
        }
        ++i;
        aux = aux->siguiente;
    }
    return retorno;
}

bool estaVacia(lista l)
{
    return (l == NULL);
}

void liberar(lista *l)
{
    if (l == NULL)
    {
        return;
    }
    struct nodo *aux = *l;
    while (aux != NULL)
    {
        *l = aux->siguiente;
        free(aux);
        aux = *l;
    }
}

char* cadena(lista l)
{
    if (l == NULL)
    {
        return NULL;
    }
    struct nodo *aux = l;
    unsigned int n;
    char *numero = NULL;
    char *cadena = (char *)malloc(sizeof(char));
    *cadena = '\0';
    while (aux != NULL)
    {
        n = 1 + (aux->valor) / 10;
        numero = (char *)malloc((n+4) * sizeof(char));
        // En snprintf, el tamaño máximo es excluyente
        snprintf(numero, (n+5) * sizeof(char), "%d -> ", aux->valor);
        cadena = (char *)realloc(
            cadena,
            (strlen(cadena)+strlen(numero)) * sizeof(char)
        );
        strcat(cadena, numero);
        free(numero);
        aux = aux->siguiente;
    }
    cadena = (char *)realloc(
        cadena,
        (strlen(cadena)+4) * sizeof(char)
    );
    strcat(cadena, "NULL");
    return cadena;
}
