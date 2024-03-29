#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

// Potencia Modular
long long power(long long base, long long exponent, long long mod) {
	long long res = 1;
	while (exponent > 0) {
		if (exponent & 1)
			res = (res * base) % mod;
		base = (base * base) % mod;
		exponent >>= 1;
	}
	return res;
}

int main() {
	long long p = 104729; // n�mero primo
	long long g = 3;  // n�mero primitivo
	
	long long j = 98765;  // clave privada de Jilmar
	long long d = 3; // clave privada de David
	
	// Jilmar y David calculan sus claves p�blicas
	long long A = power(g, j, p);
	long long B = power(g, d, p);
	
	// Inicio cronometro
	auto start = chrono::high_resolution_clock::now();
	
	// Repeticiones
	int num_reps = 3000000;
	
	for (int i = 0; i < num_reps; i++) {
		// Jilmar y David - clave compartida
		long long keyA = power(B, j, p);
		long long keyB = power(A, d, p);
	}
	
	// Fin cron�metro
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	
	cout<< "Tiempo de ejecuci�n : " << duration.count() << " microsegundos" << endl;
	
	return 0;
}
