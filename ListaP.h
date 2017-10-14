#pragma once

#include"NodoP.h"

#include<sstream>
#include<string>
#include<iostream>

using namespace std;

//clase que crea los cartones, debe tener 5 listas donde guarde todas las columnas para cada letra (BINGO),
// esto para que antes de crear un carton use el metodo existe y revise que la columna creada no exista ya 
// en la lista. Asi no recorremos carton por carton para verificar si esta repetido
template<class T>
class ListaP {
	T* ele;
	NodoP<T>* primero;
	NodoP<T>* actual;
	NodoP<T>* back; // ultimo de la lista
	int size;
public:
	ListaP();
	int getSize();
	bool esVacia();
	void push_back(T* dato);
	void insertarPrincipio(T* dato);
	void mostrar(T* dato);
	friend ostream& operator << (ostream& sout, ListaP<T>& lis);
	void push_down(T[]);
	void enlazar();
	void reservar(T*);
	string toStringElementos();

	string toString();
	string imprime_lista_reverse();
	~ListaP();
};

// recibe una columna, la ingresa, valor por valor los nodos de la lista, 
// donde corresponda segun la letra
template<class T>
void ListaP<T>::push_down(T dato[]) {
	/****************Metodo a modificar***************
	crear 5 lista2, cada una contiene vectores, una lista con vectores 'A' otra 'B' y asi...
	Antes de hacer esto debe de recorrer la lista de columnas y validar que T dato[] no exista ya,
	si no existe se ingresa a la lista respectiva y despues hace todo lo de abajo
	como la primera pos de cada vector siempre es una letra (BINGO), se puede usar eso para verificar 
   cual lista hay que revisar y a cual lista hay que ingresar el vector
	*/
	int i = 0;
	int cont = 0;
	string* ptr = new string("-1");
	string* p = new string(dato[i]);
	actual = primero;
	if (*p == "B") {
		while (actual) {
			ptr = new string(dato[i++]);
			actual->setElemento(ptr);
			actual = actual->getAbaj();
		}
	}
	else if (*p == "I") {
		while (cont++ < 1)
			actual = actual->getSig();
		while (actual) {
			ptr = new string(dato[i++]);
			actual->setElemento(ptr);
			actual = actual->getAbaj();
		}
	}
	else if (*p == "N") {
		while (cont++ < 2)
			actual = actual->getSig();
		while (actual) {
			ptr = new string(dato[i++]);
			actual->setElemento(ptr);
			actual = actual->getAbaj();
		}
	}
	else if (*p == "G") {
		while (cont++ < 3)
			actual = actual->getSig();
		while (actual) {
			ptr = new string(dato[i++]);
			actual->setElemento(ptr);
			actual = actual->getAbaj();
		}
	}
	else if (*p == "O") {
		while (cont++ < 4)
			actual = actual->getSig();
		while (actual) {
			ptr = new string(dato[i++]);
			actual->setElemento(ptr);
			actual = actual->getAbaj();
		}
	}
}
//--------------------------------------------
// agrega 5 nodos hacia abajo a cada nodo (primero se crea la lista doblemente
// enlazada en push back)
template<class T>
void ListaP<T>::reservar(T* ptr) {
	NodoP<T>* temp;
	for (int i = 0; i < 5; i++) {
		push_back(ptr);
	}
	temp = primero;
	actual = primero;
	while (temp) {
		for (int i = 0; i < 5; i++) {
			temp->setAbaj(new NodoP<T>(ptr));
			temp = temp->getAbaj();
		}
		actual = actual->getSig();
		temp = actual;
	}
}
//--------------------------------------------
template<class T>
ListaP<T>::ListaP() {
	primero = NULL;
	actual = NULL;
	size = 0;
}
//--------------------------------------------
template<class T>
bool ListaP<T>::esVacia() {
	return (primero == NULL);
}
//--------------------------------------------
//Inserta al final, crea una lista doblemente enlazada
template<class T>
void ListaP<T>::push_back(T* dato) {
	NodoP<T> *nodo = new NodoP<T>(dato);
	NodoP<T> *temp = primero;
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
ostream& operator<<  (ostream& os, ListaP<T>& lis)
{
	os << lis->mostrar() << "nn";
	return sout;
}
//--------insertar principio  ----
template <class T>
void ListaP<T>::insertarPrincipio(T* dato) {
	primero = new NodoP<T>(dato);
}
//---------mostrar
template<class T>
void ListaP<T>::mostrar(T* dato) {
	cout << dato << "," << endl;
}
//--------------------------------------------
//imprime con formato de matriz
template<class T>
string ListaP<T>::toString() {
	stringstream r;
	actual = primero;
	NodoP<T>* temp = actual;

	while (temp) {
		r << "{";
		while (actual) {
			r << "     " << (*(actual->getElemento())) << "         ";
			if (actual->getSig() == NULL) {
				r << "}";
				r << "\n";
			}
			actual = actual->getSig();
		}
		r << "\n";
		temp = temp->getAbaj();
		if (temp)
			actual = temp;
	}
	r << endl;
	return r.str();
}
//--------------------------------------------
// de prueba, solo un nodo y sus 5 nodos hacia abajo
template<class T>
string ListaP<T>::toStringElementos() {
	stringstream r;
	NodoP<T>* temp = primero;
	NodoP<T>* arrib = primero;
	actual = primero;
	r << "{\n";
	while (actual) {
		//imprime elementos
		r << "( ";
		r << (*(actual->getElemento()));
		while (temp->getAbaj()) {
			r << ", ";
			r << "*" << (*(temp->getAbaj()->getElemento()));
			arrib = temp; //probar
			temp = temp->getAbaj();
			temp->setArrib(arrib); //probar
		}
		r << " )";
		if (actual->getSig() != NULL)
			r << "->\n";
		actual = actual->getSig();
		temp = actual;
	}
	r << " \n}\n";
	return r.str();
}
//--------------------------------------------
// prueba, imprime lista doblementa enlazada de derecha a iaquierda
template<class T>
string ListaP<T>::imprime_lista_reverse() {
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
int ListaP<T>::getSize() {
	return size;
}
//--------------------------------------------
// enlaza todos los nodos der-izq, izq-der
template<class T>
void ListaP<T>::enlazar() {
	actual = primero;
	NodoP<T>* k = actual;       //apuntador que recorre la lista 
	NodoP<T>* i = k;           //va hacia abajo enlazando a la der
	NodoP<T>* j = k->getSig(); //va hacia abajo enlazando a la izq
	while (k != NULL) {
		while (i != NULL && j != NULL) {
			i->setSig(j);
			j->setPrev(i);
			i = i->getAbaj();
			j = j->getAbaj();
		}
		k = k->getSig(); // me muevo a la segunda pos de la lista
		i = k;
		if (k)
			j = k->getSig();
	}
}
//--------------------------------------------
template<class T>
ListaP<T>::~ListaP() {
	while (primero) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
	primero = NULL;
	size = 0;
}
//--------------------------------------------
