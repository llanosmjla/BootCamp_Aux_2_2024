#include "iostream"
#include "vector"
#include "list"
#include "string"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;


struct Posicion
{
	int x, y;
};

enum Direccion
{
	Arriba,
	Abajo,
	Derecha,
	Izquierda
};

class Abstract {
public:
	Posicion posicion;

	Abstract() {
		posicion.x = 0;
		posicion.y = 0;
	}

	void dibujarse() {
		cout << "Dibujando en " << posicion.x << " " << posicion.y << endl;
	}
};



class Pacman : public Abstract {
public:
	float velocidad;
	//Posicion posicion;
	bool esVulnerable;
	float puntos;
	Direccion dir;

	Pacman() {
		velocidad = 0;
		posicion.x = 0;
		posicion.y = 0;
		esVulnerable = false;
		puntos = 0;
		dir = Arriba;
	}

	Pacman(float velocidad, Posicion posicion, bool esVulnerable, float puntos, Direccion dir) {
		this->velocidad = velocidad;
		this->posicion = posicion;
		this->esVulnerable = esVulnerable;
		this->puntos = puntos;
		this->dir = dir;
	}

	void mover() {
		if (dir == Arriba) {
			posicion.y += velocidad;
		}
		else if (dir == Abajo) {
			posicion.y -= velocidad;
		}
		else if (dir == Derecha) {
			posicion.x += velocidad;
		}
		else if (dir == Izquierda) {
			posicion.x -= velocidad;
		}
	}

	template <class T> 
	void chocar(T &objeto) { // class Dulce o fantastma
		if (this->posicion == objeto->posicion) {
			cout << "hubo choque" << endl;
		}
	}


};

enum TipoDulce {
	Puntaje,
	Inmunidad
};

class Dulce : public Abstract {
public:
	Posicion posicion;
	float tiempoDuracion;
	bool esVisible;
	TipoDulce tipoDulce;

	Dulce() {
		posicion.x = 0;
		posicion.y = 0;
		tiempoDuracion = 0;
		esVisible = false;
		tipoDulce = Puntaje;
	}

	Dulce(Posicion posicion, float tiempoDuracion, bool esVisible, TipoDulce tipoDulce) {
		this->posicion = posicion;
		this->tiempoDuracion = tiempoDuracion;
		this->esVisible = esVisible;
		this->tipoDulce = tipoDulce;
	}

	void desaparecer() {
		esVisible = false;
	}

	void aparecer(float ancho, float alto) {
		esVisible = true;
		int x = 0;
		int y = 0;
		while (true) {
			x = rand() % 10;
			y = rand() % 10;

			if (x < ancho && y < alto) {
				posicion.x = x;
				posicion.y = y;
				break;
			}
		}
	}
};

class Fantasma : public Abstract {
public: 
	Posicion posicion;
	vector<Posicion> puntos;
	int posicionPuntoActual;
	float velocidad;
};

class GameManager {

public:
	Pacman player;
	list<Fantasma> enemigos;
	list<Dulce> dulces;

	GameManager() {
		player = Pacman();
		enemigos.clear();
		dulces.clear();
	}

	GameManager(Pacman player, list<Fantasma> enemigos, list<Dulce> dulces) {
		this->player = player;
		this->enemigos = enemigos;
		this->dulces = dulces;
	}

	void crearDulces(Posicion posicion, float ancho, float largo){
		int contadorDulces = 0;
		for (auto dulce = dulces.begin(); dulce != dulces.end(); dulce++) {
			contadorDulces++;
			if (contadorDulces == 1) {
				dulce->posicion.x = 0;
				dulce->posicion.y = 0;
				dulce->dibujarse();
			}
			else {
				if (contadorDulces == 2) {
					dulce->posicion.x = ancho;
					dulce->posicion.y = 0;
					dulce->dibujarse();
				}
				else {
					if (contadorDulces == 3) {
						dulce->posicion.x = 0;
						dulce->posicion.y = largo;
						dulce->dibujarse();
					}
					else {
						if (contadorDulces == 4) {
							dulce->posicion.x = ancho;
							dulce->posicion.y = largo;
							dulce->dibujarse();
						}
					}
				}
			}
		}

		for (auto dulce : dulces) {

		}
	}

	void crearEnemigos(Posicion posicion, int cant, string tipoDistribucion) {

	}
	void asignarVelocidad(float vel){
		

	}
	
	void detenerFantasmas() {
		for (Fantasma i : enemigos) {
			i.velocidad = 0;
		}
	}

	void renderizar() {
		player.dibujarse(); // aqui se dibuja pacma 
		for (Fantasma i : enemigos) {
			i.dibujarse(); // dibujando los fantasmaas 
			i.posicionPuntoActual = 2;
		}
		for (Dulce i : dulces) {
			i.dibujarse(); // dibujando los dulces
			i.esVisible = false;
		}
	}
};



int main() {

	srand(time(NULL));

	int v1 = rand() % 100; // 0 - 99

	Pacman pacman;
	Dulce dulce;
	Fantasma fantasma;

	pacman.chocar<Dulce>(dulce);
	pacman.chocar<Fantasma>(fantasma);

	return 0;
}