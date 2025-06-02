/*
 * pruebasTADCasilla.h
 *
 *  Created on: 9 dic 2024
 *      Author: jorge
 */

#ifndef PRUEBASTADCASILLA_H_
#define PRUEBASTADCASILLA_H_

/*
 * Casos de prueba para crear una casilla
 *
 * Caso 1: Creación de una casilla
 *   Se crea una casilla con valores iniciales. Verificamos que está vacía y su valor es 0.
 */
void pruebaCrearCasilla();

/*
 * Casos de prueba para poner valor en una casilla
 *
 * Caso 1: Asignar valor 8:
 *   Asignamos el valor 8 a una casilla y confirmamos que se almacena correctamente.
 *
 * Caso 2: Asignar valor 10:
 *   Asignamos el valor 10 a una casilla diferente y comprobamos el resultado.
 */
void pruebaPonerValorCasilla();

/*
 * Casos de prueba para obtener valor de una casilla
 *
 * Caso 1: Obtener valor 4:
 *   Ponemos una casilla con valor 4 y confirmamos que se obtiene el resultado.
 *
 * Caso 2: Obtener valor 8:
 *   Ponemos una casilla con valor 8 y confirmamos el resultado.
 */
void pruebaObtenerValorCasilla();

/*
 * Casos de prueba para verificar si una casilla está vacía
 *
 * Caso 1: Casilla ocupada:
 *   Ponemos una casilla como ocupada y confirmamos que no está vacía.
 *
 * Caso 2: Casilla vacía:
 *   Ponemos una casilla como vacía y confirmamos que el estado es vacía.
 */
void pruebaEstaVaciaCasilla();

/*
 * Casos de prueba para vaciar una casilla
 *
 * Caso 1: Casilla ocupada:
 *   Vaciar una casilla ocupada y confirmar que queda vacía.
 *
 * Caso 2: Casilla ya vacía:
 *   Intentar vaciar una casilla que ya está vacía y verificar que el estado no varia.
 */
void pruebaVaciarCasilla();

/* Inicia las pruebas */
void pruebasCasilla();


#endif /* PRUEBASTADCASILLA_H_ */
