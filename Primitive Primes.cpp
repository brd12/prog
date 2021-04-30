//Primitive Primes -> https://codeforces.com/contest/1316/problem/C

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define endl '\n'
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	int n, m, p;
    cin >> n >> m >> p;
    vi ai(n);
    vi bi(m);
    rep(a, n){
        cin >> ai[a];
    }
    rep(b, m){
        cin >> bi[b];
    }
    int coefa, coefb;
    coefa = coefb = 0;
    while(ai[coefa]%p == 0){
        coefa++;
    }
    while(bi[coefb]%p == 0){
        coefb++;
    }
    cout << coefa+coefb << endl;

	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt
