#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, a, b) for (size_t i = a; i < (size_t)b; i++)

ll ModFactoriales[1000005];

int mod = 1000000007;

void Extendedgcd(int a, int b, int&g, int& x, int& y) {
	int r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
	r2 = a, x2 = 1, y2 = 0;
	r1 = b, x1 = 0, y1 = 1;
	while (r1) {
		q = r2 / r1;
		r0 = r2 % r1;
		x0 = x2 - q * x1;
		y0 = y2 - q * y1;
		r2 = r1, x2 = x1, y2 = y1;
		r1 = r0, x1 = x0, y1 = y0;
	}
	g = r2, x = x2, y = y2;
}

int modinv(int a, int m) {
	int g, x, y; Extendedgcd(a, m, g, x, y);
	if (g == 1) return (x + m) % m;
	return -1;
}


bool is_good(int a, int b, int number){
	while(number > 0){
		if (number%10 != a and number%10 != b){
			return false;
		}
		number /= 10;
	}
	return true;
}

int binomialmod(int n, int k, int mod){
	return ((ModFactoriales[n]*modinv(ModFactoriales[k], mod))%mod * modinv(ModFactoriales[n - k], mod))%mod;
}

int main(){
	
	
	ModFactoriales[0] = 1;

	rep(k, 1, 1000001){
		ModFactoriales[k] = (ModFactoriales[k-1]*k)%mod;
	}

	int a, b, largo, suma;
	cin >> a >> b >> largo;
	suma = 0;


	rep(k, 0, largo+1){


		if (is_good(a, b, k*a + (largo-k)*b)){
			suma += binomialmod(largo, k, mod);
			suma = suma%mod;
		}
	}
	
	cout << suma << endl;

	return 0;
}