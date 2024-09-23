#include <iostream>
#include <string.h>

using namespace std;

struct Fecha {
	int dia;
	int mes;
	int anio;
};

class Persona {
private:
	int ci;
	Fecha fechaNacimiento;
public:
	//constructores
	Persona() {
		
	};
	
	// parametros
	string nombre;
	string apellido;

	//metodos

	int calcularEdad() {
		int edad = 2024 - fechaNacimiento.anio;
		return edad;
	}

	string obtenerNombreCompleto() {
		//strcat
		string nombreCompleto = nombre +" "+ apellido;
		return nombreCompleto;
	}


	//setter y getters 
	void setCi(int ci) {
		this->ci = ci;
	}

	int getCi() {
		return ci;
	}

	void setFechaNacimiento(Fecha fn) {
		this->fechaNacimiento = fn;
	}
	Fecha getFechaNacimiento() {
		return fechaNacimiento;
	}


};

enum Tipo {
	cajaAhorro,
	plazoFijo,
	empresarial
};

class Banco {
private:
	string nombre;
public:
	string direccion;

	Banco(){}

	void verInfo() {
		cout << "Nombre: " << nombre << endl;
		cout << "Direccion" << direccion << endl;
	}

	// setter y getters 
};

class Cuenta {

private :
	Persona duenio;
	float saldo;
public:
	Tipo tipoCuenta;
	Banco entidad;

//metodos
	void verInfo() {
		entidad.verInfo(); // nombre y direccion del banco
		//string nombreCompleto = duenio.obtenerNombreCompleto(); // nombre completo de la persona 
		cout << "Nombre Persona: " << duenio.obtenerNombreCompleto() << endl;
		//cout << "Nombre Persona: " << nombreCompleto << endl;
		cout << "Saldo: " << this->saldo;
	}
};

/*int main() {

	Persona persona;

	persona.nombre = "Jose";
	persona.apellido = "Llanos";

	cout << persona.obtenerNombreCompleto() << endl;

	return 0;

}*/