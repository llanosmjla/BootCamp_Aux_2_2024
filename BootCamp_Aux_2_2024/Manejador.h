#pragma once

#include "Digito.h"

class Manejador
{
private:
	int numeroActual;
	Digito* digito;
public:
	Manejador();
	Manejador(int);
	~Manejador();

	void setNumeroActual(int);
	int getNumeroActual();

	void siguiente(int);
	void anterior(int);
	void reset();

};

