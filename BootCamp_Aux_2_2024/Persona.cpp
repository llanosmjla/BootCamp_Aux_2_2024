#include <iostream>
#include <string.h>

using namespace std;

class Persona {
private:
	string nombre;

public:
	Persona(string nombre) {
		this->nombre = nombre;
	}

	void setNombre(string nombre) {
		this->nombre = nombre;
	}

	string getNombre() {
		return nombre;
	}
};

class Estudiante : public Persona {
private:
	string cu;
	float promedio;
	float nota;

public: 
	Estudiante(string nombre, string cu, float promedio, float nota) : Persona(nombre) {
		this->cu = cu;
		this->promedio = promedio;
		this->nota = nota;
	}


	void verInfo() {
		cout << "Nombre: " << Persona::getNombre() << endl;
		cout << "Cu:" << cu << endl;
		cout << "Nota:" << nota << endl;
		cout << "Promedio:" << promedio << endl;
	}
};

class Docente : public Persona {
private:
	string ci;

public:
	Docente(string nombre, string ci) : Persona(nombre) {
		this->ci = ci;
	}

	void verInfo() {
		cout << "Nombre" << Persona::getNombre() << endl;
		cout << "Ci:" << ci << endl;
	}
};


//int main() {
//	Estudiante e1("Juan", "123", 20, 80);
//	e1.verInfo();
//
//	Docente d1("Pedro", "456");
//
//	d1.verInfo();
//	return 0;
//}

