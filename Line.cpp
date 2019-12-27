#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd

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


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	ll mcd = gcd(a, b);
	if(c%mcd != 0){
		cout << -1 << endl;
		return 0;
	}

	a /= mcd;
	b /= mcd;
	c /= mcd;

	ll x, y, g;

	Extendedgcd(a, b, g, x, y);

	cout << -x*c << " " << -y*c << endl;

    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe < in.txt > out.txt