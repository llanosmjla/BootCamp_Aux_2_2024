#pragma once

#include "Dibujador.h"
#include <algorithm>
#include <unordered_map>

class Digito : public Dibujador {
private:
	int numDigito;
public:
	Digito();
	Digito(int);
	Digito(char[7]);
	Digito(string);
	~Digito();

	void dibujar();
	void dibujar(int);
	void dibujar(char[7]);
	void dibujar(string);

	int aDigito(string);
	int aDigito(char[7]);

	string ordenar(string);
	bool validarSecuencia(string);



	void setNumDigito(int);
	int getNumDigito();

	void setSecuenciaDigito(char[7]);
	char* getSecuenciaDigito();
};

