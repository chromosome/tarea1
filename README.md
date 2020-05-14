# Tarea 1

## Dependencias

Para generar los datos de entrada y graficar los de salida se requiere numpy, scipy y matplotlib.

## Uso

El archivo maestro tarea1.sh controla la compilación y ejecución de los programas.
Para compilar todos los programas:

```sh
. ./tarea1.sh && build_all
```

Para compilar un programa individual utilice:

```sh
. ./tarea1.sh && build $(nombre_del_programa)
```

Una vez compilados pueden ejecutarse mediante:

```sh
. ./tarea1.sh && run $(nombre_del_programa)
```
El tiempo de ejecución se escribe a un archivo con el nombre_del_programa en la carpeta "results".

Para generar los graficos
