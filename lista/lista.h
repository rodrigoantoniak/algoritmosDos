#include <stdbool.h>

struct nodo {
  int valor;
  struct nodo *siguiente;
};

typedef struct nodo *lista;

struct coincidencias {
  unsigned int *lugares;
  unsigned int cantidad;
};

typedef struct coincidencias *resultado;

/**
 * Agrega un valor x al final de una lista l.
 * @param l Lista a la que se le agregará el valor.
 * @param x Valor a agregar.
 * @return 0 si se agregó correctamente,
    -1 si la lista es nula.
 */
int agregar(lista *l, int x);

/**
 * Inserta un valor x en una determinada posición n de una lista l.
 * @param l Lista en la que se insertará el valor.
 * @param x Valor a insertar.
 * @param n Posición en la que se insertará el valor.
 * @return 0 si se insertó correctamente,
    1 si n es mayor a la cantidad de elementos,
    -1 si la lista es nula.
 */
int insertar(lista *l, int x, unsigned int n);

/**
 * Elimina el valor en una posición n de una lista l.
 * @param l Lista a la que se le eliminará el valor.
 * @param n Posición en la que se insertará el valor.
 * @return 0 si se eliminó correctamente,
    1 si n es mayor o igual a la cantidad de elementos,
    -1 si la lista es nula.
 */
int eliminar(lista *l, unsigned int n);

/**
 * Busca un valor x en una lista l.
 * @param l Lista en la que se buscará el valor.
 * @param x Valor a buscar.
 * @return NULL si la lista es nula,
    sino un resultado con los lugares donde se encontró el valor y
    la cantidad de coincidencias.
 */
resultado buscar(lista l, int x);

/**
 * Indica si una lista l está vacía.
 * @param l Lista a evaluar.
 * @return booleano que indica si la lista está vacía.
 */
bool estaVacia(lista l);

/**
 * Libera una lista de la memoria de la computadora.
 * @param l Puntero a lista que se va a liberar.
 */
void liberar(lista *l);

/**
 * Devuelve una cadena con los valores de una lista l.
 * @param l Lista a convertir.
 * @return NULL si la lista es nula,
    sino una cadena con los valores de la lista.
 */
char *cadena(lista l);
