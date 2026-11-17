/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 2e5;
ll n, sizeTree[N + 1];
bool vs[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfsSize(ll u, ll par) {
    sizeTree[u] = 1;

    for(auto i : edge[u]) if(i != par && !vs[i]) {
        dfsSize(i, u);
        sizeTree[u] += sizeTree[i];
    }
}

ll findCentroid(ll u, ll par, ll curSize) {
    for(auto i : edge[u]) if(i != par && !vs[i]) {
        if(sizeTree[i] > curSize / 2) return findCentroid(i, u, curSize);
    }
    
    return u;
} 

void solve() {
    dfsSize(1, -1);
    cout << findCentroid(1, -1, n);
}

void write() {

}

int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}