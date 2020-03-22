//Interval Product https://matcomgrader.com/problem/9339/interval-product/

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> frac;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd
//Segment Tree

const int maxn = 100000; //Editar segun constraints

int tree[2*maxn];

void build(int lista[], int n){

	rep(a, 0, n-1){
		tree[n+a] = lista[a];
	}

	for(int a = n-1; a > 0; a--){
		tree[a] = tree[a << 1] * tree[a << 1 | 1];
	}
}

void updateNode(int pos, int val, int n){
	tree[pos + n] = val;
	pos += n;

	for(int a = pos; a > 1; a >>= 1){
		tree[a>>1] = tree[a] * tree[a^1];
	}
}

int query(int l, int r, int n){ //query en intervalo [l, r)
	int res = 1;
	
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l&1){
			res *= tree[l++];
		}

		if(r&1){
			res *= tree[--r];
		}
	}

	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	char command;
	int temp, temp1, temp2; //temp = valores de array, temp1, temp2 = valores de query
	while(cin >> n >> k){
		int values[n];
		rep(a, 0, n-1){
			cin >> temp;
			if(temp > 0){
				values[a] = 1;
			}
			else if(temp == 0){
				values[a] = 0;
			}
			else{
				values[a] = -1;
			}
		}
		
		build(values, n);
		rep(a, 1, k){
			cin >> command >> temp1 >> temp2;
			if(command == 'C'){
				if(temp2 > 0){
					updateNode(temp1-1, 1, n);
				}
				else if(temp2 < 0){
					updateNode(temp1-1, -1, n);
				}
				else{
					updateNode(temp1-1, 0, n);
				}
			}
			else{
				int result = query(temp1-1, temp2, n);

				if(result > 0){
					cout << "+";
				}
				else if(result < 0){
					cout << "-";
				}
				else{
					cout << "0";
				}
			}
		}
		cout << endl;
	}

    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt