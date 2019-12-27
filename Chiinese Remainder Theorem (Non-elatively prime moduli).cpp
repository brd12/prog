#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd

ll modsum(ll a, ll b, ll mod){
	return (((a%mod) + (b%mod))%mod + mod)%mod;
}

ll modprod(ll a, ll b, ll mod){
	return (((a%mod) * (b%mod))%mod + mod)%mod;
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

//Teo Chino del Resto x tal que x = r1 mod m1 y x = r2 mod m2

pair<ll, ll> CRT(ll r1, ll m1, ll r2, ll m2){
	ll x, y, g;
	Extendedgcd(m1, m2, g, x, y);
	if ((r1 - r2)% g != 0){
		return {-1, -1};
	}
	ll temp = (m2/g);
	ll mcm = temp*m1;

	return {modsum(r1%mcm, m1*modprod(x%temp, ((r2-r1)/g)%temp, temp), mcm), mcm};	
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T;
    cin >> T;
    ll r1, m1, r2, m2;
    rep(k, 1, T){
        cin >> r1 >> m1 >> r2 >> m2;
        pair<ll, ll> sol = CRT(r1, m1, r2, m2);
        if(sol.first == -1){
            cout << "no solution" << endl;
        }
        else{
            cout << sol.first << " " << sol.second << endl;
        }
    }
    return 0;
}