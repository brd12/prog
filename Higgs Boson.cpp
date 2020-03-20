//Higgs Boson https://www.urionlinejudge.com.br/judge/en/problems/view/1324

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> fraction;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd

fraction UpdateSol(fraction solvieja, fraction solnueva){
	//cout << solnueva.first << " " << solnueva.second << endl;
	if(solnueva == (fraction){-1, 0}){
		//cout << "failed solution" << endl;
		return solvieja;
	}

	if(solvieja == (fraction){0, 0}){
		//cout << "first sol!" << endl;
		return solnueva;
	}

	if(0 > solnueva.first*solvieja.second - solvieja.first*solnueva.second){
		return solnueva;
	}

	return solvieja;
}

fraction CheckSolution(fraction sol, ll a1, ll b1, ll c1, ll d1, ll a2, ll b2, ll c2, ll d2){
	/*cout << "intento de sol: " << sol.first << " " << sol.second << endl;
	cout << "radio1: " << sol.first*a1 + b1*sol.second << " " << sol.second << endl;
	cout << "radio2: " << sol.first*a2 + b2*sol.second << " " << sol.second << endl;
	cout << "angulo1: " << sol.first*c1 + d1*sol.second << " " << sol.second << endl;
	cout << "angulo2: " << sol.first*c2 + d2*sol.second << " " << sol.second << endl; */
	ll polarfix = 0;
	if(sol.second == 0){
		if(a1 != 0 and sol.first != 0){
			return {-1, 0};
		}
		if(a1 == 0){
			if(abs(b1) != abs(b2)){
				return {-1, 0};
			}
			if(b1 != b2){
				polarfix = 180;
			}
		}

		if(a1 != a2){
			polarfix = 180;
		}

		if(c1 == c2){
			if((d1 - d2 + polarfix)%360 != 0){
				return {-1, 0};
			}
			return {0, 1};
		}

		if(c1 < c2){
			swap(c1, c2);
			swap(d1, d2);
		}

		return {((d2 - d1 + polarfix)%360 + 360)%360, c1 - c2};

		return{1000, 1000};
	}

	if(sol.first < 0){
		return {-1, 0};		
	}

	if(a1*sol.first + b1*sol.second == 0){
		return sol;
	}

	if(a1*sol.first + b1*sol.second != a2*sol.first + b2*sol.second){
		polarfix = 180;
	}

	ll anglediff = c1*sol.first -c2*sol.first + d1*sol.second - d2*sol.second + polarfix*sol.second;
	if (anglediff%(360*sol.second) == 0){
		return sol;
	}
	return {-1, 0};
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a1, b1, c1, d1, a2, b2, c2, d2;
	cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2;

	while(a1 != 0 or b1 != 0 or c1 != 0 or d1 != 0 or a2 != 0 or b2 != 0 or c2 != 0 or d2 != 0){
		fraction sol1 = {b2 - b1, a1 - a2};
		fraction sol2 = {-b1 - b2, a1 + a2};

		if(sol1.first != 0 and sol1.second != 0){
			ll temp = gcd(sol1.first, sol1.second);
			//cout << "sol1 gcd " << temp << endl;
			sol1.first /= temp;
			sol1.second /= temp;
		}

		if(sol2.first != 0 and sol2.second != 0){
			ll temp = gcd(sol2.first, sol2.second);
			//cout << "sol2 gcd " << temp << endl;
			sol2.first /= temp;
			sol2.second /= temp;
		}

		if(sol1.second < 0){
			sol1.first *= -1;
			sol1.second *= -1;
		}

		if(sol2.second < 0){
			sol2.first *= -1;
			sol2.second *= -1;
		}

		//cout << sol1.first << " " << sol1.second << endl;
		//cout << sol2.first << " " << sol2.second << endl;

		fraction minsol = {0, 0};

		minsol = UpdateSol(minsol, CheckSolution(sol1, a1, b1, c1, d1, a2, b2, c2, d2));
		minsol = UpdateSol(minsol, CheckSolution(sol2, a1, b1, c1, d1, a2, b2, c2, d2));

		if(minsol.first == 0 and minsol.second > 0){
			minsol.second = 1;
		}

		if(minsol.first != 0){
			ll temp = gcd(minsol.first, minsol.second);
			minsol.first /= temp;
			minsol.second /= temp;
		}

		cout << minsol.first << " " << minsol.second << endl;

		cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2;
		//cout << "new testcase" << endl;
	}

    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt