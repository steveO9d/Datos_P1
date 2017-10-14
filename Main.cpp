#include"ListaP.h"
#include "Lista2.h"
#include"Pila.h"
#include"Valor.h"

#include<ctime>

int main() {
	srand(time(NULL));
	string* ptr = new string("-1");
	//Lista2<string>* ll = new Lista2<string>();
	ListaP<string>* listap = new ListaP<string>();

	cout << "toString\n" << listap->toStringElementos() << endl;
	
	//para crear un carton por ahora, primero hay que reservar y luego enlazar, ya despues 
	// se usa push down para ingresar las columnas (siempre hacer 5 pushDown para crear carton)
	listap->reservar(ptr);
	listap->enlazar();
	Valor* v;
	v = new Valor("B");
	listap->push_down(v->generarColumna());
	v = new Valor("I");
	listap->push_down(v->generarColumna());
	v = new Valor("N");
	listap->push_down(v->generarColumna());
	v = new Valor("G");
	listap->push_down(v->generarColumna());
	v = new Valor("O");
	listap->push_down(v->generarColumna());
	cout << listap->toString();


	cout << endl << endl;
	system("pause");
	return 0;
}
