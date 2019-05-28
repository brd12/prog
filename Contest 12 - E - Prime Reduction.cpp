#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define rep(i, a, b) for (size_t i = a; i < (size_t)b; i++)

vi Primoshasta(int n){ //criba
	vector<bool> isPrime(n+2, true);
	vi lista;

	for(int k = 2; k*k <= n; k++){
		if (isPrime[k]){
			for(int j = k*k; j <= n; j += k){
				isPrime[j] = false;
			}
		}
	}

	rep(a, 2, n+1){
		if (isPrime[a]){
			lista.emplace_back(a);
		}
	}

	return lista;
}

int main(){

	int maxprime = floor(sqrt(pow(10,9)));

	vi primos = Primoshasta(maxprime);

	long long n;
	cin >> n;
	int counter = 0;
	int suma = 0;
	int previouscheck = 0;
	bool safefail = false;
	while(n != 4){
	    previouscheck = n;

		for(int p : primos){
			if (previouscheck == p){
				safefail = true;
				break;
			}
			if (n%p == 0 and n != p){
				while(n%p == 0){
					n /= p;
					suma += p;
				}
			}
			
			if(n < p){
			    break;
			}
		}
		
		counter += 1;
		if (n != 1){
		    n += suma;
		}
		else{
		    n = suma;
		}
		suma = 0;

		if (previouscheck == n){
		    cout << previouscheck << " " << counter << endl;
		    cin >> n;
		    counter = 0;
		    suma = 0;
		}
		previouscheck = n;
	}

	return 0;
}