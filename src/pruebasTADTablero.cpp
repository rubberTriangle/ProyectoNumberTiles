/*
 * pruebasTADTablero.cpp
 *
 *  Created on: 9 dic 2024
 *      Author: jorge
 */

#include "entorno.h"
#include "TADCasilla.h"
#include "TADTablero.h"
#include "pruebasTADTablero.h"

#include <fstream>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

void mostrarTablero(Tablero t){
	for (int i = 0; i < t.filas; i++){
		cout << "\n";
		for (int j = 0; j < t.columnas; j++){
			cout << obtenerValorTablero(t, i, j) << " ";
		}
	}
	cout << "\n";
}

void pruebaIniciarTableroAleatorio(){

	srand (time(NULL));

	Tablero tablero1;
	Tablero tablero2;
	Tablero tablero3;
	int comoIniciar = 0;
	int m[7][7]{{2,4,8,16,2,4,8},{2,4,8,16,2,4,8}};
	int filas;
	int columnas;
	int filasIniciales = 3;

	mostrarTablero(tablero1);
	cout << "Probando matriz menor: ";
	comoIniciar = 3;
	filas = 3;
	columnas = 3;

	iniciarTablero(tablero1, filas, columnas, filasIniciales, comoIniciar, m);
	mostrarTablero(tablero1);

	cout << "Probando matriz media: ";
	comoIniciar = 0;
	filas = 5;
	columnas = 4;

	iniciarTablero(tablero2, filas, columnas, filasIniciales, comoIniciar, m);
	mostrarTablero(tablero2);

	cout << "Probando matriz mayor: ";
	comoIniciar = 3;
	filas = 7;
	columnas = 7;

	iniciarTablero(tablero3, filas, columnas, filasIniciales, comoIniciar, m);
	mostrarTablero(tablero3);
}

void pruebaPonerValorTablero(){
	Tablero t;
	int comoIniciar = 4;
	int m[7][7];
	int filas = 7;
	int columnas = 5;
	int filasIniciales = 3;



	iniciarTablero(t, filas, columnas, filasIniciales, comoIniciar, m);
	int fila = 0;
	int columna = 0;
	int valor = 8;

	ponerValorTablero(t, fila, columna, valor);

	if (obtenerValorCasilla(t.vector[fila][columna]) != valor){
		cout << "Error el poner valor en el tablero caso 1" << endl;
	}

	fila = 4;
	columna = 3;
	valor = 20;

	ponerValorTablero(t, fila, columna, valor);

	if (obtenerValorCasilla(t.vector[fila][columna]) != valor){
		cout << "Error el poner valor en el tablero caso 2" << endl;
	}

	fila = 7;
	columna = 7;
	valor = 32;

	ponerValorTablero(t, fila, columna, valor);

	if (obtenerValorCasilla(t.vector[fila][columna]) != valor){
		cout << "Error el poner valor en el tablero caso 3" << endl;
	}
}

void pruebaObtenerValorTablero(){

	Tablero t;
	int comoIniciar = 3;
	int m[7][7];
	int filas = 7;
	int columnas = 5;
	int filasIniciales = 3;

	int fila = 0;
	int columna = 0;
	int valor = 8;

	iniciarTablero(t, filas, columnas, filasIniciales, comoIniciar, m);

	ponerValorTablero(t, fila, columna, valor);

	if (obtenerValorTablero(t, fila, columna) != valor){
		cout << "Error al obtener valor en el tablero caso 1" << endl;
	}

	fila = 4;
	columna = 3;
	valor = 20;

	ponerValorTablero(t, fila, columna, valor);

	if (obtenerValorTablero(t, fila, columna) != valor){
		cout << "Error al obtener valor en el tablero caso 2" << endl;
	}

	fila = 7;
	columna = 7;
	valor = 32;

	ponerValorTablero(t, fila, columna, valor);

	if (obtenerValorTablero(t, fila, columna) != valor){
		cout << "Error al obtener valor en el tablero caso 3" << endl;
	}
}

