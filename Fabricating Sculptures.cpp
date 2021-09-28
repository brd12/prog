#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int DP[5000][5000];

int solve(int blocks, int base){
    if(base <= 0 or blocks < 0){
        return 0;
    }
    if(DP[blocks][base] != -1){
        return DP[blocks][base];
    }
    if(blocks == 0){
        return DP[blocks][base] = 1;
    }
    if(base == 1){
        return DP[blocks][base] = 1;
    }

    return DP[blocks][base] = (MOD + (2*solve(blocks, base-1)%MOD +(-solve(blocks, base-2) + solve(blocks-base, base))%MOD)%MOD)%MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(DP, -1, sizeof(DP));

    int blocks, base;
    cin >> base >> blocks;
    blocks -= base;
    cout << solve(blocks, base) << '\n';

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}