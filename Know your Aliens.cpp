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

    string s;
    cin >> s;
    
    ll roots = 0;
    int multiplier = 1;
    vi points;
    
    ll largo = s.length();
    
    ll coef[10002];
    
    coef[0] = 1;
    
    char control = s[0];
    
    rep(k, 1, largo-1){
        if(control != s[k]){
            points.push_back(2*k + 1);
            roots += 1;
        }
        control = s[k];
    }
    
    rep(k, 1, roots){
        for(int j = k; j > 0; j--){
            coef[j] = coef[j-1] - points[k-1]*coef[j];
            }
        coef[0] = -points[k-1]*coef[0];
    }
    
    if((s[0] == 'A' and roots%2 == 0) or (s[0] == 'H' and roots%2 == 1)){
        multiplier = -1;
    }
    
    cout << roots << endl;
    
    for(int a = roots; a > 0; a--){
        cout << multiplier*coef[a] << " ";
    }
    cout << multiplier*coef[0] << endl;
    
    return 0;
}

//g++- -std=c++11 -O2 Temp.cpp && a.exe < in.txt > out.txt
