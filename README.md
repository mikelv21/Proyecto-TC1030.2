# Proyecto-TC1030.2 "Casa Inteligente"

Este proyecto surge de la necesidad de optimizar el funcionamiento básico de una casa con el objetivo de ahorrar tiempo y energia electrica, además de hacer un monitoreo continuo en cuestion de seguridad del hogar. Todo esto con ayuda de algunos sensores y actuadores (como lamparas o motores). Esta programacion se vuelve mas logica y digerible gracias a la programacion orientada a objetos.

**Funcionalidad:**

Las indicaciones que se le dan al programa se le dan desde la clase "App", que simula una aplicacion del Smartphone del usuario, 
por lo tanto el "main" trabaja como la interfaz de dicha aplicacion donde se puede seleccionar entre las siguientes opciones:

Consultar los sensores:
  
   - Ver todos los sensores
   - Ver las camaras, ver solo una camara o poner a grabar una en especifico
   - Ver los sensores de Humo/Gas (Es el mismo integrado)
   - Ver los sensores de movimiento
   - Ver el estado de las puertas (si estan abiertas o cerradas)
   
Consultar los actuadores (Que son motores y lamparas):

   -Apagar, prender o observar las lamparas
   -Prender y apagar motores (Los motores pueden ser por ejemplo para encender una bomba de un huerto o abrir el porton de una cochera)
   
**Consideraciones:**

Este proyecto consta de 4 librerias, cada una con una respectiva clase y en su caso clases heredadas. Ademas de un "main"
Asi que como el programa esta hecho en c++ standard se puede correr en todos los sistemas operativos y en consola.

Compilar con: "g++ casa.h actuadores.h sensores.h app.h mainCasaInteligente.cpp"

correr en linux: "/a.out"
correr en windows: "a.exe"