void pruebaEstaVaciaCasillaTablero(){
	Tablero t;
	int comoIniciar = 1;
	int m[7][7];
	int filas = 7;
	int columnas = 5;
	int filasIniciales = 3;

	iniciarTablero(t, filas, columnas, filasIniciales, comoIniciar, m);

	ponerValorTablero(t,0,0,8);
	vaciarCasillaTablero(t,0,0);

	if(!estaVaciaCasillaTablero(t, 0, 0)){
		cout << "Error en ver si esta vacia la casilla en el tablero caso 1" << endl;
	}

	ponerValorTablero(t,4,3,20);
	vaciarCasillaTablero(t,4,3);

	if(!estaVaciaCasillaTablero(t, 4, 2)){
		cout << "Error en ver si esta vacia la casilla en el tablero caso 2" << endl;
	}

	ponerValorTablero(t,7,7,32);
	vaciarCasillaTablero(t,7,7);

		if(!estaVaciaCasillaTablero(t, 7, 7)){
			cout << "Error en ver si esta vacia la casilla en el tablero caso 3" << endl;
		}


}

void pruebaVaciarCasillaTablero(){
	Tablero t;
	int comoIniciar = 1;
	int m[7][7];
	int filas = 7;
	int columnas = 5;
	int filasIniciales = 3;

	iniciarTablero(t, filas, columnas, filasIniciales, comoIniciar, m);

	int fila = 0;
	int columna = 0;
	ponerValorTablero(t,fila,columna,8);
	vaciarCasillaTablero(t, fila, columna);

	if (!estaVaciaCasillaTablero(t, fila, columna)){
		cout << "Error al vaciar casilla del tablero caso 1" << endl;
	}

	fila = 4;
	columna = 3;
	ponerValorTablero(t,fila,columna,20);
	vaciarCasillaTablero(t, fila, columna);

	if (!estaVaciaCasillaTablero(t, fila, columna)){
		cout << "Error al vaciar casilla del tablero caso 2" << endl;
	}

	fila = 7;
	columna = 7;
	ponerValorTablero(t,fila,columna,32);
	vaciarCasillaTablero(t, fila, columna);

	if (!estaVaciaCasillaTablero(t, fila, columna)){
		cout << "Error al vaciar casilla del tablero caso 3" << endl;
	}
}

void pruebaEstaLlenaColumnaTablero(){
	Tablero t;
	int comoIniciar = 1;
	int m[7][7];
	int filas = 7;
	int columnas = 7;
	int filasIniciales = 1;

	iniciarTablero(t, filas, columnas, filasIniciales, comoIniciar, m);

	ponerValorTablero(t, 1, 1, 8);

	if(estaLlenaColumnaTablero(t, 5)){
		cout << "Error en ver si esta llena la columna del tablero caso 1" << endl;
	}

	ponerValorTablero(t, 1, 4, 20);

	if(estaLlenaColumnaTablero(t, 4)){
		cout << "Error en ver si esta llena la columna del tablero caso 2" << endl;
	}

	ponerValorTablero(t, 6, 6, 2);

	//mostrarTablero(t);

	if(!estaLlenaColumnaTablero(t, 6)){
		cout << "Error en ver si esta llena la columna del tablero caso 3" << endl;
	}
}

void pruebaEstaLlenoTablero(){
	Tablero t;
	int comoIniciar = 1;
	int m[7][7];
	int filas = 7;
	int columnas = 5;
	int filasIniciales = 3;

	iniciarTablero(t, filas, columnas, filasIniciales, comoIniciar, m);

	if (estaLlenoTablero(t)){
		cout << "Error en ver si esta lleno tablero caso 1" << endl;
	}

	for (int i = 0; i < obtenerNumFilas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			ponerValorTablero(t, i, j, 2);
		}
	}

	if (!estaLlenoTablero(t)){
		cout << "Error en ver si esta lleno tablero caso 2" << endl;
	}


}

