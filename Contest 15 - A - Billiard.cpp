#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



#define rep(i, a, b) for (size_t i = a; i < (size_t)b; i++)
#define gcd __gcd

ll lcm(ll a, ll b){
	return (a/gcd(a, b))*b;
}

ll modsum(ll a, ll b, ll mod){
	return (((a%mod) + (b%mod))%mod + mod)%mod;
}

ll modprod(ll a, ll b, ll mod){
	return (((a%mod) * (b%mod))%mod + mod)%mod;
}

void Extendedgcd(ll a, ll b, ll&g, ll& x, ll& y) {
	ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
	r2 = a, x2 = 1, y2 = 0;
	r1 = b, x1 = 0, y1 = 1;
	while (r1) {
		q = r2 / r1;
		r0 = r2 % r1;
		x0 = x2 - q * x1;
		y0 = y2 - q * y1;
		r2 = r1, x2 = x1, y2 = y1;
		r1 = r0, x1 = x0, y1 = y0;
	}
	g = r2, x = x2, y = y2;
}

pair<ll, ll> CRT(ll r1, ll m1, ll r2, ll m2){
	ll x, y, g;
	Extendedgcd(m1, m2, g, x, y);
	if ((r1 - r2)% g != 0){
		return {-1, -1};
	}
	ll temp = (m2/g);
	ll mcm = temp*m1;

	return {modsum(r1%mcm, m1*modprod(x%temp, ((r2-r1)/g)%temp, temp), mcm), mcm};	
}
int main(){

	int mesa_x, mesa_y, bola_x, bola_y, velocidad_x, velocidad_y;

	cin >> mesa_x >> mesa_y >> bola_x >> bola_y >> velocidad_x >> velocidad_y;


	if(velocidad_x != 0 and velocidad_y != 0){
		pair<ll, ll> sol = CRT(-1*velocidad_x*bola_x, mesa_x, -1*velocidad_y*bola_y, mesa_y);

		if (sol.first == -1){
			cout << -1 << endl;	
		}

		else{

			if(((bola_x + sol.first*velocidad_x)/mesa_x)%2 == 0){
				cout << 0 << " ";
			}

			else{
				cout << mesa_x << " ";
			}

			if(((bola_y + sol.first*velocidad_y)/mesa_y)%2 == 0){
				cout << 0 << endl;
			}

			else{
				cout << mesa_y << endl;
			}
		}
	}

	else if (velocidad_y != 0){
		if (bola_x != 0 and bola_x != mesa_x){
			cout << -1 << endl;
		} 
		else{
			if (velocidad_y > 0){
				cout << bola_x << " " << mesa_y << endl;
			}
			else{
				cout << bola_x << " " << 0 << endl;
			}
		}
	}

	else{
		if(bola_y != 0 and bola_y != mesa_y){
			cout << -1 << endl;
		}

		else{
			if (velocidad_x > 0){
				cout << mesa_x << " " << bola_y << endl;
			}
			else{
				cout << 0 << " " << bola_y << endl;
			}
		}
	}

	return 0;
}