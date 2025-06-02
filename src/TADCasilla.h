/*
 * TADCasilla.h
 *
 *  Created on: 25 nov 2024
 *      Author: jorge
 */

#ifndef TADCASILLA_H_
#define TADCASILLA_H_


struct Casilla{
	bool ocupada;
	int valor;
};

//PRE={c iniciada}
//POST={crea una nueva casilla vacía}
//COMPLEJIDAD: O(n)
void crearCasilla(Casilla &c);

//PRE={c iniciada y valor > 0 y es un número 2^n}
//POST={pone el valor en la casilla}
//COMPLEJIDAD: O(n)
void ponerValorCasilla(Casilla &c, int valor);

//PRE={c iniciada}
//POST={devuelve el valor de la casilla indicada}
//COMPLEJIDAD: O(n)
int obtenerValorCasilla(Casilla c);

//PRE={c iniciada}
//POST={devuelve true si la casilla está vacía y false si no}
//COMPLEJIDAD: O(n)
bool estaVaciaCasilla(Casilla c);

//PRE={c iniciada}
//POST={vacia la casilla especificada}
//COMPLEJIDAD: O(n)
void vaciarCasilla(Casilla &c);

#endif /* TADCASILLA_H_ */
