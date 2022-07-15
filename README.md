<h1 align="center">Universidad de Costa Rica

Facultad de ingeniería 

Escuela de Ingeniería Eléctrica

IE0117-Programación bajo plataformas abiertas

I Ciclo  2022



Proyecto

Resolvedor de laberintos

Jonathan Gómez Hidalgo B93297

Grupo: 001

Profesor: Juan Carlo Coto

</h1>

## índice:
---

- [Introducción](#Introducción)
- [Diseño General](#diseño-General)
- [Principales Retos](#principales-Retos)
- [Conclusiones](#Conclusiones )

# Introducción
---
En este documento se explorará la forma en que se crea el resolvedor de laberintos, las limitaciones que este tiene, algunos desafíos que se presentaron durante la creación del código, finalmente se plantean observaciones obtenidas durante el proceso de programación para obtener un código más ordenado.

# Diseño General
---
Este programa carga un archivo .txt con la información de un laberinto elaborado a partir de ceros, unos y dos, los ceros indican pared, los unos  indican los caminos y el 2 indica el final del camino corecto del laberinto, el código está conformado por las siguientes secciones:

## Principal.
Esta parte del código se encarga de cargar las siguienes dos partes del código y luego de procesar dichas secciones imprime en consola el laberinto resuelto.

Esta parte se programó cargando los archivos de las otras partes del programa y posteriormente se crea una función que imprime el laberinto resuelto,finalmente en la función main se llama la función que dibuja el laberinto resuelto.

## Cargar_archivo
Esta sección se encarga de  leer los datos que se encuentran en el documento .txt, estos datos se leen como de tipo char, en este código luego de ser cargado, estos datos se convierten en una matriz numérica para a poder utilizar las direcciones de cada posición de la matriz y de esta manera manipular las posiciones de los unos posteriormente.

Esta sección se programó de forma que cargue un archivo .txt en modo lectura, posteriormente se accede a cada linea que se encuentra en el archivo y se almacena en una variable temporalmente para seguidamente transformar esa  linea a un dato de forma numérica y posteriormente esta linea ya se separa cada numéro de esta fila y se almacena en una matriz y el proceso se repite para cada linea hasta obener toda la información del laberinto.

## solucionador_lab
Este script se encarga de revisar las posiciones laterales, superior e inferior de cada uno que se encuentre en cada fila de la matriz obtenida, para obtener las posiciones se utilizó el formato de "nombre_de_la_matriz[fila][columna]" ya que con esta forma se puede cambiar de fila o columna facilmente en un for sumando o restanto un 1 a la posición en la que se encuentra hubicado, el indice del for en ese momento, en el caso de que al menos tres posiciones en cualquier combinación de las posiciones laterales, superior o inferior de cada 1 correspondan a un 0, este 1 se cambiará por un 0 ya que este 1 no pertence al camino que lleva a la solucion del laberinto.

Este script se programón de manera que recorra la matriz obtenida con el script anterior y luego realiza el proceso descrito anteriormente de eliminar los unos que no forman parte del camino correcto.

Finalmente se llama la funcion de otro script que se encarga de revisar si el laberinto ya fue solucionado o necesita eliminar otros unos que no corresponden a la solución correspondiente.

## prueba_lab
Este código verifica que una vez que se hayan eliminado todos lo unos poibles no queden más unos que no corresponden, ya que generalmente se necesita más de una revisión, para ello veamos un ejemplo, tome en cuenta la siguiente matriz de ejemplo.

<h1 align="center">
0 0 0 0 1 0 0

0 1 1 1 1 0 0

0 0 0 1 0 0 0

0 2 1 1 0 0 0
</h1>

Para posicionarnos en la matriz utilizaremos el formato [fila][columna] comenzando desde la posición [0][0] en la esquina superior izquierda, observando la posición [1][1] se descubre que hay un 1, sin embargo, este uno no corresponde al camino que soluciona el laberinto, por lo tanto se elimina, pero si este se elimina luego en la posición [1][2] queda otro uno que no corresponde, por lo que el proceso de eliminar los unos que no cumplan con la condición de formar parte del camino de la solución se deben eliminar, por esta razón el proceso debe ser repetitivo.

 Esta sección se programó de manera que recorra la matriz y cada vez que se encuentre un 1 verifica que este uno esté "conectado" solamente a dos unos vecinos o a un  uno y un dos, en cualquiera de estos casos el uno es valido en la posición en la que se encuentra ya que un camino valido como solución del laberinto implica que cada uno sea como un conducto por lo que no puede tener desviaciones.


# Principales Retos
---

## Reto 1.
Uno de los retos que se presentó es que al inicio el código se creó en un solo script, sin embargo posteriormente se fue separando en diferentes secciones según se fue necesitando, inicialmente cada parte del código se realizaba en el script principal y posteriormente se separaba cuando ya estaba listo, en estos casos, algunas partes del código dependían de 
variables que se encontraban en otro script por lo que no estaban definidas, la solución a este inconveniente fue declarar las variables como variables globales por lo que ya era posible llamarlas desde el script donde se estaba llamando un script secundario.


## Reto 2.
Otro reto fue a partir de la instalación de Git en el sistema operativo, ya que se necesitaba ingresar como ROOT para lograr realizar la instalación, sin embargo, cuando intentaba iniciar la instalación el sistema lanzaba un error referente a un  servidor de la Universidad de Costa Rica, la solución a este problema fue actualizar sudo mediante el comando "sudo apt-get update"  y con eso fue suficiente para instalar satisfactoriamente GIT.

## Reto 3.

Un reto imortante que surgió fue al mometno de enlazar el repositorio de GIT con GITHUB ya que se cargaban los archivos sin problema, sin embargo luego de subir los archivos hay que loguearse con el usuario de GITHUB, sin embargo, al utilizar el usuario y contraseña establecidos en la pagina de GITHUB se generaba un error de acceso, con una investigación al respecto, encontré que GITHUB declaró como obsoleto el sistema de loguearse y que actualmente se utilizan tokens, los cuales se generan desde la página de GITHUB, entonces, al momento de loguearse en consola, se utiliza el mismo usuario pero para la contraseña  se utiliza el token generado desde GITHUB.

## Reto 4.
El principal reto fue idear una manera de resolver el laberinto, ya que debe ser de manera general, es decir, que el método sea capaz de resolver cualquier laberinto, finalmente el método utiliazado funciona aunque tiene algunas deficiencias, la solución obtenida se basa en convertir la matriz de caracteres en una matriz numérica y luego manipular los unos que se encuentran en ella, con esto se deben considerear todos los casos que se pueden dar en la matriz, por ejemplo, si hay un 1 en la primera fila, las condiciones de las celdas vecinas son diferentes a las de un uno que se encuentre en la fila del centro de la matriz, ya que en el primer caso solo existen 3 celdas vecinas y en el segundo caso hay 4, por otro lado, si el uno se encuentra en la última fila, las condiciones de las celdas vecinas van a ser iguales al primer caso, sin embargo, la posición de las celdas vecinas es diferente, estos son solamente algunos de los casos, pues existen muchos otros y el margen de error es muy grande ya que existen muchas posibilidades de no tomar en cuenta algún caso importante, por eso este es uno de las limitantes de este metodo.

## Reto 5
Un reto importante fue determinar como realizar el script que revisa si el laberinto se resuelve de forma correcta y válida ya que se dificulta obtener el camino del laberinto exclusivamente, sin embargo se logra crear de forma efectiva y funcional, sin embargo, por la forma en que está realizado tiene sus limitaciones ya que se deben evaluar diferentes circunstancias y hay muchas posibilidades de dejar alguna comnbinación olvidada.


# Conclusiones
---
El principal aprendizaje obtenido en este proyecto fue la importancia de dividir el programa en diferentes scripts, ya que de esta manera se obtiene un mejor orden en el código y si se necesitan hacer cambios solo se ingresa al archivo que contiene la sección que se desea cambiar, ya que al inicio estaba haciendo el código en un solo archivo pero cuando se hizo más grande se llegaron a 200 lineas de código y buscar una sección para realizarle cambios dentro de tantas lineas se dificulta, por lo que en ese punto decidí separfarlo en seciones de acuerdo a la función que realiza cada parte y de esta manera se obtuvieron las diferentes partes en las cuales resulta el programa completo, algunas preguntas que surgieron realizando el proyecto fueron las siguientes.

- Realizar un script que se ejecute automaticamente en linux cada vez que se encienda el sistema?, esta pregunta surge a partir de que quería cambiarle el idioma del teclado en linux mientras editaba el archivo README.md y realizando una investigación indicaban que esta  era una solución para cambiar el idioma cada vez que se inicia el sistema.
- Si yo tengo un repositorio público en GItHUB, cualquier persona puede ingresar y editarlo o solamente las personas que yo invite?


