#pragma once

#include"ListaElemento.h"

class Tablero{
private:
	list<ListaElemento*>* carton;
	list <ListaElemento*>::iterator it;
public:
	Tablero();
	//Tablero(ListaElemento*);
	void insertarElementos(ListaElemento*);
	ListaElemento* devolverPrimerLista();
	void cartonToString();
	void imprimirConFormato(ListaElemento* l);
	~Tablero();
};

