#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> Prime_Divisors(3005, 0);

	for(int k = 2; k < 3005; k++){

		if (Prime_Divisors[k] == 0){

			for(int a = 2*k; a < 3005; a += k){

				Prime_Divisors[a] += 1;
			}
		}
	}

	int count = 0;

	for(int a = 1; a <= n; a++){
		if(Prime_Divisors[a] == 2){
			count += 1;
		}
	}
	
	cout << count << endl;

	return 0;
}