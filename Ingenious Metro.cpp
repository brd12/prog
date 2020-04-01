//Ingenious Metro https://www.urionlinejudge.com.br/judge/en/problems/view/1320

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> graph;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> frac;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define log(x) (31 - __buitlin_clz(x))
#define logg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd
#define lcm(a, b) a/gcd(a, b)*b

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t, q, temp, start, end;
    cin >> t >> q;

    while(t != 0 and q != 0){
        if(t == 1){
            cin >> temp;
            rep(a, 1, q){
                cin >> start >> end;
                if(end == start or end == 2*temp - start){
                    cout << "Y";
                }
                else{
                    cout << "N";
                }
                if(a != q){
                    cout << " ";
                }
            }
        }
        else{
            vi porters;
            int minport = 1000003;
            rep(a, 1, t){
                cin >> temp;
                porters.push_back(temp);
                minport = min(minport, temp);
            }

            int commongcd = 0;
            rep(a, 0, t-1){
                commongcd = gcd(commongcd, porters[a] - minport);
            }

            rep(a, 1, q){
                cin >> start >> end;
                start -= minport;
                end -= minport;

                if((start-end)%(2*commongcd) == 0 or (start+end)%(2*commongcd) == 0){
                    cout << "Y";
                }
                else{
                    cout << "N";
                }
                if(a != q){
                    cout << " ";
                }
            }
        }
        cout << endl;
        cin >> t >> q;
    }

    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt