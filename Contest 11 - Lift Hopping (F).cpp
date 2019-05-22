#include<bits/stdc++.h>
using namespace std;

struct edge{
	int a, b, cost;
};

const int INF = 1e8;

vector<edge> e;

vector<int> d(100, INF);

void Bellman_Ford(vector<edge> e, int n, int m) //n = nodes, m = edges, v = vertice inicial
{
    d[0] = 0;
    vector<int> p (n);
    int x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1)
        return;
    else
    {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());
    }
}

int main(){
	int n, k; //numero de ascensores, piso_objetivo

	while(cin >> n >> k){
	   
        e.resize(0);
	    for(int k = 0; k < 100; k++){
	        d[k] = INF;
	    }   
	   
		int velocidades[n];

		int tempvel;
		
		for(int a = 0; a < n; a++){
			cin >> tempvel;
			velocidades[a] = tempvel;
		}

		string line;
		getline(cin, line);

		for(int a = 0; a < n; a++){
			getline(cin, line);

			vector<int> pisos;

			stringstream str;
			str << line;

			int counter = 0;

			int piso;
			while(str >> piso){
				pisos.emplace_back(piso);
				counter+= 1;
			}

			for(int k = 0; k < counter-1; k++){
				for(int j = k+1; j < counter; j++){
					edge tempedge = {pisos[k], pisos[j], velocidades[a]*(pisos[j]-pisos[k]) + 60};
					e.emplace_back(tempedge);
					tempedge = {pisos[j], pisos[k], velocidades[a]*(pisos[j]-pisos[k]) + 60};
					e.emplace_back(tempedge);
				}
			}
		}
		
		
		Bellman_Ford(e, 100, e.size());
		
		if(d[k] == INF){
			cout << "IMPOSSIBLE" << endl;
		}

		else if (k == 0){
			cout << 0 << endl;
		}
		else{
			cout << d[k] - 60 << endl;
		}
	}

	return 0;
}
