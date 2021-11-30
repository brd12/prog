#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;  
typedef vector<vi> g;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> gll;
typedef vector<pair<ll, ll>> vpll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define pb push_back
#define endl '\n'
#define trav(a,x) for (auto& a: x)
#define gcd(a, b) __gcd(a, b)


bool vis[1<<20];
int score[1<<20];

int count(int k){
    int count=0;
    while(k!=0){
      k = k&(k-1);
      count++;
    }
    return count;
}

int n, m;
g mapa(20);

int solve2(int mask);

int solve(int mask){
    if(vis[mask]){
        return score[mask];
    }
    
    vis[mask] = true;
    int temp = -(1 << 21);
    
    int i = 1;
    for(int a = 0; a < n; a++){
        if(!(i & mask)){
            int tsol = 0;
            for(int k : mapa[a]){
                if(mask & (1<<k)){
                    tsol++;
                }
                else{
                    tsol--;
                }
            }
            temp = max(temp, tsol + solve2(mask + i));
        }
        i *= 2;
    }
    
    return score[mask] = temp;
    
}

int solve2(int mask){
    if(vis[mask]){
        return score[mask];
    }
    
    vis[mask] = true;
    int temp = 1 << 21;
    
    int i = 1;
    for(int a = 0; a < n; a++){
        if(!(i & mask)){
            int tsol = 0;
            for(int k : mapa[a]){
                int uff = 1 << k;
                if(mask & (1<<k)){
                    tsol--;
                }
                else{
                    tsol++;
                }
            }
            temp = min(temp, tsol + solve(mask + i));
        }
        i *= 2;
    }
    return score[mask] = temp;
}

    
int main(){
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    score[(1 << n) - 1] = 0;
    vis[(1<<n) - 1] = 1;
    
    
    int t1, t2;
    for(int a = 0; a < m; a++){
        cin >> t1 >> t2;
        mapa[t1-1].push_back(t2-1);
        mapa[t2-1].push_back(t1-1);
    }
    int sol = solve(0);
    if(sol < 0){
        cout << "player 2" << endl;
    }
    else if(sol > 0){
        cout << "player 1" << endl;
    }
    else{
        cout << "tie" << endl;
    }
    return 0;
}
