#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define gcd __gcd

ll positions[1002];
bool checklist[10002];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    ll cars, name, change;
    bool consistence;
    cin >> cars;
    
    while(cars > 0){
        consistence = true;
        memset(positions, -1, sizeof(positions));
        memset(checklist, false, sizeof(checklist));
        rep(k, 1, cars){
            cin >> name >> change;
            
            if(checklist[name]){
                consistence = false;
            }
            checklist[name] = true;
            
            if(change + k > cars or change + k < 1 or abs(change) > cars-1){
                consistence = false;
            }
            else{
                if(positions[change + k] != -1){
                    consistence = false;
                }
                positions[change + k] = name;
            }
        }
        
        if(consistence){
            rep(a, 1, cars-1){
                cout << positions[a] << " ";
            }
            cout << positions[cars] << endl;
        }
        else{
            cout << -1 << endl;
        }
        cin >> cars;
    }

    return 0;
}

//g++- -std=c++11 -O2 Temp.cpp && a.exe < in.txt > out.txt
