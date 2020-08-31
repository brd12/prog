//Going to School - https://www.spoj.com/problems/GS/

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

ld act[15][15];
ld probs[15][15];
ld receiving[15];


void matMul(int n){
	ld sol[15][15];
	memset(sol, 0, sizeof(sol));
	rep(a, n){
		rep(b, n){
			rep(c, n){
				sol[a][b] += act[a][c]*probs[c][b];
			}
		}
	}
	swap(act, sol);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	cout.precision(5);

	int t, n, start, goal, temps, tempg;
	cin >> t;
	ld psol;
	ld anterior;
	rep(test, t){
		cin >> n >> start >> goal;
		psol = 0;
		anterior = 0;
		memset(probs, 0, sizeof(probs));
		memset(receiving, 0, sizeof(receiving));
		memset(act, 0, sizeof(act));
		rep(a, n-1){
			cin >> temps >> tempg;
			cin >> probs[temps-1][tempg-1];
			probs[tempg-1][temps-1] = probs[temps-1][tempg-1];
			receiving[tempg-1] += probs[temps-1][tempg-1];
			receiving[temps-1] += probs[temps-1][tempg-1];
		}
		receiving[goal-1] = 1;
		rep(a, n){
			act[a][a] = 1;
			probs[goal-1][a] = 0;
			rep(b, n){
				probs[a][b] /= receiving[a];
			}
		}
		probs[goal-1][goal-1] = 1;
		repx(a, 1, 3001){
			//cout << "------------------------" << endl;
			matMul(n);
			/*rep(a, n){
				rep(b, n){
					cout << act[a][b] << " ";
				}
				cout << endl;
			}"acc: " << act[start-1][goal-1] << endl;*/ 
			psol += a*(act[start-1][goal-1] - anterior);
			anterior = act[start-1][goal-1];
			//cout << "loop: " << a << ", esperanza actual : " << psol << endl;
		}	
		cout << fixed;
		cout << psol << endl;

	}

	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt