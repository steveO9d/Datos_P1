#include "ListaElemento.h"

ListaElemento::ListaElemento() {
	elemento = new list<string>(6, "vacio |");
	i = elemento->begin();
	//cout << "Se ha creado una lista de elementos de tamano " << elemento->size() << endl;
}

void ListaElemento::elemToString() {
	i = elemento->begin();
	while (i != elemento->end())
		cout << *i++ << " ";
	cout << endl;
}

void ListaElemento::insertar(string e) {
	if (devolverPrimero() == "vacio |")
		elemento->assign(1, e);
	else
		elemento->push_back(e);
}

string ListaElemento::devolverPrimero() {
	i = elemento->begin();
	return *i;
}


ListaElemento::~ListaElemento() {}

/*Notas:
insert agrega a la lista (pos, elemento), añade uno mas a la lista
assign remueve todos y agrega elemento #(veces) assign(#, elemento)
*/