void pruebaObtenerNumFilas(){
	Tablero t1;
	int comoIniciar = 4;
	int m[7][7];
	int filas1 = 1;
	int columnas1 = 1;
	int filasIniciales1 = 3;

	iniciarTablero(t1, filas1, columnas1, filasIniciales1, comoIniciar, m);

	if (obtenerNumFilas(t1) != 1){
		cout << "Error en ver numero de filas caso 1" << endl;
	}

	Tablero t2;
	int n[7][7];
	int filas2 = 3;
	int columnas2 = 4;
	int filasIniciales2 = 3;

	iniciarTablero(t2, filas2, columnas2, filasIniciales2, comoIniciar, n);

	if (obtenerNumFilas(t2) != 3){
		cout << "Error en ver numero de filas caso 2 " << obtenerNumFilas(t2) << endl;
	}

	Tablero t3;
	int l[7][7];
	int filas3 = 7;
	int columnas3 = 7;
	int filasIniciales3 = 3;

	iniciarTablero(t3, filas3, columnas3, filasIniciales3, comoIniciar, l);

	if (obtenerNumFilas(t3) != 7){
		cout << "Error en ver numero de filas caso 3 " << obtenerNumFilas(t2) << endl;
	}

}

void pruebaObtenerNumColumnas(){
	Tablero t1;
	int comoIniciar = 4;
	int m[7][7];
	int filas1 = 1;
	int columnas1 = 1;
	int filasIniciales1 = 3;

	iniciarTablero(t1, filas1, columnas1, filasIniciales1, comoIniciar, m);

	if (obtenerNumColumnas(t1) != 1){
		cout << "Error en ver numero de columnas caso 1" << obtenerNumColumnas(t1) << endl;
	}

	Tablero t2;
	int n[7][7];
	int filas2 = 3;
	int columnas2 = 4;
	int filasIniciales2 = 3;

	iniciarTablero(t2, filas2, columnas2, filasIniciales2, comoIniciar, n);

	if (obtenerNumColumnas(t2) != 4){
		cout << "Error en ver numero de columnas caso 2 " << obtenerNumColumnas(t2) << endl;
	}

	Tablero t3;
	int l[7][7];
	int filas3 = 7;
	int columnas3 = 7;
	int filasIniciales3 = 3;

	iniciarTablero(t3, filas3, columnas3, filasIniciales3, comoIniciar, l);

	if (obtenerNumColumnas(t3) != 7){
		cout << "Error en ver numero de columnas caso 3 " << obtenerNumColumnas(t2) << endl;
	}

}

void pruebaObtenerValorMaximoTablero(){
	Tablero t1;
	int comoIniciar = 4;
	int m[7][7];
	int filas1 = 7;
	int columnas1 = 7;
	int filasIniciales1 = 3;
	int valor;
	int exponente;


	iniciarTablero(t1, filas1, columnas1, filasIniciales1, comoIniciar, m);

	ponerValorTablero(t1, 1, 1, 1024);

	valor = obtenerValorMaximoTablero(t1, exponente);



	if (valor != 1024){
		cout << "Error al obtener valor maximo del tablero caso 1" << endl;
	}

	ponerValorTablero(t1, 3, 4, 2048);

	valor = obtenerValorMaximoTablero(t1, exponente);

	if (valor != 2048){
		cout << "Error al obtener valor maximo del tablero caso 2" << endl;
	}

	ponerValorTablero(t1, 7, 7, 4096);

	valor = obtenerValorMaximoTablero(t1, exponente);

	if (valor != 4096){
		cout << "Error al obtener valor maximo del tablero caso 3" << endl;
	}

}

void pruebaRellenarHuecos(){
    Tablero t1;
    int comoIniciar = 4;
    int m[7][7];
    int filas1 = 7;
    int columnas1 = 7;
    int filasIniciales1 = 3;

    iniciarTablero(t1, filas1, columnas1, filasIniciales1, comoIniciar, m);

    ponerValorTablero(t1,0,0,2);
    ponerValorTablero(t1,1,0,2);
    vaciarCasillaTablero(t1,0,0);
    rellenarHuecos(t1);
    if(estaVaciaCasillaTablero(t1,0,0))
        cout<<"Error al rellenar huecos caso 1"<<endl;


    ponerValorTablero(t1,3,4,2);
    ponerValorTablero(t1,4,4,2);
    vaciarCasillaTablero(t1,3,4);
    rellenarHuecos(t1);
    if(estaVaciaCasillaTablero(t1,0,4))
        cout<<"Error al rellenar huecos caso 2"<<endl;


    ponerValorTablero(t1,6,7,2);
    ponerValorTablero(t1,7,7,2);
    vaciarCasillaTablero(t1,6,7);
    rellenarHuecos(t1);
    if(estaVaciaCasillaTablero(t1,0,7))
        cout<<"Error al rellenar huecos caso 3"<<endl;
}

