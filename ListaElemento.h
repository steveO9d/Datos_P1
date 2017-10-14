#pragma once

#include<iostream>
#include<list>
#include<string>

using namespace std;

class ListaElemento {
private:
	list<string>* elemento;
	list <string>::iterator i;
public:
	ListaElemento();
	void elemToString();
	string devolverPrimero();
	//list <string>::iterator devolverPos();
	void insertar(string);
	~ListaElemento();
};

