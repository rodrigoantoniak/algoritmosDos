# Tipos de datos

Bienvenido al repositorio que contiene los tipos
de datos utilizados en Algoritmos y Estructuras
de Datos 2. Dentro de este repositorio, se divide
cada tipo de archivo dentro de su respectiva
carpeta; de ahí, es insertar de la forma deseada
en el programa a compilar, incluirlo adecuadamente
y obtener el ejecutable correctamente. Para ello,
se recomienda instalar los siguientes componentes:

### Windows

1. [Visual Studio Code][vscode]: si bien, existen editores
    de texto más livianos y entornos de desarrollo más
    complejos; VSCode cumple el propósito deseado,
    además que posee características particulares
    buscadas. Dentro de ellas están las extensiones
    [Remote Development][remote] y
    [C/C++ Extension Pack][cpptools], donde la
    primera se instala nativamente y el segundo
    dentro del servidor de VSCode en WSL.
2. [Subsistema de Windows para Linux][wsl] (WSL):
    Microsoft ofrece la posibilidad de ejecutar este
    híbrido entre máquina virtual y contenedor, así
    se logra el funcionamiento de programas hechos
    para Linux sin tener que instalarlo nativamente.
    Por ejemplo, permite compilar programas de
    C pretendidos para sistemas basados en UNIX.
3. [Kit de desarrollo en C][config-cpp] y
    [GDB][gdb]: dentro de la distribución Linux que
    corresponda al subsistema, es necesario instalar
    el paquete que abarque el conjunto de
    herramientas para trabajar en C; así también,
    hace falta agregar el depurador de GNU (ya que
    se ocupa el Compilador C de GNU, llamado GCC).
    El comando a ejecutar cambiará según la distro
    utilizada, es decir:

   - Debian y derivados (Kali Linux, Ubuntu, etc.):

      ```
      sudo apt install build-essential gdb
      ```

   - openSUSE y derivados (SUSE Linux Enterprise):

      ```
      sudo zypper install
      patterns-devel-base-devel_basis gdb
      ```

   - Arch y derivados (Manjaro, etcétera):

      ```
      sudo pacman -S base-devel gdb
      ```

   - Alpine:

      ```
      doas apk add build-base gdb
      ```

   - Red Hat Enterprise Linux (RHEL) y derivados
      (Alma, Rocky, Oracle):
 
      ```
      sudo yum group install
      "Development Tools"
      ```

   - Fedora y derivados (openEuler, entre otros):

      ```
      sudo dnf group install
      "Development Tools"
      ```

### Linux

1. Un compilador y un depurador de C: puede
    elegir entre GCC+GDB y LLVM Clang+LLDB
    (existen otros compiladores, pero se recomienda
    usar estos).
2. Un editor de texto o un entorno de desarrollo:
    considerando el sistema operativo, para este
    punto hay elecciones ilimitadas y será preferencia
    del usuario final.

### OS X

1. [XCode][xcode]

### FreeBSD

1. Un editor de texto o un entorno de desarrollo:
    como este sistema operativo incluye Clang
    (cuyo ejecutable se llama cc), sólo hace falta
    decidir el programa para escritura de código.

## Compilación de programas

1. Colocar la(s) biblioteca(s) a ocupar en el programa
    dentro de su directorio.
2. Incluir la(s) biblioteca(s) entre comillas dobles, en
    vez de los símbolos < y >; llamándolo por su
    extensión de encabezado (.h).
3. Compilar adecuadamente para obtener el ejecutable,
    esto es usar el siguiente comando:

    ```
    compilador -Wall -o programa programa.c biblioteca.c
    ```

donde:

- compilador puede variar entre gcc, clang y cc, según
    el sistema operativo y la elección hecha.
- \-Wall provee todas las advertencias importantes para
    estos programas.
- '\-o programa' indica que el ejecutable se llamará
    programa, cuyo nombre puede cambiarse a lo que
    desee.
- programa.c corresponde al programa principal escrito,
    debe reemplazarse el nombre por el que asigne.
- biblioteca.c tendrá el nombre del archivo de
    encabezado incluido en el programa principal; en
    otras palabras, puede ser lista.c, pila.c o cola.c.
    Cuando se utilice varios de estos, se coloca todas
    las bibliotecas usadas; separándose por un espacio
    en blanco, sin importar el orden (ni lista, ni pila, ni
    cola se dependen entre sí).

___

## Preguntas frecuentes

> ¿Por qué usar el comando, en vez de una utilidad que
> provee un entorno de desarrollo?

Lo que se desarrolla es muy sencillo y evita perder
tiempo configurando para cada programa que
se pueda generar, siendo que debe cambiarse al
utilizar una biblioteca en vez de otra. Si el proyecto
realmente fuera de una complejidad considerable, sería
necesario usar una herramienta como make (con
Makefile) o cmake (con CMakeLists.txt).

[vscode]: https://code.visualstudio.com/
[remote]: https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack
[cpptools]: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack
[wsl]: https://learn.microsoft.com/es-mx/windows/wsl/
[config-cpp]: https://code.visualstudio.com/docs/cpp/config-wsl
[gdb]: https://sourceware.org/gdb/
[xcode]: https://developer.apple.com/xcode/
