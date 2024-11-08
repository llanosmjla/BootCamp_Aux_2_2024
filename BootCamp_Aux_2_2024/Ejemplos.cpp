#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Persona {
public:
	string ci;
	string nombre;
	string apellido;

	Persona() {
		ci = "";
		nombre = "";
		apellido = "";
	}

	Persona(string ci, string nombre, string apellido) {
		this->ci = ci;
		this->nombre = nombre;
		this->apellido = apellido;
	}


	void verInfo() {
		cout << "CI: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Apellido: " << apellido << endl;
	}
};

class Transaccion {
public:
	string nroDeTransaccion; //identificador unico
	string fecha;
	float monto;
	string tipo; //deposito, retiro, transferencia

	Transaccion() {
		nroDeTransaccion = "";
		fecha = "";
		monto = 0;
		tipo = "";
	}

	Transaccion(string nroDeTransaccion, string fecha, float monto, string tipo) {
		this->nroDeTransaccion = nroDeTransaccion;
		this->fecha = fecha;
		this->monto = monto;
		this->tipo = tipo;
	}

	void verInfo() {
		cout << "Nro de Transaccion: " << nroDeTransaccion << endl;
		cout << "Fecha: " << fecha << endl;
		cout << "Monto: " << monto << endl;
		cout << "Tipo: " << tipo << endl;
	}
};


class CuentaBancaria {
public:
	string nroDeCuenta;
	float saldo;
	Persona duenio;
	vector<Transaccion> transacciones;
	
	//Constructores
	CuentaBancaria(string nroDeCuenta, float saldo, Persona duenio, vector<Transaccion> transacciones) {
		this->nroDeCuenta = nroDeCuenta;
		this->saldo = saldo;
		this->duenio = duenio;
		this->transacciones = transacciones;
	}

	//Metodos
	float actualizarSaldo() {
		for (int i = 0; i < transacciones.size(); i++) {
			if (transacciones[i].tipo == "Deposito")
				this->saldo += transacciones[i].monto;
			else if (transacciones[i].tipo == "Retiro")
				this->saldo -= transacciones[i].monto;
		}
		return this->saldo;
	}

	void verInfo() {
		cout << "Nro de Cuenta: " << nroDeCuenta << endl;
		cout << "Saldo: " << saldo << endl;
		duenio.verInfo();
		cout << "------------------------------------" << endl;
		cout << "Transacciones: " << endl;
		cout << "------------------------------------" << endl;
		for (int i = 0; i < transacciones.size(); i++) {
			transacciones[i].verInfo();
			cout << "------------------------------------" << endl;
		}
	}
};

//int main() {
//	
//	vector <Transaccion> transacciones;
//
//	Persona p1("123", "Juan", "Perez");
//	Transaccion t1("1", "01/01/2024", 100, "Deposito");
//	
//	Transaccion t2("2", "02/01/2024", 50, "Retiro");
//
//	transacciones.push_back(t1);
//	transacciones.push_back(t2);
//
//	CuentaBancaria c1("1", 100, p1, transacciones);
//	c1.actualizarSaldo();
//	c1.verInfo();
//
//	return 0;
//}