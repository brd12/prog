//PRIME1 - Prime Generator https://www.spoj.com/problems/PRIME1/en/

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

bool isPrime(int n, vi primes){
	for(int p : primes){
		if (p*p > n){
			break;
		}
		if(n%p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	vi primes = Primoshasta(100000);

	int t, n, m;
	cin >> t;

	rep(k, 1, t){
		cin >> m >> n;

		rep(a, max(2, m), n){
			if(isPrime(a, primes)){
				cout << a << endl;
			}
		}
		cout << endl;
	}

    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt