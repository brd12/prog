//Infinite Path https://codeforces.com/contest/1327/problem/D

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> graph;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> frac;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define log(x) (31 - __buitlin_clz(x))
#define logg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd
#define lcm(a, b) a/gcd(a, b)*b

vi Lista_Divisores(int n){ //Lista NO ORDENADA de divisores de un número.
	vi lista;
	rep(z, 1, floor(sqrt(n))){
		if (n%z == 0){
			lista.push_back(z);
			lista.push_back(n/z);
		}
	}
	if(floor(sqrt(n))*floor(sqrt(n)) == n){
		lista.pop_back();

		return lista;
	}
}

bool isVisited[200002];
int permutation[200002];
int colors[200002];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, actual_index, minloop;
	cin >> t;
	rep(a, 1, t){
		memset(isVisited, false, sizeof(isVisited));
		cin >> n;
		minloop = n;
		rep(b, 1, n){
			cin >> permutation[b];
		}
		rep(b, 1, n){
			cin >> colors[b];
		}
		rep(b, 1, n){
			if(!isVisited[b]){
				actual_index = b;
				//vi loop = {};
				vi color_loop = {};
				while(!isVisited[actual_index]){
					isVisited[actual_index] = true;
					//loop.push_back(actual_index);
					color_loop.push_back(colors[actual_index]);
					actual_index = permutation[actual_index];
				}

				int largo = color_loop.size();

				vi divisores = Lista_Divisores(largo);

				for(int d : divisores){
					rep(z, 0, d-1){
						bool isColored = true;
						int color_check = color_loop[z];
						rep(y, 1, largo/d - 1){
							if(color_check != color_loop[z + y*d]){
								isColored = false;
							}
						}
						if(isColored){
							//cout << "coloracion posible: d = " << d << endl;
							minloop = min(minloop, d);
							z = d-1;
						}
					}
				}
			}
		}

		cout << minloop << endl;
	}

    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt