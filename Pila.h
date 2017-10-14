#pragma once

#include<iostream>
#include<vector>

using namespace std;

template <class T>
class Pila {
private:	int limite; //ubicacion elemento superior

	int nElementos;
	T* vec;
public:
	Pila<T>(int nelem = 10);
	T& top();
	bool push(const T&);
	bool pop(T& valorExtraido);
	bool empty();
	bool full();

	string toString();

	~Pila();
};

template<class T>
Pila<T>::Pila(int nelem) {
	vec = new T[nelem];
	nElementos = nelem;
	limite = -1;
}

template<class T>
T& Pila<T>::top() {
	if (!empty())
		return vec[limite];
}

template<class T>
bool Pila<T>::push(const T& valorInsertado) {
	if (!full()) {
		vec[++limite] = valorInsertado;
		return true;
	}
	else
		return false;
}

template<class T>
bool Pila<T>::pop(T& valorExtraido) {
	if (!empty()) {
		//la sig asignacion cambia el valor de T&
		valorExtraido = vec[limite--];
		nElementos--;
		return true;
	}
	return false;
}

template<class T>
bool Pila<T>::empty() {
	return limite == -1;
}

template<class T>
bool Pila<T>::full() {
	return limite == (nElementos - 1);
}

template<class T>
string Pila<T>::toString() {
	stringstream r;
	for (int i = 0; i < nElementos; i++)
		r << vec[i] << "\n";
	return r.str();
}

template<class T>
Pila<T>::~Pila() { delete[]vec; }
