#include <bits/stdc++.h>
using namespace std;


int polignac_2 (int numero){ // mayor potencia de 2 que divide a numero!
	int conteo = 0;
	for (int k = 1; k < 20; k++){

		conteo += numero/pow(2, k);
	}
	return conteo;
}


int polignac_5 (int numero){ //mayor potencia de 5 que divide a numero!
	int conteo = 0;
	for (int k = 1; k < 9; k++){

		conteo += numero/pow(5, k);

	}

	return conteo;
}

int v_2 (int numero){ // mayor potencia de 2 que divide a un numero
	for(int k = 1; k <= 20; k++){
		if (fmod(numero, pow(2, k)) != 0){
			return k-1;
		}
	}
}


int v_5 (int numero){ //mayor potencia de 5 que divide a un numero
	for(int k = 1; k <= 9; k++){
		if (fmod(numero, pow(5, k)) != 0){
			return k-1;
		}
	}
}

int inverso (int numero){ // inversos mod 10
	if(numero == 1){
		return 1;
	}
	else if(numero ==3){
		return 7;
	}
	else if(numero == 7){
		return 3;
	}
	else if(numero == 9){
		return 9;
	}
}


int aporte (int numero){ //modulo 10 sin 2s ni 5s
	if (numero == 1){
		return 1;
	}
	else{
		int digito = 1;
		for (int k = 2; k <= numero; k++){
			digito *= k/(pow(2, v_2(k))*pow(5, v_5(k)));
			digito = digito%10;
		}
	return digito;
	}
}

int bucle (int numero){ //definido por temas de tamaño lol
	if (numero == 0){
		return 1;
	}
	else if (numero % 4 == 0){
		return 6;
	}
	else if (numero % 4 == 1){
		return 2;
	}
	else if (numero % 4 == 2){
		return 4;
	}
	else if (numero % 4 == 3){
		return 8;
	}
}

int main(){
	string palabra;
	while(getline(cin, palabra)){
		
		int sol = 1;
		int divisores[2] = {0, 0}; // guarda los 2s y 5s
		map <char, int> diccionario; //contar letras
		for(int k = 0; k < palabra.size(); k++){
			if (diccionario.count(palabra[k]) == 1){
				diccionario[palabra[k]] += 1;
			}
			else{
				diccionario[palabra[k]] = 1;
			}
		}	


		for ( const auto &p : diccionario ){ //calcula mod 10 de cada divisor del multinomial
   			sol *= aporte(p.second);
   			sol = sol%10;
   			divisores[0] -= polignac_2(p.second); //cuenta los 2s en los divisores del multinomial
   			divisores[1] -= polignac_5(p.second); //cuenta los 5s en los divisores del multinomial
		}
		divisores[0] += polignac_2(palabra.size()); //cuenta los 2s en el numerador
		divisores[1] += polignac_5(palabra.size()); //cuenta los 5s en el numerador
		sol *= inverso(aporte(palabra.size())); //multiplica por el inverso del numerador, llevamos el inverso de la solucion
		sol = (sol+10)%10;
		sol = inverso(sol); //solucion sin 2s ni 5s


		int ceros = min(divisores[0], divisores[1]); // cuenta los 0s a la derecha
		divisores[0] -= ceros;
		divisores[1] -= ceros;
		sol*= bucle(divisores[0]); // multiplicar por lo que queda
		sol = sol%10;
		cout << sol << endl;
	}
	return 0;
}
