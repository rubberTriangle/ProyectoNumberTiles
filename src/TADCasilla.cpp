/*
 * TADCasilla.cpp
 *
 *  Created on: 25 nov 2024
 *      Author: jorge
 */

#include "TADCasilla.h"

#include <fstream>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;


void crearCasilla(Casilla &c){
	c.ocupada = false;
	c.valor = 0;
}

void ponerValorCasilla(Casilla &c, int valor){
	c.ocupada = true;
	c.valor = valor;
}

int obtenerValorCasilla(Casilla c){
	return c.valor;
}

bool estaVaciaCasilla(Casilla c){
	return !c.ocupada;
}

void vaciarCasilla(Casilla &c){
	c.ocupada = false;
	c.valor = 0;
}
