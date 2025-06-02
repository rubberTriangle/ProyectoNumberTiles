/*
 * TADJuego.cpp
 *
 *  Created on: 18 dic 2024
 *      Author: jorge
 */

#include "entorno.h"
#include "TADCasilla.h"
#include "TADTablero.h"
#include "TADJuego.h"

#include <fstream>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;


void terminar(bool perdido){
	string msg;
	msg = " ";

	if(!perdido){
		msg = "Te has rendido";
		entornoMostrarMensajeFin(msg);
	}else{
		msg = "Has perdido";
		entornoMostrarMensajeFin(msg);
	}

	entornoPausa(1.5);
	entornoTerminar();
}

void actualizar(Juego juego, int filaPista, int columnaPista){

	if(filaPista != -1 && columnaPista != -1)
		entornoEliminarNumero(filaPista, columnaPista);

	for(int i = 0; i < obtenerNumColumnas(juego.tablero); i++){
		for (int j = 0; j < obtenerNumFilas(juego.tablero); j++){
			if (obtenerValorTablero(juego.tablero, j, i) != 0){
				entornoEliminarNumero(j, i);
				entornoPonerNumero(j, i, obtenerValorTablero(juego.tablero, j, i));
			}else{
				entornoEliminarNumero(j, i);
			}
		}
	}

	entornoPonerPuntuacion(juego.puntuacion);
}

void juego(Juego &juego){

	bool salir = false;
	bool fusion = true;

	TipoTecla tecla;
	int numFilas = obtenerNumFilas(juego.tablero);
	int numColumnas = obtenerNumColumnas(juego.tablero);
	int columnas = 0;
	int exponente;
	int valor;

	int desechar = 3;

	int columnaPista = -1;
	int filaPista = -1;

	int filaColocar;

	juego.puntuacion = 0;

	entornoPonerPuntuacion(juego.puntuacion);

	entornoContadorAyuda(desechar);

	obtenerValorMaximoTablero(juego.tablero, exponente);

	valor = pow (2,exponente);
	entornoPonerNumeroLanzador(valor, 0);
/*
	for (int i = 0; i < numFilas; i++){
		cout << "\n";
		for (int j = 0; j < numColumnas; j++){
			cout << obtenerValorTablero(t, i, j) << " ";
		}
	}
*/

	actualizar(juego, filaPista, columnaPista);

	while (!salir) {
		tecla = entornoLeerTecla();

		switch (tecla) {
		case TEnter:
			if(!estaLlenaColumnaTablero(juego.tablero, columnas)){
				juego.puntuacion = juego.puntuacion + valor;

				filaColocar = obtenerPosicionVaciaColumnaTablero(juego.tablero, columnas);

				ponerValorTablero(juego.tablero, filaColocar, columnas, valor);

				fusionar(juego.tablero, filaColocar, columnas, valor, juego.puntuacion);

				for (int i = 0; i < numFilas; i++){
					for (int k = 0; k < numColumnas; k++){
						if(obtenerValorTablero(juego.tablero, i, k) != 0){
							fusionar(juego.tablero, i, k, obtenerValorTablero(juego.tablero, i, k), juego.puntuacion);
						}
					}
				}
/*
				for (int i = 0; i < numFilas; i++){
					cout << "\n";
					for (int j = 0; j < numColumnas; j++){
						cout << obtenerValorTablero(t, i, j) << " ";
					}
				}
*/
				obtenerValorMaximoTablero(juego.tablero, exponente);

				exponente = 1+ rand()%exponente;
				valor = pow (2,exponente);

				entornoQuitarNumeroLanzador(columnas);
				entornoPonerNumeroLanzador(valor, columnas);

				actualizar(juego, filaPista, columnaPista);
			}else{
				if (obtenerValorTablero(juego.tablero, numFilas-1, columnas) == valor){
					filaColocar = numFilas;
					fusionar(juego.tablero, filaColocar, columnas, valor, juego.puntuacion);

					obtenerValorMaximoTablero(juego.tablero, exponente);

					exponente = 1+ rand()%exponente;
					valor = pow (2,exponente);

					entornoQuitarNumeroLanzador(columnas);
					entornoPonerNumeroLanzador(valor, columnas);

					actualizar(juego, filaPista, columnaPista);
				}
			}

			break;

		case TDerecha:
			entornoQuitarNumeroLanzador(columnas);

			if (columnas < numColumnas - 1)
				columnas++;
			else
				columnas = 0;

			entornoPonerNumeroLanzador(valor, columnas);

			break;

		case TIzquierda:
			entornoQuitarNumeroLanzador(columnas);

			if (columnas == 0)
				columnas = numColumnas - 1;
			else
				columnas--;

			entornoPonerNumeroLanzador(valor, columnas);
			break;

		case TF1:
			if (desechar > 0){
				exponente = 1 + rand() % 8;
				valor = pow (2,exponente);

				entornoQuitarNumeroLanzador(columnas);
				entornoPonerNumeroLanzador(valor, columnas);

				desechar--;

				entornoContadorAyuda(desechar);
			}
			break;

		case TF2:
			columnaPista = pista(juego.tablero, valor);
			filaPista =	obtenerPosicionVaciaColumnaTablero(juego.tablero, columnaPista);

			if (columnaPista != -1){
				entornoPonerNumeroPista(filaPista, columnaPista, valor);
			}
			break;

		case TSalir:
			terminar(salir);
			break;

		case TNada:
			break;
		}

		bool enc = false;

		for (int i = 0; i < numColumnas; i++){
			if (obtenerValorTablero(juego.tablero, numFilas-1, i) == valor){
				enc = true;
			}
		}

		if (estaLlenoTablero(juego.tablero) && desechar == 0 && !enc){
			//cout << "Esta lleno";
			terminar(!salir);
		}
	}

	terminar(salir);
}


bool iniciar(Juego j){

	bool func = false;

	srand (time(NULL));

	int numFilas, numColumnas, comoIniciar, filasIniciales;

	int m[MAX_FILAS][MAX_COL];

	if (entornoCargarConfiguracion(numFilas, numColumnas, comoIniciar, filasIniciales, m)){

		func = true;

		if (comoIniciar == 0){
			entornoIniciar(numFilas, numColumnas);
			iniciarTablero(j.tablero, numFilas, numColumnas, filasIniciales, comoIniciar, m);

		}else{
			numFilas = 5;
			numColumnas = 5;
			filasIniciales = 2;

			entornoIniciar(numFilas, numColumnas);
			iniciarTablero(j.tablero, numFilas, numColumnas, filasIniciales, comoIniciar, m);
		}

		juego(j);
	}

	return func;
}




