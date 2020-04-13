//Stop Counting! https://open.kattis.com/problems/stopcounting

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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    cout.precision(15);

    int n, temp;
    cin >> n;

    double maxwin = 0;

    ll accsum[n + 2];
    accsum[0] = 0;
    rep(a, 1, n){
        cin >> temp;
        accsum[a] = accsum[a-1] + temp;
    }

    rep(a, 1, n){
        maxwin = max(maxwin, (double)accsum[a]/a);
        maxwin = max(maxwin, (double)(accsum[n] - accsum[n-a])/a);
        //cout << (double)accsum[a]/a << " " << (double)(accsum[n] - accsum[n-a])/a << endl;
    }
    cout << maxwin << endl;

    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt