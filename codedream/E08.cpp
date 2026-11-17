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

const ll N = 3e5;
ll n, m, cl = 1, color[N + 1], a[N + 1];
vector<ll> edge[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void paint(ll u) {
    map<ll, ll> x;
    for(auto i : edge[u]) if(i != u & color[i] != 0) {
        x[color[i]] ++;
    }

    for(auto &[i, j] : x) {
        if(a[i] == j) {
            color[u] = i;
            a[i] ++;
            return;
        }
    }

    color[u] = cl;
    a[cl] ++;
    cl ++;
}

void solve() {
    FOR(i, 1, n) if(color[i] == 0) {
        paint(i);
    }

    FOR(i, 1, n) cout << color[i] << ' ';
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