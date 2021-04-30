//Simple Math 2 -> https://atcoder.jp/contests/arc111/tasks/arc111_a

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;

#define endl '\n'

ull modMul(ull a, ull b, const ull mod) { //Modular Multiplication
	ll ret = a*b-mod*(ull)((ld)a*b/mod);
	return ret+((ret<0)-(ret>=(ll)mod))*mod; }
ull modPow(ull a, ull b, const ull mod) { //Binary Exponentiation
	if (b == 0) return 1;
	ull res = modPow(a,b/2,mod); res = modMul(res,res,mod);
	return b&1 ? modMul(res,a,mod) : res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	ll n, m;
    cin >> n >> m;
    ll remainder;
    remainder = modPow(10, n, m*m);
    cout << (remainder/m)%m << endl;

	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt
