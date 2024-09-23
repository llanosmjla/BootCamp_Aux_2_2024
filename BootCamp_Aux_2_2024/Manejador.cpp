#include "Manejador.h"


Manejador::Manejador() {
	this->numeroActual = 0;
	this->digito = new Digito();
}

Manejador::Manejador(int num) {
	this->numeroActual = num;
}

Manejador::~Manejador() {
}

// siguiente : aumenta el numero actual en 1

void Manejador::siguiente(int num) {
	this->numeroActual = num + 1;
	this->digito->dibujar(this->numeroActual);
}


void Manejador::setNumeroActual(int num) {
	this->numeroActual = num;
}

int Manejador::getNumeroActual() {
	return this->numeroActual;
}

