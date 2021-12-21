#include "Temperatura.h"
#include "ubedots.h"
#include <iostream>
#include <chrono>
#include <winsock2.h>
#include<windows.h>
using namespace std;

int main() {
	Temperatura t; //Cria um objeto t da classe Temperatura
	t.inicializa(); // Inicializa a simulação
	t.enviarComando(RES_ON); // Aciona o resistor
	for (int i = 0; i < 10; ++i) {
		cout << t.lerTemp() << endl; // Lê a temperaturda
		this_thread::sleep_for(chrono::milliseconds(1000)); // Aguarda
	}
	return EXIT_SUCCESS;
}
