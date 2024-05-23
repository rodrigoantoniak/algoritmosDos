#include <stdbool.h>

typedef struct {
  unsigned int cantidad;
  int *valores;
} pila;

/**
 * Inicia una nueva pila válida
 * @param p Puntero a pila que se va a iniciar.
 * @return 0 si se inició correctamente,
    -1 si el puntero es nulo.
 */
int iniciar(pila *p);

/**
 * Apilar un valor x en una pila p.
 * @param p Puntero a pila que se le apilará el valor.
 * @param x Valor a agregar.
 * @return 0 si se apiló correctamente,
    -1 si el puntero es nulo.
 */
int apilar(pila *p, int x);

/**
 * Desapilar el último valor agregado a una pila p.
 * @param p Puntero a pila que se le desapilará el valor.
 * @return NULL si el puntero es nulo o la pila está vacía,
    sino un puntero al valor desapilado.
 */
int *desapilar(pila *p);

/**
 * Indica si una pila p está vacía.
 * @param p Pila a evaluar.
 * @return booleano que indica si la pila está vacía.
 */
bool estaVacia(pila p);

/**
 * Libera el contenido de una pila de la memoria de la computadora.
 * @param p Puntero a la pila que se va a liberar.
 */
void liberar(pila *p);

/**
 * Devuelve una cadena con los valores de una pila p.
 * @param p Pila a convertir.
 * @return NULL si la pila es nula,
    sino una cadena con los valores de la pila.
 */
char *cadena(pila p);
