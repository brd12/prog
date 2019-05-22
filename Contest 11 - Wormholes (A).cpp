//Bellman-Ford y estructura de grafos desde https://cp-algorithms.com/graph/bellman_ford.html#toc-tgt-6

#include <bits/stdc++.h>
using namespace std;

struct edge{
	int a, b, cost;
};

const int INF = 1e8;

void Bellman_Ford(vector<edge> e, int n, int m){
	vector<int> d (n, INF);
	d[0] = 0;
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

	if (x == -1)
		cout << "not possible";
	else
	{
		cout << "possible";
	}
}

int main(){

	int cases;
	cin >> cases;
	for(int a = 0; a < cases; a++){

		int n, m; //nodes, edges
		vector<edge> e;

		int tempa, tempb, tempcost;

		cin >> n >> m;

		for(int k = 0; k < m; k++){
			cin >> tempa >> tempb >> tempcost;
			edge tempedge = {tempa, tempb, tempcost};
			e.emplace_back(tempedge);
		}

		Bellman_Ford(e, n, m);
		cout << endl;
	}

	return 0;
}