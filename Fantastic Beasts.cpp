//Fantastic Beasts https://www.urionlinejudge.com.br/judge/en/problems/view/2908

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> graph;
typedef vector<ll> vll;
typedef pair<ll, ll> frac;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define log(x) (31 - __buitlin_clz(x))
#define logg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd
#define lcm(a, b) a/gcd(a, b)*b


int beast_pos[12];
int patron[12][105];
int howmany[105];
bool isVisited[12][105];
int CRTInfo[12][105]; //index [x][104] stores the length of the loop!
bool hasLooped[12];
int loopedbois = 0;

void Advance(int beast){
    howmany[beast_pos[beast]] -= 1;
    //cout << "Movement: beast " << beast << " from " << beast_pos[beast] << " to " << patron[beast][beast_pos[beast]] << endl;
    beast_pos[beast] = patron[beast][beast_pos[beast]];
    howmany[beast_pos[beast]] += 1;
    if(isVisited[beast][beast_pos[beast]] and !hasLooped[beast]){
        hasLooped[beast] = true;
        loopedbois += 1;
    }
    isVisited[beast][beast_pos[beast]] = true;
}

ll inline mod(ll x, ll m) { return ((x %= m) < 0) ? x+m : x; }
ll inline mult(ll x, ll y, ll m) { return (x * y) % m; }
ll inline add(ll x, ll y, ll m) { return (x + y) % m; }
void Extendedgcd(ll a, ll b, ll& g, ll& x, ll& y) {
    ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
    r2 = a, x2 = 1, y2 = 0;
    r1 = b, x1 = 0, y1 = 1;
    while (r1) {
        q = r2 / r1;
        r0 = r2 % r1;
        x0 = x2 - q * x1;
        y0 = y2 - q * y1;
        r2 = r1, x2 = x1, y2 = y1;
        r1 = r0, x1 = x0, y1 = y0;        
    }
    g = r2, x = x2, y = y2;
}
pair<ll,ll> CRT(vector<ll>& r, vector<ll>& m) {
    int n = r.size();
    // assert (n > 1);
    ll r1 = r[0], m1 = m[0];
    rep(i,1,n-1) {
        ll r2 = r[i], m2 = m[i];
        ll g, x, y; Extendedgcd(m1, m2, g, x, y);
        if ((r1 - r2) % g != 0) return {-1, -1}; // no solution
        ll z = m2/g;
        ll lcm = m1 * z;
        ll sol = add(mod(r1, lcm), m1*mult(mod(x,z),mod((r2-r1)/g,z),z), lcm);
        r1 = sol;
        m1 = lcm;
    }
    // rep(i,0,n-1) assert (r1 % m[i] == r[i]);
    return {r1, m1};
}




int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    memset(isVisited, false, sizeof(isVisited));
    memset(howmany, 0, sizeof(howmany));
    memset(hasLooped, false, sizeof(hasLooped));
    memset(CRTInfo, -1, sizeof(CRTInfo));

    int b, z, delay, loopsize;
    cin >> b >> z;
    rep(oof, 1, b){
        cin >> beast_pos[oof];
        howmany[beast_pos[oof]] += 1;
        rep(uff, 1, z){
            cin >> patron[oof][uff];
        }
    }
    if(howmany[beast_pos[1]] == b){
        cout << beast_pos[1] << " 0" << endl;
        return 0;
    }
    delay = 0;

    while(loopedbois < b){
        delay += 1;
        rep(a, 1, b){
            Advance(a);
        }
        if(howmany[beast_pos[1]] == b){
            cout << beast_pos[1] << " " << delay << endl;
            return 0;
        }
    }

    rep(a, 1, b){
        loopsize = 1;
        CRTInfo[a][beast_pos[a]] = 0;
        Advance(a);
        while(CRTInfo[a][beast_pos[a]] == -1){
            loopsize += 1;
            CRTInfo[a][beast_pos[a]] = loopsize-1;
            Advance(a);
        }
        CRTInfo[a][104] = loopsize;
    }

    ll minsol = -1;
    ll zoosol;

    rep(zoo, 1, z){

        vector<ll> restos, mods;
        bool consistency_check = true;
        rep(bestia,1,b) {
            restos.push_back(CRTInfo[bestia][zoo]);
            if (restos.back() == -1) {
                consistency_check = false;
                break;
            }
            mods.push_back(CRTInfo[bestia][104]);
        }
        pair<ll, ll> solucion;
        if(consistency_check){
            solucion = CRT(restos, mods);
        }
        else{
            solucion = {-1, -1};
        }

        // pair<ll, ll> solucion = CRT(CRTInfo[1][zoo], CRTInfo[1][104], CRTInfo[2][zoo], CRTInfo[2][104]);
        // rep(bestia, 3, b){
        //     solucion = CRT(solucion.first, solucion.second, CRTInfo[bestia][zoo], CRTInfo[bestia][104]);
        // }


        if(solucion.first != -1){
            if(minsol != -1 and solucion.first + delay < minsol){
                minsol = solucion.first + delay;
                zoosol = zoo;
            }
            else if(minsol == -1){
                minsol = solucion.first + delay;
                zoosol = zoo;
            }
        }
    }

    if(minsol != -1){
        cout << zoosol << " " << minsol << endl;
    }
    else{
        cout << "*" << endl;
    }
    
    return 0;
}

//g++ -std=c++11 -O2 Temp.cpp && a.exe <in.txt> out.txt