#include <bits/stdc++.h>
using namespace std;

vector<int> DP; //spoiler

bool particular_jump(int mod, string arena, int largo, int caso){ //revisa los espacios con numeracion congruente al caso mod (mod)
	for(int b = 0; b < largo/mod; b++){
		if (arena[caso + b*mod] == 'P'){
			return false;
		}

	}
	return true;
}

int global_jump(int mod, string arena, int largo){

	if(DP[mod] != -1){ //revisar si ya se hizo
		return DP[mod];
	}
	else{
		for(int a = 0; a < mod; a++){ //si se hacen saltos de tamaño k, hay k opciones disjuntas que revisar //
			if (particular_jump(mod, arena, largo, a)){
				DP[mod] = 1;
				return 1;
			}
		}
		DP[mod] = 0;
		return 0;
	}
}


int main(){

	string arena;

	while(cin >> arena){

		int conteo = 0;

		int largo = arena.length();

		DP.assign(largo, -1);

		if(largo%2 == 0){

			for(int k = 1; k < largo/2; k++){
				conteo += 2*global_jump(__gcd(largo, k), arena, largo); //mcd(a, b) = mcd(a-b, b), corriendo en todo el largo da TLE
				//como la arena es circular, saltos de largo k pasa por todas las casillas con distancia mcd(tamaño_arena, k), por lo que hay que revisar en el mcd.

			}

			conteo += global_jump(largo/2, arena, largo);

		}

		else{
			for(int k = 1; k < largo/2 +1; k++){
				conteo += 2*global_jump(__gcd(largo, k), arena, largo);
			}
		}

		cout << conteo << endl;

	}

	return 0;
}