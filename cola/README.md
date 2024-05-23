# Colas

En esta carpeta, se encuentra el archivo de
encabezado y la implementación de cola en C.
Dentro de colas.h, se halla las definiciones de
estructura de datos y funciones (junto con una
descripción). La cola se define como una
estructura que contiene:

- valores: Un puntero hacia el último valor
  insertado, el cual se gestiona como si fuera
  un array.
- cantidad: Representa cuántos elementos se
  hallan en la cola.

Las funciones que se encuentran son: iniciar,
enfilar, desfilar, estaVacia, liberar y cadena.

Siempre recuérdese de liberar cada cola
cuando no se va a ocupar más. Además, no
hay necesidad de ocupar punteros de cola
en el programa principal; con utilizar & es
suficiente.

___

## Preguntas frecuentes

> ¿Se puede usar (cola.cantidad == 0)
> directamente, en vez de llamar a estaVacia()?

Si, inclusive se puede remover la función de
los archivos; quitando la necesidad de
incluir stdbool.h. De todas formas, se halla
la función para comprensión.