void pruebaFusionar(){
	Tablero t;
	int comoIniciar = 4;
	int m[7][7];
	int filas = 7;
	int columnas = 7;
	int filasIniciales = 3;

	int puntuacion;
	int fila;

	iniciarTablero(t, filas, columnas, filasIniciales, comoIniciar, m);

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	ponerValorTablero(t, 2, 4, 2);
	ponerValorTablero(t, 2, 2, 2);
	ponerValorTablero(t, 1, 4, 3);
	ponerValorTablero(t, 1, 2, 3);
	ponerValorTablero(t, 0, 4, 3);
	ponerValorTablero(t, 0, 2, 3);
	ponerValorTablero(t, 1, 3, 2);
	ponerValorTablero(t, 0, 3, 2);

	fila = 2;

	//mostrarTablero(t);

	fusionar(t, fila, 3, 2, puntuacion);

	//mostrarTablero(t);

	if (obtenerValorTablero(t, 0, 3) != 32){
		cout << "Error prueba fusionar caso 1 " << "Valor obtenido es: " << obtenerValorTablero(t, 0, 3) <<  endl;
	}

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	//mostrarTablero(t);

	ponerValorTablero(t, 1, 4, 4);
	ponerValorTablero(t, 1, 5, 4);
	ponerValorTablero(t, 1, 2, 4);
	ponerValorTablero(t, 1, 1, 4);
	ponerValorTablero(t, 0, 3, 4);

	fila = 1;

	//mostrarTablero(t);

	fusionar(t, fila, 3, 4, puntuacion);

	//mostrarTablero(t);

	if (obtenerValorTablero(t, 0, 3) != 32){
		cout << "Error prueba fusionar caso 2 " << "Valor obtenido es: " << obtenerValorTablero(t, 0, 3) <<  endl;
	}
}

void pruebaFusionar2(){
	Tablero t;
	int comoIniciar = 4;
	int m[7][7];
	int filas = 7;
	int columnas = 7;
	int filasIniciales = 3;

	int cont = 0;
	int fila;

	iniciarTablero(t, filas, columnas, filasIniciales, comoIniciar, m);

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	ponerValorTablero(t, 2, 4, 2);
	ponerValorTablero(t, 2, 2, 2);
	ponerValorTablero(t, 1, 4, 3);
	ponerValorTablero(t, 1, 2, 3);
	ponerValorTablero(t, 0, 4, 3);
	ponerValorTablero(t, 0, 2, 3);
	ponerValorTablero(t, 1, 3, 2);
	ponerValorTablero(t, 0, 3, 2);

	fila = 2;

	//mostrarTablero(t);

	fusionar2(t, fila, 3, 2, false, false, true, cont);

	//mostrarTablero(t);

	if (cont != 3){
		cout << "Error prueba fusionar2 caso 1 " << "Valor obtenido es: " << cont <<  endl;
	}

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	cont = 0;

	//mostrarTablero(t);

	ponerValorTablero(t, 0, 2, 4);

	fila = 0;

	//mostrarTablero(t);

	fusionar2(t, fila, 3, 4, false, true, false, cont);

	//mostrarTablero(t);

	if (cont != 1){
		cout << "Error prueba fusionar2 caso 2 " << "Valor obtenido es: " << cont <<  endl;
	}

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	cont = 0;

	//mostrarTablero(t);

	ponerValorTablero(t, 0, 4, 4);

	fila = 0;

	//mostrarTablero(t);

	fusionar2(t, fila, 3, 4, true, false, false, cont);

	//mostrarTablero(t);

	if (cont != 1){
		cout << "Error prueba fusionar2 caso 3 " << "Valor obtenido es: " << cont <<  endl;
	}
}

