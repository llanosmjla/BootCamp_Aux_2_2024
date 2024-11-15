#include "iostream"
#include "vector"
#include "string"
//#include <algorithm>

using namespace std;

class Parada {
	public:
	string nombre;
	float latitud;
	float longitud;

	Parada() {
		nombre = "";
		latitud = 0;
		longitud = 0;
	}

	Parada(string nombre, float latitud, float longitud) {
		this->nombre = nombre;
		this->latitud = latitud;
		this->longitud = longitud;
	}
};

class Bus {
public:
	int numeroAsientos;
	int numeroPasajeros;
	vector<Parada*> paradas; //[1, 2, 3, 4] = 4  begin = 1 , end = 4, 

	//Constructor 
	Bus() {
		numeroAsientos = 0;	
		numeroPasajeros = 0;
		paradas.clear();
	}

	Bus(int numeroAsientos, int numeroPasajeros, vector<Parada*> paradas) {
		this->numeroAsientos = numeroAsientos;
		this->numeroPasajeros = numeroPasajeros;
		this->paradas = paradas;
	}

	//metodos 
	void iniciar() {
		numeroPasajeros = 0;
		paradas.clear();// borra todos los elementos del vector
	}

	void siguienteParada() {
		if (paradas.size() > 0) {
			paradas.erase(paradas.begin()); // erase eliminar un elmento del vector
		}
		else {
			cout << "No hay mas paradas" << endl;
		}
	}

	void enParada(int pasajerosSuben, int pasajerosBajan) {
		int pasajerosEnParada = numeroPasajeros + pasajerosSuben - pasajerosBajan;

		if (pasajerosEnParada <= numeroAsientos) {
			numeroPasajeros += pasajerosSuben - pasajerosBajan;
			cout << "Pasajeros subidos: " << pasajerosSuben << endl;
			cout << "Pasajeros bajados: " << pasajerosBajan << endl;
			cout << "Parada: " << paradas[0]->nombre << endl;
		}
		else {
			cout << "No se puede subir esa cantidad de pasajeros" << endl;
		}
	}

	void verInfo() {
		cout << "Numero de Asientos: " << numeroAsientos << endl;
		cout << "Numero de Pasajeros: " << numeroPasajeros << endl;
		cout << "Numero de Asientos Libres: " << numeroAsientos - numeroPasajeros << endl;
		cout << "Paradas restantes: " << endl;
		for (int i = 0; i < paradas.size(); i++) {
			cout << paradas[i]->nombre << endl;
		}
	}
};


/*int main() {
	/*vector <Parada*> paradas;
	paradas.push_back(new Parada("Parada A", 0, 0));
	paradas.push_back(new Parada("Parada B", 0, 0));
	paradas.push_back(new Parada("Parada C", 0, 0));
	paradas.push_back(new Parada("Parada D", 0, 0));
	paradas.push_back(new Parada("Parada E", 0, 0));

	Bus bus1(20, 0, paradas);

	bus1.enParada(5, 0); // en la parada A

	bus1.siguienteParada(); // eliminando la parada A y Parada B queda como la primera parada en la lista 

	bus1.enParada(0, 2); // en la paradas B

	bus1.siguienteParada(); // eliminando la parada B y Parada C queda como la primera parada en la lista

	bus1.enParada(0, 0); // en la paradas C

	bus1.verInfo();

	vector <int> numeros;

	numeros.push_back(1); // 0
	numeros.push_back(2); // 1
	numeros.push_back(3); // 2
	numeros.push_back(4); // 4
	numeros.push_back(5); // 5
	numeros.push_back(6); // 6

	cout << "La primera elemento del vector: " << numeros.front() << endl;
	//auto elementoAEliminar = find(numeros.begin(), numeros.end(), 3);
	//numeros.erase(elementoAEliminar);


	cout << "Capacidad del vector: " << numeros.capacity() << endl;

	int numeroAElimianr = 4;

	for (auto i = numeros.begin(); i != numeros.end(); i++) {
		if (*i == numeroAElimianr) {
			numeros.erase(i);
			break;
		}
	}

	cout << "-------------------" << endl;

	if (numeros.empty()) {
		cout << "El vector esta vacio" << endl;
	}
	else {
		for (int numero : numeros) {
			cout << numero << endl;
		}
	}
	


	/*
	cout << "-------------------" << endl;
	numeros.pop_back();

	for (int numero : numeros) {
		cout << numero << endl;
	}

	return 0;
}*/