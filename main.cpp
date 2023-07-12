#include <iostream>
#include <queue>
#include "Utils.h"
#include <cctype>
using namespace std;

void pasarClienteAtaquilla(queue<int> cola){		

		
}

void run(){
	char dato = 'F';
	Utils util;
	queue<int> colaCedulas;
	while(dato != 'f' || dato != 'F'){
		cout<<"OPCIONES:"<<endl;
		cout<<"---- A: INGRESAR CEDULAS"<<endl;
		cout<<"---- 1: LLAMAR AL SIGUIENTE DE LA COLA EN LA TAQUILLA 1"<<endl;
		cout<<"---- 2: LLAMAR AL SIGUIENTE DE LA COLA EN LA TAQUILLA 2"<<endl;
		cout<<"---- 3: LLAMAR AL SIGUIENTE DE LA COLA EN LA TAQUILLA 3"<<endl;	
		cout<<"---- F: SALIR"<<endl;
		cin>>dato;
		cout<<endl;
		cin.ignore();
		
		if(dato == 'A'){
			colaCedulas = util.ingresarCedulas(colaCedulas);
		}	
		if(dato == '1'){
			cout<<"TAQUILLA 1:"<<endl;
			if(!colaCedulas.empty()){
				colaCedulas = util.pasarClienteAtaquilla(colaCedulas);
			}else{
				cout<<"no hay mas clientes que atender"<<endl;
			}			
		}
		if(dato == '2'){
			cout<<"TAQUILLA 2:"<<endl;
			if(!colaCedulas.empty()){
				colaCedulas = util.pasarClienteAtaquilla(colaCedulas);
			}else{
				cout<<" no hay mas clientes que atender"<<endl;
			}
		}		
		if(dato == '3'){
			cout<<"TAQUILLA 3:"<<endl;
			if(!colaCedulas.empty()){
				colaCedulas = util.pasarClienteAtaquilla(colaCedulas);
			}else{
				cout<<"no hay mas clientes que atender"<<endl;
			}
		}	
		/*
		switch(dato){
			
			case 'A':
				
				break;
			case '1':
				cout<<"Taquilla 1"<<endl;
				util.pasarClienteAtaquilla(colaCedulas);
				break;					
			case '2':
				cout<<"Taquilla 2"<<endl;
				util.pasarClienteAtaquilla(colaCedulas);
				break;					
			case '3':
				cout<<"Taquilla 3"<<endl;
				util.pasarClienteAtaquilla(colaCedulas);
				break;													
		}	
		*/

	}

	int opcion = 1;	

	
}
		
	
		
int main(){
	run();
	return 0;
}
