#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define rep(i, a, b) for (size_t i = a; i < (size_t)b; i++)

vector<bool> isPrime(10000002, true);
vi primes;

int NumberofPrimes[10000002];


int main(){

	NumberofPrimes[1] = 0;

	for(int k = 2; k*k <= 10000000; k++){
		if (isPrime[k]){
			for(int j = k*k; j <= 10000000; j+= k){
				isPrime[j] = false;
			}
		}

	}

	rep(k, 2, 10000001){
		NumberofPrimes[k] = NumberofPrimes[k-1] + isPrime[k];
	}

	int t, n;

	cin >> t;

	rep(k, 0, t){

		cin >> n;

		cout << NumberofPrimes[n] - NumberofPrimes[n/2] << endl;

	}

	return 0;

}