#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd

ll Factorial[1000002];
ll mod = 1000000007;

bool isGood(ll a, ll b, ll n){
	while(n > 0){
		if (n%10 != a and n%10 != b){
			return false;
		}
		n /= 10;
	}
	return true;
}

void Extendedgcd(ll a, ll b, ll&g, ll& x, ll& y){
	ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
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

ll invmod(ll a, ll m) {
	ll g, x, y; Extendedgcd(a, m, g, x, y);
	if (g == 1) return (x + m) % m;
	return -1;
}


ll mulmod(ull a, ull b, ull c) //a*b mod c
{
    ull x = 0, y = a % c;
    while (b)
    {
        if (b & 1)
            x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll BinomialMod(ll n, ll k, ll mod){
	return mulmod(Factorial[n], invmod(mulmod(Factorial[k], Factorial[n-k], mod), mod), mod);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, n;
	cin >> a >> b >> n;
	ll sol = 0;

	Factorial[0] = 1;

	rep(k, 1, 1000000){
		Factorial[k] = (Factorial[k-1]*k)%mod;
	}

	rep(k, 0, n){
		if (isGood(a, b, k*a + (n-k)*b)){
			sol += BinomialMod(n, k, mod);
			sol = sol%mod;
		}
	}

	cout << sol << endl;

    return 0;
}