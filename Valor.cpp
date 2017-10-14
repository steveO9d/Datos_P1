#include "Valor.h"


// se recibe un string para crear el vector, el string es B || I || N || G || O
Valor::Valor(string val) {
	valInicial = val;
	numero = 0;
	vec = new string[TAM];
	if (valInicial == "B") {
		limInferior = 1;
		limSup = 15;
	}
	else if (valInicial == "I") {
		limInferior = 16;
		limSup = 30;
	}
	else if (valInicial == "N") {
		limInferior = 31;
		limSup = 45;
	}
	else if (valInicial == "G") {
		limInferior = 46;
		limSup = 60;
	}
	else if (valInicial == "O") {
		limInferior = 61;
		limSup = 75;
	}
	vec[0] = val; // pone la primera letra B-I-N-G-O
	for (int i = 1; i < TAM; i++) {
		vec[i] = "0";
	}
	cant = 1;
}


//genera numeros aleatorios de 1 hasta limiteSup
int Valor::generarNumero() {
	random_device rd;
	mt19937 num(rd());
	uniform_int_distribution<> rango(limInferior, limSup);
	return rango(num);
}

//pasa de int a string
string Valor::getValor() {
	stringstream ss;
	numero = generarNumero();
	ss << numero;
	return ss.str();
}

//si el numero getValor esta en el vector, false
bool Valor::repetido(string* num) {
	for (int i = 1; i < TAM; i++) {
		if (vec[i] == *num) {
			return true;
			break;
		}
	}
	return false;
}

//verifica que no exista otra columna igual
bool Valor::existe(string temp[]) { 
	int i, j;
	for (i = 0; i < cant; i++) {
		for (j = 0; j < cant; j++) {
			if (vec[i] != temp[j] && i == j) 
				return false;
		}
	}
	return true; 
}

// crea una columna y la devuelve en un vector
string* Valor::generarColumna() {
	string* aux;
	do {
		aux = new string(getValor());
		if (!repetido(aux)) {
			vec[cant++] = *aux;
		}
	} while (cant < TAM);
	return vec;
}

// prueba, imprime elementos de la columna generada
string Valor::toString() {
	stringstream r;
	if (cant == 6) {
		r << "--------------------\n{";
		for (int i = 0; i < cant; i++) {
			r << vec[i];
			if (i < cant - 1)
				r << ", ";
		}
		r << "}\n";
	}
	else
		r << "----- vacio -----\n";
	return r.str();
}


Valor::~Valor() {}
