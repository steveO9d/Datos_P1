#pragma once;

#include <iostream>
#include<string>

using namespace std;

template<class T>
class Nodo {
	T* elemento;
	Nodo<T>*sig;
	Nodo<T>*prev;
	Nodo<T>*arrib;
	Nodo<T>*abaj;
public:
	Nodo(T* dato);
	Nodo<T>* getSig();
	Nodo<T>* getPrev();
	Nodo<T>* getArrib();
	Nodo<T>* getAbaj();
	T* getElemento();
	void setSig(Nodo<T> *elemento);
	void setPrev(Nodo<T> *elemento);
	void setAbaj(Nodo<T> *elemento);
	void setArrib(Nodo<T> *elemento);
};

//---------------------------------------------------------
template<class T>
Nodo<T>::Nodo(T* elemento) {
	this->elemento = elemento;
	sig = NULL;
	prev = NULL;
	arrib = NULL;
	abaj = NULL;
}
//-----------------------------------------------------------
template<class T>
T* Nodo<T>::getElemento() {
	return elemento;
}
//-----------------------------------------------------------
template<class T>
Nodo<T>*  Nodo<T>::getSig() {
	return sig;
}
//-----------------------------------------------------------
template<class T>
Nodo<T>* Nodo<T>::getPrev() {
	return prev;
}
//-----------------------------------------------------------
template<class T>
Nodo<T>* Nodo<T>::getArrib() {
	return arrib;
}
//-----------------------------------------------------------
template<class T>
Nodo<T>* Nodo<T>::getAbaj() {
	return abaj;
}
//-----------------------------------------------------------
template<class T>
void Nodo<T>::setSig(Nodo<T> *elemento) {
	sig = elemento;
}
//-----------------------------------------------------------
template<class T>
void Nodo<T>::setArrib(Nodo<T> *elemento) {
	arrib = elemento;
}
//-----------------------------------------------------------
template<class T>
void Nodo<T>::setAbaj(Nodo<T> *elemento) {
	abaj = elemento;
}
//-----------------------------------------------------------
template<class T>
void Nodo<T>::setPrev(Nodo<T> *elemento) {
	prev = elemento;
}