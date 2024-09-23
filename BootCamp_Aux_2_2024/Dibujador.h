#pragma once

#include <iostream>

using namespace std;

class Dibujador
{
public:
	Dibujador();
	~Dibujador();

	virtual void dibujar(int);
};

