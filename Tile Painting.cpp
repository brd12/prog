#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd

vll Primoshasta(ll n){
	vector<bool> isPrime(n+2, true);
	vll lista;

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
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	vll primos = Primoshasta(1e6 + 3);
	
	ll sol = n;

	for(ll p : primos){
		if(p > n){
			break;
		}
		if(n%p == 0){
			while(n%p == 0){
				n /= p;
			}
			if(n != 1){
				cout << 1 << endl;
				return 0;
			}
			else{
				cout << p << endl;
				return 0;
			}
		}
	}

	cout << sol << endl;

    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt