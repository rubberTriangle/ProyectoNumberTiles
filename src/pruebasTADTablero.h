/*
 * pruebasTADTablero.h
 *
 *  Created on: 9 dic 2024
 *      Author: jorge
 */

#ifndef PRUEBASTADTABLERO_H_
#define PRUEBASTADTABLERO_H_


/*
 * Casos de prueba para inicializar un tablero aleatorio
 *
 * Caso 1: Tamaño mínimo
 *   Inicializamos un tablero 3x3 con matriz de entrada m y valores generados aleatoriamente.
 *   Mostramos el resultado para verificar su estructura.
 *
 * Caso 2: Tamaño intermedio
 *   Inicializamos un tablero 5x4 con matriz m y verificamos la estructura inicial generada.
 *
 * Caso 3: Tamaño máximo
 *   Inicializamos un tablero 7x7 con matriz m y comprobamos que se genera correctamente.
 */
void pruebaIniciarTableroAleatorio();

/*
 * Casos de prueba para poner valor en el tablero
 *
 * Caso 1: Esquina superior izquierda
 *   Ponemos un valor en la posición [0][0] y verificamos que se almacena correctamente.
 *
 * Caso 2: Centro del tablero
 *   Ponemos un valor en la posición [4][3] y comprobamos su correcta asignación.
 *
 * Caso 3: Esquina inferior derecha
 *   Ponemos un valor en la posición [7][7] y validamos que se almacena adecuadamente.
 */
void pruebaPonerValorTablero();

/*
 * Casos de prueba para obtener valor del tablero
 *
 * Caso 1: Esquina superior izquierda
 *   Obtenemos un valor en la posición [0][0] y verificamos que coincide con el esperado.
 *
 * Caso 2: Centro del tablero
 *   Obtenemos un valor en la posición [4][3] y validamos su precisión.
 *
 * Caso 3: Esquina inferior derecha
 *   Comprobamos el valor en la posición [7][7].
 */
void pruebaObtenerValorTablero();

/*
 * Casos de prueba para verificar si una casilla está vacía
 *
 * Caso 1: Casilla vacía inicial
 *   Vaciamos la casilla [0][0] y verificamos que está vacía.
 *
 * Caso 2: Casilla ocupada y luego vaciada
 *   Asignamos y eliminamos un valor en la posición [4][3] para confirmar que se vacía.
 *
 * Caso 3: Casilla ocupada y vaciada en el borde
 *   Realizamos el mismo procedimiento en [7][7].
 */
void pruebaEstaVaciaCasillaTablero();

/*
 * Casos de prueba para vaciar casillas del tablero
 *
 * Caso 1: Esquina superior izquierda
 *   Vaciamos la casilla [0][0] y verificamos que queda vacía.
 *
 * Caso 2: Centro del tablero
 *   Vaciamos la casilla [4][3] y confirmamos su estado.
 *
 * Caso 3: Esquina inferior derecha
 *   Probamos la funcionalidad en [7][7].
 */
void pruebaVaciarCasillaTablero();

/*
 * Casos de prueba para verificar si una columna está llena
 *
 * Caso 1: Columna parcialmente llena
 *   Verificamos que una columna con casillas vacías no está llena.
 *
 * Caso 2: Columna completamente llena
 *   Rellenamos una columna y confirmamos que está llena.
 */
void pruebaEstaLlenaColumnaTablero();

/*
 * Casos de prueba para verificar si el tablero está lleno
 *
 * Caso 1: Tablero vacío
 *   Verificamos que un tablero recién inicializado no está lleno.
 *
 * Caso 2: Tablero completamente lleno
 *   Llenamos todas las casillas y confirmamos el estado.
 */
void pruebaEstaLlenoTablero();

/*
 * Casos de prueba para obtener el número de filas del tablero
 *
 * Caso 1: Tablero 1x1
 *   Verificamos que el número de filas coincide con el valor inicial.
 *
 * Caso 2: Tablero 3x4
 *   Validamos el número de filas.
 *
 * Caso 3: Tablero 7x7
 *   Confirmamos que el número de filas es correcto.
 */
void pruebaObtenerNumFilas();

/*
 * Casos de prueba para obtener el número de columnas del tablero
 *
 *  Caso 1: Tablero 1x1
 *   Verificamos que el número de columnas coincide con el valor inicial.
 *
 * Caso 2: Tablero 3x4
 *   Validamos el número de columnas.
 *
 * Caso 3: Tablero 7x7
 *   Confirmamos que el número de columnas es correcto.
 */
void pruebaObtenerNumColumnas();

/*
 * Casos de prueba para obtener el valor máximo del tablero
 *
 * Caso 1: Tablero con valor 1024
 *   Confirmamos que se identifica el mayor valor.
 *
 * Caso 2: Tablero con valor 2048
 *   Confirmamos que se identifica el mayor valor.
 *
 * Caso 3: Tablero con valor 4096
 *   Confirmamos que se identifica el mayor valor.
 */
void pruebaObtenerValorMaximoTablero();

/*
 * Casos de prueba para rellenar huecos en el tablero
 *
 * Caso 1: Hueco en la esquina superior izquierda
 *   Probamos la funcionalidad rellenando desde [0][0].
 *
 * Caso 2: Hueco en el centro
 *   Rellenamos un hueco central y validamos.
 *
 * Caso 3: Hueco en la esquina inferior derecha
 *   Confirmamos que se rellena un hueco en [0][7].
 */
void pruebaRellenarHuecos();

/*
 * Casos de prueba para fusionar valores
 *
 * Caso 1: Fusión de valores alineados
 *   Probamos la fusión de valores consecutivos en una fila.
 *
 * Caso 2: Fusión de valores separados
 *   Verificamos que se combinan valores correctamente.
 */
void pruebaFusionar();

/*
 * Casos de prueba para fusionar valores
 *
 * Caso 1: Fusión de valores alineados
 * 	Probamos la fusión de de valores consecutivos adyacentes a una adyacente inferior.
 *
 * Caso 2: Comprobación de casillas adyacentes a una casilla adyacente a la original por la izquierda.
 * 	Comprobamos el número de casillas adyacentes a una dada.
 *
 * Caso 3: Comprobación de casillas adyacentes a una casilla adyacente a la original por la derecha.
 * 		Comprobamos el número de casillas adyacentes a una dada.
 */
void pruebaFusionar2();

/*
 * Casos de prueba para sugerir pista
 *
 * Caso 1: Pista básica
 *   Validamos que la pista devuelve una columna válida.
 *
 * Caso 2: Pista avanzada
 *   Confirmamos que las pistas más complejas funcionan correctamente.
 */
void pruebaPista();

/*
 * Casos de prueba para sugerir pista2
 *
 * Caso 1: Pista básica
 *   Validamos que la pista devuelve una columna válida.
 *
 * Caso 2: Pista avanzada
 *   Confirmamos que las pistas más complejas funcionan correctamente.
 */
void pruebaPista2();

/* Inicia las pruebas */
void pruebasTablero();

#endif /* PRUEBASTADTABLERO_H_ */
