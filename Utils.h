#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;


class Stack {
public:
    int top;
    unsigned capacity;
    char* array;
};

Stack* createStack(unsigned capacity)
{
    Stack* stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array
        = new char[(stack->capacity * sizeof(char))];
    return stack;
}

int isFull(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) { return stack->top == -1; }

void push(Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

void reverse(char str[])
{

    int n = strlen(str);
    Stack* stack = createStack(n);

    int i;
    for (i = 0; i < n; i++){
    	push(stack, str[i]);
	}
        

    for (i = 0; i < n; i++){
    	str[i] = pop(stack);
	}
        
}


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

   			string str = cedula;
   			char char_arr[str.length()];
   	
   			for (int i = 0; i < str.length(); i++) {
       			char_arr[i] = str[i];

   			}
   	
  			reverse(char_arr);	
			int size = sizeof(char_arr) / sizeof(char_arr[0]);
			string Str(char_arr, size);
			
			cout<<"cedula invertida "<<Str<<endl;
   			cedula = Str;

			i=cedula.length()-cantidadDigitos;
			do{
				digitos=obtenerTresDigitos(i, cedula, 3);
				cedulaYaAgregada=existeEnCola(cola, digitos);
				i--;
			}
			while(cedulaYaAgregada && i>=0);
		}
		cola.push(digitos);
		imprimirCola(cola);
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

