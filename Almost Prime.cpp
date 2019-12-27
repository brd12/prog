#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    vi PrimeDivisors(3002, 0);

    rep(k, 2, 1500){
        if(PrimeDivisors[k] == 0){
            for(int j = k; j < 3001; j += k){
                PrimeDivisors[j] += 1;
            }
        }
    }

    int sol = 0;
    int n;
    cin >> n;

    rep(a, 2, n){
        if(PrimeDivisors[a] == 2){
            sol += 1;
        }
    }

    cout << sol << endl;
    return 0;
}