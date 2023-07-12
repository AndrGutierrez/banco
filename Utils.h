#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Utils{
public:
	Utils(){}
	queue<int> agregarCedula(queue<int> cola, string cedula){
		int cantidadDigitos=3;
		int i=cedula.length()-cantidadDigitos;
		bool cedulaYaAgregada = false;
		int digitos;

		do{
			digitos=obtenerTresDigitos(i, cedula, 3);
			cedulaYaAgregada=existeEnCola(cola, digitos);
			i--;
		}
		while(cedulaYaAgregada && i>=0);
		if(i<0 && cedulaYaAgregada){
			reverse(cedula.begin(), cedula.end()); 
			i=cedula.length()-cantidadDigitos;
			do{
				digitos=obtenerTresDigitos(i, cedula, 3);
				cedulaYaAgregada=existeEnCola(cola, digitos);
				i--;
			}
			while(cedulaYaAgregada && i>=0);
		}
		cola.push(digitos);
		// imprimirCola(cola);
		return cola;
	}

	int obtenerTresDigitos(int posicion, string cedula, int cantidad){
		string digitos = "";
		for(int i=posicion; i<posicion+3; i++){
			digitos += cedula[i];
		}
		int digitosInt= stoi(digitos);
		// cout << digitosInt << endl;
		return digitosInt;
	}

	bool existeEnCola(queue<int> cola, int numero){
		queue<int> copiaCola=cola;
		bool existe = false;
		while (!copiaCola.empty()) {
			if (copiaCola.front() == numero) {
				existe = true;
				break;
			}
			copiaCola.pop();
		}

		// cout << "existe: " << existe << endl;
		return existe;
	}
	void imprimirCola(queue<int> cola){

		queue<int> copiaCola=cola;
		while (!copiaCola.empty()) {
			cout << copiaCola.front() << endl;
			copiaCola.pop();
		}
	}
	
	
	queue<int> ingresarCedulas(queue<int> colaCedulas){
		
		queue<int> CopiaColaCedulas = colaCedulas;
		string cedula;
		cout<<"Porfavor ingrese su cedula de identidad"<<endl;
		getline(cin,cedula);			
		CopiaColaCedulas= agregarCedula(colaCedulas, cedula);
		
		return CopiaColaCedulas;
		
	}
	
	queue<int>  pasarClienteAtaquilla(queue<int> colaCedulas){
		queue<int> CopiaColaCedulas = colaCedulas;
		cout<<"la clave del cliente que sigue en la cola virtual es " << CopiaColaCedulas.front()<<endl;
		CopiaColaCedulas.pop();
		return CopiaColaCedulas;
		
	}
	

};

