//Shrinking Polygons https://www.spoj.com/problems/SAMER08K/

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> frac;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd

vi Lista_Divisores(int n){ //Lista NO ORDENADA de divisores de un número.
	vi lista;
	rep(z, 1, floor(sqrt(n))){
		if (n%z == 0){
			lista.push_back(z);
			lista.push_back(n/z);
		}
	}
	if(floor(sqrt(n))*floor(sqrt(n)) == n){
		lista.pop_back();

		return lista;
	}
}

bool isLegal[10000002]; //1e7 + 2

bool lilJumps(int initial, int lados, int interval){
	rep(z, 0, lados-1){
		if (not isLegal[initial + z*interval]){
			//cout << "fallo! posicion " << initial + z*interval << " cantidad de lados: " << lados << " pos inicial << " << initial << endl;
			return false;
		}
	}
	return true;
}

bool isValid(int accsum, int lados){ //largo accsum en lados partes -> cada parte mide accsum/lados

	int largo = accsum/lados;
	rep(a, 0, largo-1){
		if(lilJumps(a, lados, largo)){
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, temp, accsum;

	cin >> n;

	while(n != 0){
		
		memset(isLegal, false, sizeof(isLegal));
		isLegal[0] = true;
		accsum = 0;

		rep(k, 1, n-1){
			cin >> temp;
			accsum += temp;
			//cout << accsum << endl;
			isLegal[accsum] = true;
		}

		cin >> temp;
		accsum += temp;
		
		vi divisores = Lista_Divisores(accsum);

		sort(divisores.begin(), divisores.end());
		reverse(divisores.begin(), divisores.end());

		//cout << divisores.size() << " " << divisores[divisores.size() - 1] << endl;

		/*cout << accsum << " ";
		for(ll a : divisores){
			cout << a << " ";
		}*/
		
		int index = 0;
		bool wincon = false;

		while(divisores[index] > 2){
			if(isValid(accsum, divisores[index])){
				//cout << "exito! numero de lados: " << divisores[index] << endl;
				cout << n - divisores[index] << endl;
				wincon = true;
				divisores[index] = 1;
			}
			else{
				index += 1;
			}
		}

		if(not wincon){
			cout << -1 << endl;
		}

		cin >> n;

	}



    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt