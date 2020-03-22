//Prime Reduction https://open.kattis.com/problems/primereduction

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> frac;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd

vi Primoshasta(int n){
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

int Suma_Factores(int n, vi primes){
	int result = 0;

	for(int p : primes){
		while(n%p == 0){
			result += p;
			n /= p;
			if(n == 1){
				break;
			}
		}
	}

	if (n > 1){
		result += n;
	}

	return result;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vi primos = Primoshasta(100000);

	while(n != 4){
		int counter = 0;
		int prevsuma = 1;
		int newsuma = n;
		while(prevsuma != newsuma){
			counter += 1;
			prevsuma = newsuma;
			newsuma = Suma_Factores(prevsuma, primos);
		}

		cout << prevsuma << " " << counter << endl;
		cin >> n;
	}

    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt