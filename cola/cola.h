#include <stdbool.h>

typedef struct {
  int *valores;
  unsigned int cantidad;
} cola;

/**
 * Inicia una nueva cola válida
 * @param p Puntero a cola que se va a iniciar.
 * @return 0 si se inició correctamente,
    -1 si el puntero es nulo.
 */
int iniciar(cola *c);

/**
 * Enfilar un valor x en una cola p.
 * @param p Puntero a cola que se le apilará el valor.
 * @param x Valor a agregar.
 * @return 0 si se apiló correctamente,
    -1 si el puntero es nulo.
 */
int enfilar(cola *c, int x);

/**
 * Desfilar el primer valor agregado a una cola p.
 * @param p Puntero a cola que se le desapilará el valor.
 * @return NULL si el puntero es nulo o la cola está vacía,
    sino un puntero al valor desapilado.
 */
int *desfilar(cola *c);

/**
 * Indica si una cola c está vacía.
 * @param c Cola a evaluar.
 * @return booleano que indica si la cola está vacía.
 */
bool estaVacia(cola c);

/**
 * Libera el contenido de una cola de la memoria de la computadora.
 * @param p Puntero a la cola que se va a liberar.
 */
void liberar(cola *c);

/**
 * Devuelve una cadena con los valores de una cola c.
 * @param c Cola a convertir.
 * @return NULL si la cola está vacía,
    sino una cadena con los valores de la cola.
 */
char *cadena(cola c);
