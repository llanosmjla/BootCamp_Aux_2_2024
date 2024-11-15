#include "iostream"

using namespace std;

class NumeroEntero {
public:
    int valor;

    NumeroEntero() {
        valor = 0;
    }

    NumeroEntero(int valor) {
        this->valor = valor;
    }

    void aumentarValor() {
        valor++;
    }

    void imprimirValor() {
        cout << valor << endl;
    }
};

class Fraccion : public NumeroEntero {
public:
    int numerador;
    int denominador;

    Fraccion() {
        numerador = 0;
        denominador = 1;
    }

    Fraccion(int valor, int numerador, int denominador) : NumeroEntero(valor) {
        this->denominador = denominador;
        this->numerador = numerador;
    }

    int calcularMCD(int a, int b) {
        while (b != 0) {
            int residuo = a % b;
            a = b;
            b = residuo;
        }
        return a;
    }

    void simplificar() {
        int mcd = calcularMCD(numerador, denominador);
        numerador /= mcd;
        denominador /= mcd;
    }

    void imprimir() {
        cout << numerador << "/" << denominador << endl;
    }
};

class Calculadora {
public:
    Fraccion resul1;
    Fraccion resul2;
    Fraccion resul3;

    int contador = 0;

    Calculadora() {
        resul1 = Fraccion();
        resul2 = Fraccion();
        resul3 = Fraccion();
    }

    Fraccion operar(Fraccion f1, Fraccion f2, char operador) {
        Fraccion resultado;
        switch (operador) {
        case '+':
            resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
            resultado.denominador = f1.denominador * f2.denominador;
            break;
        case '-':
            resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
            resultado.denominador = f1.denominador * f2.denominador;
            break;
        default:
            cout << "Operador no soportado" << endl;
            break;
        }
        resultado.simplificar();
        guardarEnHistorial(resultado);
        return resultado;
    }

    float operarFloat(Fraccion f1, Fraccion f2, char operador) {
        Fraccion resultado = operar(f1, f2, operador);
        return static_cast<float>(resultado.numerador) / resultado.denominador;
    }

    Fraccion sumar(Fraccion f1, Fraccion f2) {
        return operar(f1, f2, '+');
    }

    Fraccion resta(Fraccion f1, Fraccion f2) {
        return operar(f1, f2, '-');
    }

    void guardarEnHistorial(Fraccion resultado) {
        if (contador == 0) {
            resul1 = resultado;
        }
        else if (contador == 1) {
            resul2 = resultado;
        }
        else if (contador == 2) {
            resul3 = resultado;
        }
        contador = (contador + 1) % 3; // Círculo de 3 resultados.
    }

    void verHistorial() {
        cout << "Historial:" << endl;
        cout << "Resultado 1: "; resul1.imprimir();
        cout << "Resultado 2: "; resul2.imprimir();
        cout << "Resultado 3: "; resul3.imprimir();
    }
};

int main() {
    Calculadora calc;

    Fraccion f1(0, 3, 4);
    Fraccion f2(0, 1, 2);

    Fraccion suma = calc.sumar(f1, f2);
    Fraccion resta = calc.resta(f1, f2);

    calc.verHistorial();

    return 0;
}
