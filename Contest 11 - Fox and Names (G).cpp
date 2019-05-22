//Bellman-Ford y estructura de grafos desde https://cp-algorithms.com/graph/bellman_ford.html#toc-tgt-6

#include <bits/stdc++.h>
using namespace std;

struct edge{
	int a, b, cost;
};

vector<edge> e;

const int INF = 1e8;
char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
bool consistence_check = false;
bool size_check = true;
int aristas = 0;

vector<int> d (27, INF);

void Bellman_Ford(vector<edge> e, int n, int m){
	d[26] = 0;
	vector<int> p (n);
	int x;
	for (int i=0; i<n; ++i)
	{
		x = -1;
		for (int j=0; j<m; ++j)
			if (d[e[j].a] < INF){
				if (d[e[j].b] > d[e[j].a] + e[j].cost){
					d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
					p[e[j].b] = e[j].a;
					x = e[j].b;
				}
			}
	}

	if (x == -1){
		consistence_check = true;
	}
}


void compare_strings(string string1, string string2){
	int size1 = string1.size();
	int size2 = string2.size();

	int minsize = min(size1, size2);
	
	bool failsafe = true;

	for(int a = 0; a < minsize; a++){
		if(string1[a] != string2[a]){
			edge tempedge = {string1[a]- 'a', string2[a] - 'a', -1};
			e.emplace_back(tempedge);
			aristas += 1;
			failsafe = false;
			break;
		}
	}

	if (size1 > size2 and failsafe){
		size_check = false;
	}

}

int main(){

	vector<string> lexico;

	int cantidad;
	cin >> cantidad;

	string temp;

	for(int k = 0; k < cantidad; k++){
		cin >> temp;
		lexico.emplace_back(temp);
	}

	for(int a = 0; a < cantidad-1; a++){
		compare_strings(lexico[a], lexico[a+1]);
	}

	for(int k = 0; k < 26; k++){
		edge tempedge = {26, k, 0};
		e.emplace_back(tempedge);
	}

	aristas += 26;

	if(size_check){
		Bellman_Ford(e, 27, aristas);
	}

	if(consistence_check){
		for(int k = 0; k > -26; k--){
			for(int a = 0; a < 26; a++){
				if(d[a] == k){
					cout << alphabet[a];
				}
			}
		}
	}
	
	else{
		cout << "Impossible";
	}
	
	return 0;
}