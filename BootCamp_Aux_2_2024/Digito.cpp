#include "Digito.h"


/*
	Metodos y operacion clave de un unordered_map
	- find(key) : retorna un iterador al elemento con la clave key, si no se encuentra retorna un iterador al final del unordered_map
	- insert(key, value) : inserta un nuevo elemento con la clave key y el valor value
	- erase(key) : elimina el elemento con la clave key
	- clear() : elimina todos los elementos del unordered_map
	- size() : retorna el numero de elementos en el unordered_map
	- empty() : retorna true si el unordered_map esta vacio, de lo contrario retorna false
	- begin() : retorna un iterador al primer elemento del unordered_map si unordered_map {1, uno, 2, dos, 3, tres} retorna un iterador al elemento {1, uno}
	- end() : retorna un iterador al final del unordered_map
	- emplace(key, value) : inserta un nuevo elemento con la clave key y el valor value
	- at(key) : retorna una referencia al valor que corresponde a la clave key
	- operator[key] = value : asigna el valor value a la clave key
	- count(key) : retorna el numero de elementos con la clave key, si no se encuentra retorna 0
	- operator[] : retorna una referencia al valor que corresponde a la clave key
*/

unordered_map<string, int> secuenciaDigitoMap = {
	{"bc", 1},
	{"abdeg", 2},
	{"abcdg", 3},
	{"bcfg", 4},
	{"acdfg", 5},
	{"acdefg", 6},
	{"abc", 7},
	{"abcdefg", 8},
	{"abcdfg", 9},
	{"abcdef", 0}
};

// Constructores
Digito::Digito(){
	this->numDigito = 0;
}

Digito::Digito(int numDigito) : Dibujador() {
	this->numDigito = numDigito;
}

Digito::Digito(char secuenciaDigito[7]) : Dibujador() {
	this->numDigito = aDigito(secuenciaDigito);
}

Digito::Digito(string secuenciaDigito) : Dibujador() {
	this->numDigito = aDigito(secuenciaDigito);
}

// destructores
Digito::~Digito() {}

void Digito::setNumDigito(int numDigito) { this->numDigito = numDigito; }
int Digito::getNumDigito() { return numDigito; }

// Funciones miembro
//-> Funciones para dibujar

void Digito::dibujar() {
	Dibujador::dibujar(numDigito);
}

void Digito::dibujar(int num) {
	Dibujador::dibujar(num);
}

void Digito::dibujar(char secuencia[7]) {
	string secuenciaStr = secuencia;
	dibujar(secuenciaStr);
}

void Digito::dibujar(string secuencia) {
	int num = aDigito(secuencia);
	if (num == -1) {
		cout << "Secuencia invalida" << endl;
		return;
	}
	dibujar(num);
}


//-> Funciones para convertir secuencia a digito
/*
  "bc" -> 1 
  "abged" -> 2
  "abgcd" -> 3
  "fgbc" -> 4
*/

int Digito::aDigito(string secuencia) {

	secuencia = ordenar(secuencia);

	if (!validarSecuencia(secuencia)) {
		//cout << "Secuencia invalida" << endl;
		return -1;
	}
	//cout << "Valor : " << secuenciaDigitoMap[secuencia] << endl;
	return secuenciaDigitoMap[secuencia]; // operator[] retorna una referencia al valor que corresponde a la clave key
}

int Digito::aDigito(char secuencia[7]) {
	string secuenciaStr = secuencia;
	return aDigito(secuenciaStr);
}

//-> Funciones para ordenar
string Digito::ordenar(string secuencia) {
	sort(secuencia.begin(), secuencia.end());
	string secuenciaOrdenada = secuencia;
	return secuenciaOrdenada;
}

//-> Funciones para validar secuencia
bool Digito::validarSecuencia(string secuencia) {
	return secuenciaDigitoMap.find(secuencia) != secuenciaDigitoMap.end();
}