#pragma once

#include"Nodo.h"

#include<sstream>
#include<string>
#include<iostream>

using namespace std;

template<class T>
class Lista2 {
	Nodo<T>* primero;
	Nodo<T>* actual;
	Nodo<T>* back; // ultimo de la lista
	int size;

public:
	Lista2();
	int getSize();
	bool esVacia();
	void push_back(T* dato);
	void eliminar(int);
	string toString();
	string toString2();
	string imprime_lista_reverse();
	~Lista2();
};

//--------------------------------------------
template<class T>
Lista2<T>::Lista2() {
	primero = NULL;
	actual = NULL;
	size = 0;
}
//--------------------------------------------
template<class T>
bool Lista2<T>::esVacia() {
	return (primero == NULL);
}
//--------------------------------------------
//Inserta al final
template<class T>
void Lista2<T>::push_back(T* dato) {
	Nodo<T> *nodo = new Nodo<T>(dato);
	Nodo<T> *temp = primero;
	actual = primero;

	if (esVacia()) {
		primero = nodo;
		back = primero;
	}
	else {
		temp = back;
		back->setSig(nodo);
		back = back->getSig();
		back->setPrev(temp);
	}
	size++;
}
//--------------------------------------------
template<class T>
string Lista2<T>::toString() {
	stringstream r;
	actual = primero;
	while (actual) {
		//lista2 imprime elementos string, o en su defecto objetos de 
		//una clase valor que proporciona los string
		//si imprime objetos se descomenta el toString
		r << (*(actual->getElemento())/*->toString()*/);
		if(actual->getSig() != NULL)
		r << ", ";
		actual = actual->getSig();
	}
	return r.str();
}

//--------2
template<class T>
string Lista2<T>::toString2() {

}


//--------------------------------------------
template<class T>
string Lista2<T>::imprime_lista_reverse() {
	stringstream r;
	actual = back;
	r << "Lista al reves: [";
	while (actual) {
		r << (actual->getElemento())/*->toString()*/;
		if (actual->getPrev() != NULL)
			r << ", ";
		actual = actual->getPrev();
	}
	r << "]\n";
	return r.str();
}
//--------------------------------------------
template<class T>
int Lista2<T>::getSize() {
	return size;
}
//--------------------------------------------
template<class T>
Lista2<T>::~Lista2() {
	while (primero) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
	primero = NULL;
	size = 0;
}
//--------------------------------------------
template<class T>
void Lista2<T>::eliminar(int i) {}


/*template<class T>
ostream &operator << (ostream& salida, const ListaP<T>& a) {
salida << a.toString();
return salida;
}*/