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

ld accsum[3001];
bool isChecked[3001];

ld lsol(ll t, ll f, ld p){
	if(f > t){
		return 0;
	}
	return lgamma(t) - lgamma(f) - lgamma(t-f+1) + (t-f)*log(p) + f*log(1-p);
}


ld bulk(ll tmax, ll f, double p){
	if(tmax < f){
		return 0;
	}
	if(isChecked[tmax-f]){
		return accsum[tmax-f];
	}
	isChecked[tmax-f] = true;
	return accsum[tmax-f] = exp(lsol(tmax, f, p)) + bulk(tmax-1, f, p);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	cout.precision(12);

	memset(isChecked, false, sizeof(isChecked));

	int n, k;
	ld p;

	cin >> n >> k >> p;
	ld failp = 1.0;
	repx(a, 1, 3000){
		failp -= n*exp(lsol(k+a, k, p))*exp((n-1)*log(bulk(k+a-1, k, p)));
	}
	cout << failp << endl;

	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt
