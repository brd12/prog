#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd

ll mod = 10000007;

ll binpow(ll a, ll b, ll m){
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    ll n, k, sol;
    cin >> n >> k;
    while(n != 0 or k != 0){
        sol = 0;

        sol += binpow(n, k, mod);
        sol = sol%mod;
        sol += binpow(n, n, mod);
        sol = sol%mod;
        sol += 2*binpow(n-1, k, mod);
        sol = sol%mod;
        sol += 2*binpow(n-1, n-1, mod);
        sol = sol%mod;

        cout << sol << endl;
        cin >> n >> k;
    }

    return 0;
}