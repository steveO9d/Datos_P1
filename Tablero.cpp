#include "Tablero.h"



Tablero::Tablero() {
	carton = new list<ListaElemento*>(5, new ListaElemento());
	it = carton->begin();
	//printf("Se ha creado un tablero de tamano %d", carton->size());
}

//Tablero::Tablero(ListaElemento* nuevoCarton) {
//	carton = nuevo carton;
//}

void Tablero::insertarElementos(ListaElemento* lista) {
	if (devolverPrimerLista()->devolverPrimero() == "vacio |")
		carton->assign(1, lista);
	else
		carton->push_back(lista);
}

void Tablero::cartonToString() {
	it = carton->begin();
	//int cont = 0;
	while (it != carton->end()) {
		//cout << ++cont << " ";
		(*it++)->elemToString();
		cout << endl;
	}
}

void Tablero::imprimirConFormato(ListaElemento* l) {
	list <ListaElemento*>::iterator i = carton->begin();
	//list <string>::iterator j = l->devolverPos();
	while (i != carton->end())
		cout << " ";
}

ListaElemento* Tablero::devolverPrimerLista() {
	it = carton->begin();
	return *it;
}

Tablero::~Tablero() {}
