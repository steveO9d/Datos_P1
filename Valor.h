#pragma once

#include<random>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

//esta clase genera un contenedor con 5 valores unicos dependiendo
//de un rango a definir, posicion[0] siempre es una letra
// cada vector generado aqui le puse de nombre columna jaja :p
class Valor {
private:
	int numero;
	int generarNumero();
	string* vec;
	string valInicial; // B-I-N-G-O
	int limInferior;
	int limSup;
	int cant;
	const int TAM = 6;
public:
	Valor(string);
	string getValor();
	string* generarColumna();
	bool repetido(string*);
	string toString();
	bool existe(string[]);
	~Valor();
};

