#pragma once

#include <iostream>
#include<string>

using namespace std;

template<class T>
class NodoP {
	NodoP<T>*prev;
	NodoP<T>*arrib;
	NodoP<T>*abaj;
public:
	T* elemento;
	NodoP<T>*sig;
	NodoP(T* dato);
	NodoP<T>* getSig();
	NodoP<T>* getPrev();
	NodoP<T>* getArrib();
	NodoP<T>* getAbaj();
	T* getElemento();
	void setSig(NodoP<T> *elemento);
	void setPrev(NodoP<T> *elemento);
	void setAbaj(NodoP<T> *elemento);
	void setArrib(NodoP<T> *elemento);

	void setElemento(T* dato);
};

//---------------------------------------------------------
template<class T>
NodoP<T>::NodoP(T* elemento) {
	this->elemento = elemento;
	sig = NULL;
	prev = NULL;
	arrib = NULL;
	abaj = NULL;
}

template<class T>
void NodoP<T>::setElemento(T* dato) {
	elemento = dato;
}
//-----------------------------------------------------------
template<class T>
T* NodoP<T>::getElemento() {
	return elemento;
}
//-----------------------------------------------------------
template<class T>
NodoP<T>*  NodoP<T>::getSig() {
	return sig;
}
//-----------------------------------------------------------
template<class T>
NodoP<T>* NodoP<T>::getPrev() {
	return prev;
}
//-----------------------------------------------------------
template<class T>
NodoP<T>* NodoP<T>::getArrib() {
	return arrib;
}
//-----------------------------------------------------------
template<class T>
NodoP<T>* NodoP<T>::getAbaj() {
	return abaj;
}
//-----------------------------------------------------------
template<class T>
void NodoP<T>::setSig(NodoP<T> *elemento) {
	sig = elemento;
}
//-----------------------------------------------------------
template<class T>
void NodoP<T>::setArrib(NodoP<T> *elemento) {
	arrib = elemento;
}
//-----------------------------------------------------------
template<class T>
void NodoP<T>::setAbaj(NodoP<T> *elemento) {
	this->abaj = elemento;
}
//-----------------------------------------------------------
template<class T>
void NodoP<T>::setPrev(NodoP<T> *elemento) {
	prev = elemento;
};
