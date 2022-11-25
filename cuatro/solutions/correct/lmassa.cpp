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
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			
			if(grilla[i][j] == 'X') {
				
				int num_X_derecha = 1, num_X_abajo = 1;
				for(int k = j+1; k < n and grilla[i][k] == 'X' and num_X_derecha < 4; ++k, ++num_X_derecha);
				for(int k = i+1; k < n and grilla[k][j] == 'X' and num_X_abajo < 4; ++k, ++num_X_abajo);
				
				if(num_X_derecha == 4) ++combinaciones_X;
				if(num_X_abajo == 4) ++combinaciones_X;
			}
			if(grilla[i][j] == 'O') {
				
				int num_O_derecha = 1, num_O_abajo = 1;
				for(int k = j+1; k < n and grilla[i][k] == 'O' and num_O_derecha < 4; ++k, ++num_O_derecha);
				for(int k = i+1; k < n and grilla[k][j] == 'O' and num_O_abajo < 4; ++k, ++num_O_abajo);
				
				if(num_O_derecha == 4) ++combinaciones_O;
				if(num_O_abajo == 4) ++combinaciones_O;
			}
		}
	}
	if(combinaciones_X > 0 and combinaciones_O > 0) {
		cout << "imposible\n";
		return 0;
	}
	if(combinaciones_X == 0 and combinaciones_O == 0 and cantidad_O + cantidad_X < n*n) {
		cout << "imposible\n";
		return 0;
	}
	if(combinaciones_X == 0 and combinaciones_O == 0) {
		if(n % 2 == 1) {
			if(cantidad_X+1 == cantidad_O) cout << "posible\n";
			else cout << "imposible\n";
		}
		else {
			if(cantidad_X == cantidad_O) cout << "posible\n";
			else cout << "imposible\n";
		}
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(grilla[i][j] == '.') continue;
			
			char marca = grilla[i][j];
			grilla[i][j] = '.';
			int combX = 0, combO = 0;
			for(int k = 0; k < n; ++k) {
				for(int l = 0; l < n; ++l) {
					if(grilla[k][l] == 'X') {
						int numXder = 1, numXaba = 1;
						for(int m = l+1; m < n and grilla[k][m] == 'X' and numXder < 4; ++numXder, ++m);
						for(int m = k+1; m < n and grilla[m][l] == 'X' and numXaba < 4; ++numXaba, ++m);
						
						combX += (numXder == 4) + (numXaba == 4);
					}
					if(grilla[k][l] == 'O') {
						int numOder = 1, numOaba = 1;
						for(int m = l+1; m < n and grilla[k][m] == 'O' and numOder < 4; ++numOder, ++m);
						for(int m = k+1; m < n and grilla[m][l] == 'O' and numOaba < 4; ++numOaba, ++m);
						
						combO += (numOder == 4) + (numOaba == 4);
					}
				}
			}
			
			if(combinaciones_X > 0 and combX == 0 and cantidad_X == cantidad_O) {
				cout << "posible\n";
				return 0;
			}
			if(combinaciones_O > 0 and combO == 0 and cantidad_X+1 == cantidad_O) {
				cout << "posible\n";
				return 0;
			}
			
			grilla[i][j] = marca;
		}
	}
	
	cout << "imposible\n";
}
