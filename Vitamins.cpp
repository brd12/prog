#include <bits/stdc++.h>
using namespace std;


int main(){
	
	map<string, int> vitaminas;
	vitaminas["A"] = 300001;
	vitaminas["B"] = 300001; 	
	vitaminas["C"] = 300001;
	vitaminas["AB"] = 300001;
	vitaminas["BA"] = 300001;
	vitaminas["CB"] = 300001;
	vitaminas["BC"] = 300001;
	vitaminas["AC"] = 300001;
	vitaminas["CA"] = 300001;
	vitaminas["ACB"] = 300001;
	vitaminas["ABC"] = 300001;
	vitaminas["BCA"] = 300001;
	vitaminas["BAC"] = 300001;
	vitaminas["CAB"] = 300001;
	vitaminas["CBA"] = 300001;

	int n;
	cin >> n;

	int temp;
	string temp2;
	for(int k = 0; k < n; k++){
		cin >> temp >> temp2;
		vitaminas[temp2] = min(vitaminas[temp2], temp);
	}

	vitaminas["AB"] = min(vitaminas["AB"], vitaminas["BA"]);
	vitaminas["AC"] = min(vitaminas["AC"], vitaminas["CA"]);
	vitaminas["BC"] = min(vitaminas["CB"], vitaminas["BC"]);
	vitaminas["ABC"] = min(min(min(min(min(vitaminas["ABC"], vitaminas["ACB"]), vitaminas["BAC"]), vitaminas["BCA"]), vitaminas["CAB"]), vitaminas["CBA"]);

	if(vitaminas["AB"] == 300001 and vitaminas["AC"] == 300001 and vitaminas["A"] == 300001 and vitaminas["ABC"] == 300001){
		cout << -1 << endl;
	}

	else if(vitaminas["BC"] == 300001 and vitaminas["AC"] == 300001 and vitaminas["C"] == 300001 and vitaminas["ABC"] == 300001){
		cout << -1 << endl;
	}

	else if(vitaminas["AB"] == 300001 and vitaminas["BC"] == 300001 and vitaminas["B"] == 300001 and vitaminas["ABC"] == 300001){
		cout << -1 << endl;
	}

	else{
		int sol = min(vitaminas["ABC"], vitaminas["A"] + vitaminas["B"] + vitaminas["C"]);
		sol = min(sol, vitaminas["A"] + vitaminas["BC"]);
		sol = min(sol, vitaminas["AB"] + vitaminas["BC"]);
		sol = min(sol, vitaminas["B"] + vitaminas["AC"]);
		sol = min(sol, vitaminas["BC"] + vitaminas["AC"]);
		sol = min(sol, vitaminas["C"] + vitaminas["AB"]);
		sol = min(sol, vitaminas["AC"] + vitaminas["AB"]);

		cout << sol << endl;

	}

	return 0;
}
