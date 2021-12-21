#include "Temperatura.h"
#include "ubedots.h"
#include <iostream>
#include <chrono>
#include <winsock2.h>
#include<windows.h>
using namespace std;

int main() {
	Temperatura t; //Cria um objeto t da classe Temperatura
	t.inicializa(); // Inicializa a simula��o
	t.enviarComando(RES_ON); // Aciona o resistor
	for (int i = 0; i < 10; ++i) {
		cout << t.lerTemp() << endl; // L� a temperaturda
		this_thread::sleep_for(chrono::milliseconds(1000)); // Aguarda
	}
	return EXIT_SUCCESS;
}
