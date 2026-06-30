Tarea 3 - Simulador Gráfico en C++ y Qt de EloTelTags y Find My
ELO329 - Diseño y Programación Orientados a Objetos
1er Semestre 2026

Integrantes:
-Rodrigo Hernández
-Ignacio Torres

Etapa desarrollada: Etapa 4 (completa)

Descripción:
Este programa simula gráficamente con C++ y Qt la interacción entre dispositivos
EloTelTags, celulares y tablets sobre un mapa. Los equipos se mueven por el territorio
y rebotan en los bordes de la imagen de fondo. Los celulares reportan su posición a una
nube (ETNube), mientras que los EloTelTags y las tablets emiten periódicamente una señal
de búsqueda (radar visual) hacia los celulares cercanos. Al hacer click sobre un celular
o tablet se despliega un menú emergente con la opción "Find My", la cual abre una ventana
con los bienes rastreados de esa persona y su última posición conocida, actualizándose
cada 1 segundo. Además, cada equipo listado en la ventana Find My cuenta con un botón
"Traza" que muestra u oculta en el mapa la trayectoria recorrida por dicho equipo desde
que se activó.

Archivos entregados:
- main.cpp            : Punto de entrada del programa, inicializa la aplicación Qt.
- mainwindow.h/.cpp    : Ventana principal, lee el archivo de configuración, arma el
                         territorio con los equipos, controla el menú Simulation
                         (Play/Pause) y el avance de la simulación vía QTimer.
- equipo.h/.cpp        : Clase base abstracta de todos los dispositivos (celular, tag,
                         tablet). Define posición, movimiento y rebote en los bordes.
- cellular.h/.cpp      : Modelo del celular, hereda de Equipo.
- eloteltag.h/.cpp     : Modelo del EloTelTag. Maneja el ciclo de señal de búsqueda
                         (radar) cada 4 segundos y el registro de su traza.
- tablet.h/.cpp        : Modelo de la tablet. Maneja el ciclo de señal de búsqueda
                         (radar) cada 5 segundos y el registro de su traza.
- territory.h/.cpp     : Contenedor de todos los equipos de la simulación.
- territoryView.h/.cpp : Vista del territorio: dibuja la imagen de fondo, cada equipo
                         según su tipo (color/forma), el radar de búsqueda, las trazas
                         activas, y maneja el click del mouse para mostrar el menú
                         emergente Find My.
- etnube.h/.cpp        : Almacena los últimos reportes de posición de
                         los equipos rastreables, agrupados por dueño/a.
- findmywindow.h/.cpp  : Ventana Find My. Muestra los bienes de una persona según lo
                         reportado en ETNube, con botón de traza por cada equipo.
                         Se actualiza cada 1 segundo mientras está abierta.
- CMakeLists.txt       : Configuración del proyecto para compilar con Qt 6 (CMake).
- config.txt           : Archivo de configuración de ejemplo.
- Placeres.jpg         : Imagen de fondo del mapa.

Compilar y ejecutar:
El proyecto utiliza CMake y Qt 6, por lo que se recomienda abrirlo directamente en
Qt Creator:
  1. Abrir Qt Creator.
  2. File -> Open File or Project... -> seleccionar CMakeLists.txt
  3. En Projects, ir a Run Settings y en Working directory cambiar a donde está la carpeta de la 
     etapa(CMakeList.txt) para que haga build con la imagen Placeres.jpg de la carpeta.
  4. Ejecutar con el botón Run.

Salida:
Al ejecutar el programa se solicita mediante un QFileDialog la selección del archivo
de configuración (config.txt). Luego se muestra una ventana con el mapa de Placeres y
los equipos posicionados según dicho archivo: celulares (azul), EloTelTags (verde) y
tablets (naranja). Tags y tablets despliegan periódicamente un radar visual (círculo
que crece) al buscar celulares cercanos. Al hacer click sobre un celular o tablet y
seleccionar "Find My" en el menú emergente, se abre una ventana con la lista de bienes
de esa persona y sus últimas posiciones reportadas a la nube, actualizada cada 1 segundo
destacar que se actualiza cada vez que los bienes están cerca.
Presionando el botón "Traza" de un equipo en esa ventana, se dibuja en el mapa la
trayectoria seguida por dicho equipo; al presionar nuevamente el botón, la traza
desaparece.

Supuestos:
- El archivo config.txt sigue el formato especificado en el enunciado, sin líneas
  vacías ni datos faltantes.
- Los ángulos en config.txt están en grados y se convierten internamente a radianes.
- Los equipos comienzan a moverse automáticamente al cargar la configuración; el menú
  Play/Pause permite reanudar o detener dicho movimiento.
- La ventana Find My muestra la última posición reportada a la nube (ETNube), no la
  posición en tiempo real del equipo.
- El radio de detección de click sobre un equipo en el mapa es de 15 píxeles.

Documentación:
La documentación del proyecto se encuentra en el archivo PDF adjunto
(Documentacion_Tarea3_ELO329_Hernández_Torres.pdf) e incluye:
- Diagrama de clases de la última etapa desarrollada.
- Explicación de la interacción entre clases.
- Dificultades encontradas durante el desarrollo y sus soluciones.

Repositorio:
Cada etapa (1, 2, 3 y 4) cuenta con su propio proyecto dentro del repositorio de
GitHub, conforme a lo solicitado en el enunciado para el desarrollo
iterativo e incremental.