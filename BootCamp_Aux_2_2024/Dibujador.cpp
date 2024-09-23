#include "Dibujador.h"

Dibujador::Dibujador() {
}

Dibujador::~Dibujador() {
}

void Dibujador::dibujar(int num) {
	switch (num) {
	case 0:
		cout << " _ " << endl;
		cout << "| |" << endl;
		cout << "   " << endl;
		cout << "| |" << endl;
		cout << " _ " << endl;
		break;
	case 1: 
		cout << " | " << endl;
		cout << "  " << endl;
		cout << " | " << endl;
		break;
	case 2: 
		cout << " _" << endl;
		cout << "  |" << endl;
		cout << " _" << endl;
		cout << "|" << endl;
		cout << " _" << endl;
		break;
	case 3:
		cout << " _" << endl;
		cout << "  |" << endl;
		cout << " _" << endl;
		cout << "  |" << endl;
		cout << " _" << endl;
		break;
	case 4:
		cout << "   " << endl;
		cout << "| |" << endl;
		cout << " _ " << endl;
		cout << "  |" << endl;
		cout << "   " << endl;
		break;
	case 5:
		cout << " _ " << endl;
		cout << "|  " << endl;
		cout << " _ " << endl;
		cout << "  |" << endl;
		cout << " _ " << endl;
		break;
	case 6:
		cout << " _ " << endl;
		cout << "|  " << endl;
		cout << " _ " << endl;
		cout << "| |" << endl;
		cout << " _ " << endl;
		break;
	case 7:
		cout << " _ " << endl;
		cout << "   |" << endl;
		cout << "   " << endl;
		cout << "   |" << endl;
		cout << "   " << endl;
		break;
	case 8:
		cout << " _ " << endl;
		cout << "| |" << endl;
		cout << " _ " << endl;
		cout << "| |" << endl;
		cout << " _ " << endl;
		break;
	case 9:
		cout << " _ " << endl;
		cout << "| |" << endl;
		cout << " _ " << endl;
		cout << "  |" << endl;
		cout << " _ " << endl;
		break;

	default:
		cout << "Numero invalido-" << endl;
		break;

	}
}