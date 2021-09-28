#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int r, c;
    cin >> r >> c;
    char MDT[r][c];
    int Histogram[r][c];
    int LeftLower[r];
    int RightLower[r];
    int sol = 0;
    rep(a, r){
        rep(b, c){
            cin >> MDT[a][b];
        }
        Histogram[a][c-1] = 1;
    }
    rep(a, r){
        for(int b = c-2; b >= 0; b--){
            Histogram[a][b] = 1 + Histogram[a][b+1]*(MDT[a][b] == MDT[a][b+1]);
        }
    }

    rep(b, c){
        stack<int> Lefty;
        stack<int> Righty;

        rep(a, r){
            while(!Lefty.empty()){
                if(Histogram[Lefty.top()][b] < Histogram[a][b]){
                    LeftLower[a] = Lefty.top();
                    Lefty.emplace(a);
                    break;
                }
                Lefty.pop();
            }
            if(Lefty.empty()){
                LeftLower[a] = -1;
                Lefty.emplace(a);
            }
            while(!Righty.empty()){
                if(Histogram[Righty.top()][b] < Histogram[r-1-a][b]){
                    RightLower[r-1-a] = Righty.top();
                    Righty.emplace(r-1-a);
                    break;
                }
                Righty.pop();
            }
            if(Righty.empty()){
                RightLower[r-1-a] = r;
                Righty.emplace(r-1-a);
            }
        }
        rep(a, r){
            sol = max(sol, min(Histogram[a][b], RightLower[a] - LeftLower[a] -1));
        }
    }
    cout << sol*sol << '\n';

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}