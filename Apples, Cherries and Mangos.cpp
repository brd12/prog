//Apples, Cherries and Mangos -> https://open.kattis.com/problems/applescherriesmangos

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vi> g;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define pb push_back
#define endl '\n'
#define trav(a,x) for (auto& a: x)

const ll cmod = 1000000007;

inline ll mod(ll x, ll m) { return ((x %= m) < 0) ? x+m : x; }
inline ll prod(ll x, ll y, ll m) { return (x * y) % m; }
inline ll sum(ll x, ll y, ll m) { return (x + y) % m; }

ll facts[400003];
ll invfacts[400003];
ll pow2[400003];

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

ll invmod(ll a, ll m) { //MODULAR INVERSE
    ll g, x, y;
    Extendedgcd(a, m, g, x, y);
    if(g == 1){
        return mod(x, m);
    } // make sure 0 <= x < m
    return -1;
}

ll invf(ll n){
	if (invfacts[n] != -1){
		return invfacts[n];
	}
	else{
		return invfacts[n] = invmod(facts[n], cmod);
	}
}

ll multinomial(ll n, ll l, ll g, ll e){
	if(l < 0 or g < 0 or e < 0){
		return 0;
	}
	else{
		return prod(prod(prod(facts[n], invf(l), cmod), invf(g), cmod), invf(e), cmod);
	}
}

ll binomial(ll n, ll k){
	if (n < k or n < 0 or k < 0){
		return 0;
	}
	else{
		return prod(prod(facts[n], invf(k), cmod), invf(n-k), cmod);
	}
}

ll count(ll a, ll b, ll c){
	ll sol = 0;
	ll l, g, e;
	repx(k, 0, c+1){ 
		l = b-c+k;
		g = k;
		e = a-l-g;
		sol += prod(prod(multinomial(a, l, g, e), pow2[e], cmod), binomial(b+k-1, a-1), cmod);
		//binomial = (c-k-e+(a-1), a-1);
		sol %= cmod;
	}
	return sol;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	memset(invfacts, -1, sizeof(invfacts));
	pow2[0] = 1;
	facts[0] = 1;

	repx(lulz, 1, 400002){
		pow2[lulz] = (pow2[lulz-1]*2)%cmod;
		facts[lulz] = (facts[lulz-1]*lulz)%cmod;
	}

	vll fruits;
	ll temp;
	rep(z, 3){
		cin >> temp;
		fruits.pb(temp);
	}
	sort(fruits.begin(), fruits.end());
	ll a, b, c;
	a = fruits[2]; b = fruits[1]; c = fruits[0];

	ll sol = 0;
	sol += count(a+1, b, c) + 2*count(a, b, c) + count(a-1, b, c);
	cout << (sol%cmod + cmod)%cmod << endl;

	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt
