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

	int maxprime = floor(sqrt(pow(10,15)));

	vi primos = Primoshasta(maxprime);

	long long n;
	cin >> n;
	int counter;
	while(n != 0){

		for(int p : primos){
			if (n%p == 0){
				counter = 0;
				while(n%p == 0){
					n /= p;
					counter += 1;
				}

				cout << p << "^" << counter << " ";
			}
			
			if(n < p){
			    break;
			}
		}
		
		if (n != 1){
		    cout << n << "^1";
		}
		
		cout << endl;
		
		cin >> n;
	}

	return 0;
}