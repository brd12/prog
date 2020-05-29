//Eleven - https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4540

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> frac;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd
#define endl '\n'
#define pb push_back

inline ll mod(ll x, ll m) { return ((x %= m) < 0) ? x+m : x; }
inline ll prod(ll x, ll y, ll m) { return (x * y) % m; }
inline ll sum(ll x, ll y, ll m) { return (x + y) % m; }

const ll cmod = 1000000007;
int digits[10];
int binomio[110][110];
int DP[10][11][110][110];

int bin(int n, int k){
    if(k > n){
        return 0;
    }
    return binomio[n][k];
}

int f(int digito, int suma, int pares, int impares){

    int sol = 0;

    if(pares < 0 or impares < 0){
        return 0;
    }

    if(digito == 0){
        if(pares == impares){
            rep(a, 0, digits[digito]){
                sol += prod(prod(bin(impares, a), bin(pares-1, digits[digito] - a), cmod) ,f(digito+1, sum((suma + 2*a*digito)%11, -1*digits[digito]*digito, 11), pares + a - digits[digito], impares - a), cmod);
                sol %= cmod;
            }
        }
        else{
            rep(a, 0, digits[digito]){
                sol += prod(prod(bin(impares-1, a), bin(pares, digits[digito] - a), cmod) ,f(digito+1, sum((suma + 2*a*digito)%11, -1*digits[digito]*digito, 11), pares + a - digits[digito], impares - a), cmod);
                sol %= cmod;
            }
        }
        return sol;
    }

    if(digito == 9){
        if(sum((suma + 2*impares*digito)%11, -1*digits[digito]*digito, 11) == 0){
            return 1;
        }
        return 0;
    }

    if(DP[digito][suma][pares][impares] != -1){
        return DP[digito][suma][pares][impares];
    }

    rep(a, 0, digits[digito]){
        sol += prod(prod(bin(impares, a), bin(pares, digits[digito] - a), cmod) ,f(digito+1, sum((suma + 2*a*digito)%11, -1*digits[digito]*digito, 11), pares + a - digits[digito], impares - a), cmod);
        sol %= cmod;
    }

    return DP[digito][suma][pares][impares] = sol;

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	int par;

    rep(a, 0, 105){
        binomio[a][0] = 1;
        binomio[a][a] = 1;
    }

    rep(a, 2, 105){
        rep(b, 1, a-1){
            binomio[a][b] = sum(binomio[a-1][b], binomio[a-1][b-1], cmod);
        }
    }

	string s;
	while(cin >> s){
		memset(digits, 0, sizeof(digits));
        memset(DP, -1, sizeof(DP));
		par = s.length()/2;
		for(char c : s){
			digits[c - '0'] += 1;
		}

        cout << f(0, 0, par, s.length() - par) << endl;
	}

	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt