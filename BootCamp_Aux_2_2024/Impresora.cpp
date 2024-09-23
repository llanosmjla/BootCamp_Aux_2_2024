#include <iostream>

using namespace std;


struct Color {
	int rojo, verde, axul;
};


class Marcador {
private:
	string marca;
	float nivelTinta;
	Color color;
public:
	Marcador();
	Marcador(string, float, Color);
	void escribir(int nLetras);
	void imprimir();
	float calcularVidaUtil();
	bool aunSrive();
	void recargar(int recarga);
	string traducirColor();
};

Marcador::Marcador() {
	this->marca = "";
	this->nivelTinta = 0.0f;
	this->color;
}
Marcador::Marcador(string _marca, float _nivelTinta, Color _color) {
	marca = _marca;
	nivelTinta = _nivelTinta;
	color = _color;
}

void Marcador::escribir(int nLetras) {
	float letrasEscritas = nLetras * 0.2f;
	nivelTinta -= letrasEscritas;
	cout << "Tinta sobrante: " << nivelTinta;
}



/*int main() {

	Color color;
	color.axul = 10;
	color.rojo = 10;
	color.verde = 10;

	Marcador marcador("epson", 10, color);
	string letras = "hola";
	//cout << "Numero letras: " << letras.length() << endl;
	marcador.escribir(letras.length());
	return 0;
}*/