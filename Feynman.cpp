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

    ll n;
    cin >> n;
    
    while(n > 0){
        cout << n*(n+1)*(2*n+1)/6 << endl;
        cin >> n;
    }
    return 0;
}

//g++- -std=c++11 -O2 Temp.cpp && a.exe < in.txt > out.txt
