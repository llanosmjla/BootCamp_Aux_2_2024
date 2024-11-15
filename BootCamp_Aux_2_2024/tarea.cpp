
//QUISPE SERRANO CARLA 
//ENLACE DE GIT HUB :
//https://github.com/CarlaQS/Juego-de-Penales.git

#include <iostream>
#include <time.h> 
#include <cstdlib> 
using namespace std;
class Jugador
{
private:
	short posicionTiro;
public:
	int nroGoles;
	Jugador()
	{
		posicionTiro = 0;
		nroGoles = 0;
	}
	void patear()
	{
		// Valida que la posición de tiro sea correcta
		cout << "Introduzca su dirección de Tiro" << endl;
		cin >> posicionTiro;
		if (posicionTiro < 1 || posicionTiro >9)
		{
			cout << "No valido" << endl;
			posicionTiro = 5;
		}
	}
	short getPosicionTiro()
	{
		return posicionTiro;
	}
};

class Arquero
{
private:
	short nroCuadros;
	short posicionTapada;
public:
	float altura;
	short posicionInicial;
	int nroAtajadas;

	Arquero()
	{
		posicionInicial = 8;
		nroAtajadas = 0;
		altura = 1.75;
		posicionTapada = 5;
	}

	Arquero(float alt, int tap)
	{
		//posicionInicial = 8;
		nroAtajadas = 0;
		altura = alt;
		posicionTapada = tap;
	}

	void atajar()
	{
		int random_x;
		//arand (time(NULL));
		random_x = rand() % 9;
		posicionTapada = random_x + 1;
		cout << "Arquero se arrojo a:" << posicionTapada << endl;
	}

	short getPosicionTapada()
	{
		return posicionTapada;
	}

	bool lograAtajar(Jugador j1)
	{
		j1.getPosicionTiro() != posicionTapada;
		return false;
	}

	// dibujar en arco 
	void graficarArcoInicial()
	{
		cout << " --- --- --- " << endl;
		cout << "|           |" << endl;
		cout << "|   ";
		cout << "  x     ";
		cout << "|" << endl;
		cout << "|           |" << endl;
		cout << " --- --- --- " << endl;
	}

	void dibujarTiro(short getPosicionTapada)
	{
		cout << " --- --- --- " << endl;
		switch (getPosicionTapada)
		{
		case 1:cout << "|           |" << endl;
			cout << "|x          |" << endl;
			break;
		case 2:cout << "|           |" << endl;
			cout << "|     x     |" << endl;
			break;
		case 3:cout << "|           |" << endl;
			cout << "|          x|" << endl;
			break;
		case 4:cout << "|           |" << endl;
			cout << "|x          |" << endl;
			break;
		case 5:cout << "|           |" << endl;
			cout << "|     x     |" << endl;
			break;
		case 6:cout << "|           |" << endl;
			cout << "|          x|" << endl;
			break;
		case 7:cout << "|x          |" << endl;
			cout << "|           |" << endl;
			break;
		case 8:cout << "|     x     |" << endl;
			cout << "|           |" << endl;
			break;
		case 9:cout << "|          x|" << endl;
			cout << "|           |" << endl;
			break;
		}
		cout << "|           |" << endl;
		cout << " --- --- --- " << endl;
	}
};

/*int main()
{
	srand(time(0));
	Jugador j1;
	Arquero aq;

	//aq.graficarArcoInicial();
	for (int i = 0; i < 9; i++)
	{
		aq.dibujarTiro(aq.getPosicionTapada());
		j1.patear();
		aq.atajar();
		if (aq.lograAtajar(j1))
		{
			cout << "NO GOL" << endl;
			aq.nroAtajadas++;
		}
		else
		{
			cout << "GOL" << endl;
			j1.nroGoles++;
		}
	}
	cout << "Total de goles : " << j1.nroGoles << endl;
	cout << "Total de atajadas : " << aq.nroAtajadas << endl;

	return 0;
}*/