void pruebaPista(){
	Tablero t;
	int comoIniciar = 4;
	int m[7][7];
	int filas = 7;
	int columnas = 5;
	int filasIniciales = 3;

	int columnaPista;

	iniciarTablero(t, filas, columnas, filasIniciales, comoIniciar, m);

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	ponerValorTablero(t, 1, 4, 2);
	ponerValorTablero(t, 1, 2, 2);
	ponerValorTablero(t, 0, 3, 2);

	//mostrarTablero(t);

	columnaPista = pista(t, 2);

	if (columnaPista != 3){
		cout << "Error prueba pista caso 1 " << "Valor obtenido es: " << columnaPista <<  endl;
	}

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	ponerValorTablero(t, 1, 3, 4);
	ponerValorTablero(t, 1, 1, 4);
	ponerValorTablero(t, 0, 2, 4);

	//mostrarTablero(t);

	columnaPista = pista(t, 4);

	if (columnaPista != 2){
		cout << "Error prueba pista caso 2 " << "Valor obtenido es: " << columnaPista <<  endl;
	}

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	ponerValorTablero(t, 1, 2, 4);
	ponerValorTablero(t, 1, 0, 4);
	ponerValorTablero(t, 0, 0, 4);

	//mostrarTablero(t);

	columnaPista = pista(t, 4);

	if (columnaPista != 1){
		cout << "Error prueba pista caso 3 " << "Valor obtenido es: " << columnaPista <<  endl;
	}
}

void pruebaPista2(){
	Tablero t;
	int comoIniciar = 4;
	int m[7][7];
	int filas = 7;
	int columnas = 7;
	int filasIniciales = 3;

	int cont = 0;
	int fila;

	iniciarTablero(t, filas, columnas, filasIniciales, comoIniciar, m);

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	ponerValorTablero(t, 2, 4, 2);
	ponerValorTablero(t, 2, 2, 2);
	ponerValorTablero(t, 1, 4, 3);
	ponerValorTablero(t, 1, 2, 3);
	ponerValorTablero(t, 0, 4, 3);
	ponerValorTablero(t, 0, 2, 3);
	ponerValorTablero(t, 1, 3, 2);
	ponerValorTablero(t, 0, 3, 2);

	fila = 2;

	//mostrarTablero(t);

	pista2(t, fila, 3, 2, false, false, true, cont);

	//mostrarTablero(t);

	if (cont != 3){
		cout << "Error prueba pista2 caso 1 " << "Valor obtenido es: " << cont <<  endl;
	}

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	cont = 0;

	//mostrarTablero(t);

	ponerValorTablero(t, 0, 2, 4);

	fila = 0;

	//mostrarTablero(t);

	pista2(t, fila, 3, 4, false, true, false, cont);

	//mostrarTablero(t);

	if (cont != 1){
		cout << "Error prueba pista2 caso 2 " << "Valor obtenido es: " << cont <<  endl;
	}

	for (int i = 0; i < obtenerNumColumnas(t); i++){
		for (int j = 0; j < obtenerNumColumnas(t); j++){
			vaciarCasillaTablero(t, i, j);
		}
	}

	cont = 0;

	//mostrarTablero(t);

	ponerValorTablero(t, 0, 4, 4);

	fila = 0;

	//mostrarTablero(t);

	pista2(t, fila, 3, 4, true, false, false, cont);

	//mostrarTablero(t);

	if (cont != 1){
		cout << "Error prueba pista2 caso 3 " << "Valor obtenido es: " << cont <<  endl;
	}
}

void iniciarPruebasTablero(){

	cout << "Inicio pruebas Tablero" << endl;

	pruebaIniciarTableroAleatorio();

	pruebaPonerValorTablero();

	pruebaObtenerValorTablero();

	pruebaEstaVaciaCasillaTablero();

	pruebaVaciarCasillaTablero();

	pruebaEstaLlenaColumnaTablero();

	pruebaEstaLlenoTablero();

	pruebaObtenerNumFilas();

	pruebaObtenerNumColumnas();

	pruebaRellenarHuecos();

	pruebaFusionar();

	pruebaFusionar2();

	pruebaPista();

	pruebaPista2();

	cout << "Fin pruebas Tablero" << endl;
}

