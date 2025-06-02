/*
 * pruebasTADCasilla.cpp
 *
 *  Created on: 9 dic 2024
 *      Author: jorge
 */

#include "TADCasilla.h"
#include "pruebasTADCasilla.h"

#include <fstream>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

void pruebaCrearCasilla(){
	Casilla c;
	crearCasilla(c);
	if (c.ocupada && c.valor != 0){
		cout << "Error al crear casilla" << endl;
	}
}

void pruebaPonerValorCasilla(){
	Casilla c1;
	Casilla c2;

	ponerValorCasilla(c1, 8);

	if (c1.valor != 8){
		cout << "Error al poner valor a la casilla en caso 1" << endl;
	}

	ponerValorCasilla(c2, 10);

	if (c2.valor != 10){
		cout << "Error al poner valor a la casilla en caso 2" << endl;
	}
}

void pruebaObtenerValorCasilla(){
	Casilla c1;
	Casilla c2;

	c1.valor = 4;
	c2.valor = 8;

	if(obtenerValorCasilla(c1) != 4){
		cout << "Error al obtener valor de la casilla en caso 1" << endl;
	}

	if (obtenerValorCasilla(c2) != 8){
		cout << "Error al obtener valor de la casilla en caso 2" << endl;
	}
}

void pruebaEstaVaciaCasilla(){
	Casilla c1;
	Casilla c2;

	c1.ocupada = true;
	c2.ocupada = false;

	if (estaVaciaCasilla(c1)){
		cout << "Error al ver si estaba vacia la casilla en caso 1" << endl;
	}

	if(!estaVaciaCasilla(c2)){
		cout << "Error al ver si estaba vacia la casilla en caso 2" << endl;
	}
}

void pruebaVaciarCasilla(){
	Casilla c1;
	Casilla c2;

	c1.ocupada = true;
	c2.ocupada = false;

	vaciarCasilla(c1);
	vaciarCasilla(c2);

	if (c1.ocupada){
		cout << "Error al vaciar la casilla en caso 1" << endl;
	}

	if (c2.ocupada){
		cout << "Error al vaciar la casilla en caso 2" << endl;
	}
}

void iniciarPruebasCasilla(){

	cout << "Inicio pruebas Casilla" << endl;

	pruebaCrearCasilla();

	pruebaPonerValorCasilla();

	pruebaObtenerValorCasilla();

	pruebaEstaVaciaCasilla();

	pruebaVaciarCasilla();

	cout << "Fin pruebas Casilla" << endl;
}
