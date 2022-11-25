// Luciano Massa Pérez, 2022
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Un juego válido cumple con una y sólo una de estas 3 condiciones:
1) Gana O
2) Gana X
3) Termina en empate

En el primer caso, debe existir una combinación de 4 O's en vertical o en
horizontal, y no debe existir una combinación de 4 X's ni en vertical ni en
horizontal. Además la última jugada debe ser una O.
En el segundo, debe existir una combinación de 4 X's en vertical o en
horizontal, y no debe existir una combinación de 4 O's ni en vertical ni en
horizontal. Además la última jugada debe ser una X.
En el tercero todas las celdas deben están marcadas con una X o una O y no puede
haber una combinación de 4 O's ni de 4 X's ni en horizontal ni en vertical.

Otro factor a considerar es el número de O's y el número de X's. Si la última
jugada válida se marcó una O, como O empieza se tiene que el número de O's debe
ser igual al número de X's más 1. Si en cambio se marcó una X, el número de O's
debe ser igual al número de X's.
*/

int main() {
	int n;
	cin >> n;
	
	vector<string> grilla(n);
	for(int i = 0; i < n; ++i)
		cin >> grilla[i];
	
	int cantidad_O = 0, cantidad_X = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
		
			if(grilla[i][j] == 'O') ++cantidad_O;
			if(grilla[i][j] == 'X') ++cantidad_X;
		}
	}
	
	int combinaciones_X = 0, combinaciones_O = 0;
	vector<vector<int> > participaciones(n, vector<int>(n));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			
			if(grilla[i][j] == 'X') {
				
				int num_X_derecha = 1, num_X_abajo = 1;
				for(int k = j+1; k < n and grilla[i][k] == 'X' and num_X_derecha < 4; ++k, ++num_X_derecha);
				for(int k = i+1; k < n and grilla[k][j] == 'X' and num_X_abajo < 4; ++k, ++num_X_abajo);
				
				if(num_X_derecha == 4) {
					++combinaciones_X;
					for(int k = j; k < j+4; ++k)
						participaciones[i][k]++;
				}
				if(num_X_abajo == 4) {
					++combinaciones_X;
					for(int k = i; k < i+4; ++k)
						participaciones[k][j]++;
				}
			}
			if(grilla[i][j] == 'O') {
				
				int num_O_derecha = 1, num_O_abajo = 1;
				for(int k = j+1; k < n and grilla[i][k] == 'O' and num_O_derecha < 4; ++k, ++num_O_derecha);
				for(int k = i+1; k < n and grilla[k][j] == 'O' and num_O_abajo < 4; ++k, ++num_O_abajo);
				
				if(num_O_derecha == 4) {
					++combinaciones_O;
					for(int k = j; k < j+4; ++k)
						++participaciones[i][k];
				}
				if(num_O_abajo == 4) {
					++combinaciones_O;
					for(int k = i; k < i+4; ++k)
						++participaciones[k][j];
				}
			}
		}
	}
	
	if(combinaciones_X > 0 and combinaciones_O > 0) {
		cout << "imposible\n";
		return 0;
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {

			if(grilla[i][j] == 'X' and combinaciones_X > 0 and participaciones[i][j] == combinaciones_X) {
				if(cantidad_X == cantidad_O)
					cout << "posible\n";
				else
					cout << "imposible\n";
				return 0;
			}
			if(grilla[i][j] == 'O' and combinaciones_O > 0 and participaciones[i][j] == combinaciones_O) {
				if(cantidad_X+1 == cantidad_O)
					cout << "posible\n";
				else
					cout << "imposible\n";
				return 0;
			}
		}
	}
	
	if(cantidad_O + cantidad_X == n*n) {
		if(n % 2 == 1) {
			if(cantidad_O == cantidad_X+1)
				cout << "posible\n";
			else
				cout << "imposible\n";
		}
		else {
			if(cantidad_O == cantidad_X)
				cout << "posible\n";
			else
				cout << "imposible\n";
		}
	}
	else {
		cout << "imposible\n";
	}
}
