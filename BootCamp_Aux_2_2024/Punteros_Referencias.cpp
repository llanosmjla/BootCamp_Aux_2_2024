#include <iostream>
using namespace std;


int main() {


	//Referencia & es una operador de referencia o direccion 
	/*int variable1 = 10;
	int variable2 = 100;
	int& ref = variable1; // ref es un alias de variable - alias
	cout << "Referencia o alias a la 'variable' : " << ref <<endl;
	cout << "Direccion de memoria de la 'variable 1' : " << &ref <<endl;
	cout << "Direccion de memoria de la 'variable 2' : " << &variable2 <<endl;
	ref = 30;     // Cambia el valor de x a trav�s de la referencia
	variable1 = 200;
	cout << "Variable vale ahora : " << variable1 << std::endl; // Imprime 30
	cout << "Variable ref : " << ref <<endl;

	int variable3 = 50;
	//No podemos Cambiar o asiganar una referencia
	ref = variable3;
	cout << "------------------------------"<<endl;
	cout << "Variable 1: " << variable1 <<endl;// 50
	cout << "Variable 3: " << variable3 <<endl;// 50
	cout << "------------------------------"<<endl;*/


	//Punteros
	cout << "------------------------------" << endl;
	cout << "Puntero a Varibale 2" << endl;
	cout << "------------------------------" << endl;
	int variable2 = 20;
	//int& ref2 = variable2;

	//Hay dos maneras de crear un puntero
	// 1. El puntero puede apuntar a una variable que esta en el heap o en el monton

	//int* puntero = new int(); // creamos un puntero que apunta a un espacio de memoria en el heap, para este caso es necesario el operador new y delete

	// 2. El puntero puede apuntar a una variable que esta en el stack o en la pila
	int* puntero = &variable2; // puntero apunta a la direcci�n de variable que esta en el stack, para este caso no es necesario el operador new y delete


	cout << "Variable 2: " << variable2 << std::endl; // Imprime 20
	cout << "Puntero puntero a Variable 2, Direccion de Memeoria: " << puntero << endl;
	*puntero = 30;     // Cambia el valor de variable a trav�s del puntero desreferenciacion *(nombrePuntero)
	cout << "Variable 2: " << variable2 << std::endl; // Imprime 30
	cout << "Puntero a Varibale 2, Valor : " << *puntero << endl;

	cout << "------------------------------" << endl;
	cout << "Puntero a Varibale 4" << endl;
	cout << "------------------------------" << endl;

	int variable4 = 80;
	//puntero = new int(30);
	puntero = &variable4;

	cout << "Puntero a Varibale 4, Valor : " << *puntero << endl;
	cout << "Puntero A Variable 4, Direccion de Memeoria : " << puntero << endl;

	//delete puntero;//Elimianr puntero*/







	return 0;
}

