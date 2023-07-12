#include <queue>
#include <iostream>
#include <string>
#include "Utils.h"

Class UtilColas{
	UtilColas()={};
	Utils utils;
	void ingresarCedulas(){
		string cedula;
		cout<<"Porfavor ingrese su cedula de identidad"<<endl;
		getline(cin,cedula);			
		colaCedulas = utils.agregarCedula(colaCedulas, cedula);
		cin.ignore();		
	}
	
	void pasarClienteAtaquilla(queue<int> cola){
		
		cout<<"la clave del cliente que sigue en la cola virtual es " <<cola.front()<<endl;
		cout<<"el cliente con clave " << cola.front() << " ha sido atendido";
		cola.pop();
		
	}
}