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
	int numero = 0;
	for(char c : s){
		if(isdigit(c)){
			numero *= 10;
			numero += c - '0';
		}
	}

	cout << 36000/gcd(36000, numero) << endl;

	return 0;
}