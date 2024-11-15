#include "iostream"
#include "string"
#include "vector"
#include "list"

using namespace std;


enum TipoTransaccion
{
	Deposito,//0
	Retiro,//1
	Transferencia//2
};

struct Fecha {
	int dia;
	int mes;
	int anio;
};

class Transaccion {
public:
	string nroDeTransaccion; //identificador unico
	Fecha fecha;
	float monto;
	TipoTransaccion tipo;

	Transaccion() {
		nroDeTransaccion = "";

		fecha.dia = 0;
		fecha.mes = 0;
		fecha.anio = 0;

		monto = 0;
		tipo = Deposito;
	}

	Transaccion(string nroDeTransaccion, Fecha fecha, float monto, TipoTransaccion tipo) {
		this->nroDeTransaccion = nroDeTransaccion;
		this->fecha = fecha;
		this->monto = monto;
		this->tipo = tipo;
	}

	

	void verInfo() {
		cout << "Nro de Transaccion: " << nroDeTransaccion << endl;
		cout << "Fecha: " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << endl;
		cout << "Monto: " << monto << endl;
		if (tipo == Deposito) {
			cout << "Tipo: Deposito" << endl;
		}
		else if (tipo == Retiro) {
			cout << "Tipo: Retiro" << endl;
		}
		else if (tipo == Transferencia) {
			cout << "Tipo: Transferencia" << endl;
		}
		
	}
};

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


class CuentaBancaria {
public:
	string nroDeCuenta;
	float saldo;
	//vector<Transaccion> transacciones; // historial
	list<Transaccion> transacciones;

	Persona duenio;

	//Constructores
	CuentaBancaria() {
		nroDeCuenta = "";
		saldo = 0;
		transacciones.clear();
		duenio = Persona();
	}

	CuentaBancaria(string nroDeCuenta, float saldo, Persona duenio){
		this->nroDeCuenta = nroDeCuenta;
		this->saldo = saldo;
		this->duenio = duenio;
	}

	CuentaBancaria(string nroDeCuenta, float saldo, Persona duenio, list<Transaccion> transacciones) {
		this->nroDeCuenta = nroDeCuenta;
		this->saldo = saldo;
		this->duenio = duenio;
		this->transacciones = transacciones;
	}

	//Metodos
	float actualizarSaldo() {

		for (Transaccion i : transacciones) {
			if (i.tipo == Deposito) {
				saldo += i.monto;
			}
			else if (i.tipo == Retiro) {
				saldo -= i.monto;
			}
			else if (i.tipo == Transferencia) {
				saldo -= i.monto;
			}
		}
		/*for (int i = 0; i < transacciones.size(); i++) {
			if (transacciones[i].tipo == Deposito)
				this->saldo += transacciones[i].monto;
			else if (transacciones[i].tipo == Retiro)
				this->saldo -= transacciones[i].monto;
		}*/
		return this->saldo;
	}

	void verInfo() {
		cout << "Nro de Cuenta: " << nroDeCuenta << endl;
		cout << "Saldo: " << saldo << endl;
		cout << "------------------------------------" << endl;
		cout << "Transacciones: " << endl;
		cout << "------------------------------------" << endl;
		for (Transaccion i : transacciones) {
			i.verInfo();
			cout << "------------------------------------" << endl;
		}
	}

	void verTransaccionesMes(int mes) {
		for (Transaccion i : transacciones) {
			if (i.fecha.mes == mes) {
				i.verInfo();
			}
		}
	}
};

int main() {
	Persona p1("1", "Juan", "Perez");

	list <Transaccion> transacciones;

	Fecha f1{ 1, 1, 2024 };
	Fecha f2{ 2, 2, 2024 };
	Fecha f3{ 3, 23, 2024 };

	Transaccion t1("1", f1, 100, Deposito);
	Transaccion t2("2", f2, 200, Deposito);
	Transaccion t3("2", f2, 50, Retiro);

	

	transacciones.push_back(t1);
	transacciones.push_back(t2);
	transacciones.push_back(t3);

	CuentaBancaria c1("1", 100, p1);

	c1.transacciones = transacciones;

	//c1.verInfo();
	c1.verTransaccionesMes(2);
	return 0;
}