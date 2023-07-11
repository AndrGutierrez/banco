#include <iostream>
#include <queue>
#include "Utils.h"
using namespace std;
void run(){
	Utils utils;
	queue<int> colaCedulas;
	colaCedulas = utils.agregarCedula(colaCedulas, "123456789");
	utils.imprimirCola(colaCedulas);
}
int main(){
	run();

	return 0;
}
