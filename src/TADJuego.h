/*
 * TADJuego.h
 *
 *  Created on: 18 dic 2024
 *      Author: jorge
 */

#ifndef TADJUEGO_H_
#define TADJUEGO_H_

#include "TADCasilla.h"
#include "TADTablero.h"

struct Juego{
	Tablero tablero;

	int puntuacion;
};



bool iniciar(Juego j);

#endif /* TADJUEGO_H_ */
