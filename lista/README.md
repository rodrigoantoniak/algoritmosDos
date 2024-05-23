# Listas

En esta carpeta, se encuentra el archivo de
encabezado y la implementación de lista en C.
Dentro de listas.h, se hallan las estructuras
de datos, definiciones de tipos y las definiciones
de las funciones (junto con una descripción).
Los structs que están dentro del archivo son:

- nodo: Representa la estructura de una unidad
  de una lista, contando con el valor almacenado
  y el siguiente nodo.
- coincidencias: Al buscar un valor en una lista,
  puede encontrarse el mismo varias veces; por
  lo que es necesario esta estructura que
  contiene los lugares en donde se encontró
  el valor buscado y la cantidad de lugares.

Dentro de las definiciones de datos, se halla:

- lista: Puntero a una estructura de nodo que
  inicia este tipo de colección. Por la estructura
  del nodo, se da a entender que es una lista
  enlazada; esto es, aclarando que no utiliza
  arrays (en otras palabras, no es ArrayList).
- resultado: Puntero a una estructura de
  coincidencias, dado que podría tener un
  resultado nulo al buscar en una lista vacía
  (no es lo mismo que no tener coincidencias).

Las funciones que se encuentran son: agregar,
insertar, eliminar, buscar, estaVacia, liberar y
cadena.

Siempre recuérdese de liberar cada lista
cuando no se va a ocupar más. Además, no
hay necesidad de ocupar punteros de lista
en el programa principal; con utilizar & es
suficiente.

___

## Preguntas frecuentes

> ¿Por qué no hay una función iniciar?

Para este caso, al declarar la igualdad de
la lista a NULL al principio es suficiente.
Por ejemplo:

```
lista l = NULL;
```

> ¿Se puede usar (lista == NULL) directamente,
> en vez de llamar a estaVacia()?

Si, inclusive se puede remover la función de
los archivos; quitando la necesidad de
incluir stdbool.h. De todas formas, se halla
la función para comprensión.
