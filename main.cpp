#include <iostream>
#include <queue>
#include "Utils.h"
using namespace std;
void run(){
	Utils utils;
	queue<int> colaCedulas;
	int opcion = 1;	
	
	while(opcion==1){
		string cedula;
		cout<<"Porfavor ingrese su cedula de identidad"<<endl;
		getline(cin,cedula);	
		do{			
			cout<<"quiere ingresar otra cedula?"<<endl;
			cout<<"1-si"<<endl;
			cout<<"2-no"<<endl;			
			cin>>opcion;
			if(opcion>2){
				cout<<"no ingresaste una opcion valida, intenta de nuevo"<<endl;
				cout<<endl;
			}	
		}
		while(opcion>2);
		
		colaCedulas = utils.agregarCedula(colaCedulas, cedula);
		cin.ignore();		
	}
	utils.imprimirCola(colaCedulas);
}
		
	
		
int main(){
	run();
	return 0;
}
