# TP3_SO
Trabajo práctico N°3: "Sockets" - '72.11 - Sistemas Operativos' - 2Q2021

## Compilación del trabajo
Para compilar el trabajo, primero el usuario debe posicionarse en el directorio donde se encuentra
el trabajo. Luego, simplemente ejecutar el siguiente comando:

    $ make all

Esto generará dos archivos ejecutables: `server` y `client`

## Instrucciones de ejecución
Para ejecutar el server y poder utilizarlo, uno debe conectarse a través del client. Esto se hace
de la siguiente manera: 
Primero, se ejecuta el comando que inicializa el server:
    
    $ ./server

Cuando realizamos esto, veremos que se imprime a pantalla el estado de ejecución del servidor,
que ya se encuentra corriendo (esperando una conexión).
Luego, se abre otra terminal, que debe posicionarse sobre el mismo directorio, y allí ejecutar:

    $ ./client

De esta manera, el cliente se conecta al servidor, y así se puede interactuar con el mismo.

### Autores
* De Simone, Franco - 61100
* Dizenhaus, Manuel - 61101
* Cornidez, Milagros - 61432