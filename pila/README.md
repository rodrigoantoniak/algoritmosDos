# Pilas

En esta carpeta, se encuentra el archivo de
encabezado y la implementación de pila en C.
Dentro de pilas.h, se halla las definiciones de
estructura de datos y funciones (junto con una
descripción). La pila se define como una
estructura que contiene:

- cantidad: Representa cuántos elementos se
  hallan en la pila.
- valores: Un puntero hacia el primer valor
  insertado, el cual se gestiona como si fuera
  un array.

Las funciones que se encuentran son: iniciar,
apilar, desapilar, estaVacia, liberar y cadena.

Siempre recuérdese de liberar cada pila
cuando no se va a ocupar más. Además, no
hay necesidad de ocupar punteros de pila
en el programa principal; con utilizar & es
suficiente.

___

## Preguntas frecuentes

> ¿Se puede usar (pila.cantidad == 0)
> directamente, en vez de llamar a estaVacia()?

Si, inclusive se puede remover la función de
los archivos; quitando la necesidad de
incluir stdbool.h. De todas formas, se halla
la función para comprensión.
