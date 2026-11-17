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

const ll N = 1e6;
ll n, k, ans = 0, high[N + 1], treeSize[N + 1], heavyTree[N + 1];
vector<ll> edge[N + 1];

map<ll, ll>* a[N + 1];

void read() {
    cin >> n >> k;
    
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfsSize(ll u, ll par) {
    treeSize[u] = 1;
    ll maxSize = 0;
    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfsSize(i, u);
        treeSize[u] += treeSize[i];
        if(treeSize[i] > maxSize) {
            maxSize = treeSize[i];
            heavyTree[u] = i; 
        }
    }
}

void dfsTree(ll u, ll par) {
    for(auto i : edge[u]) if(i != par && i != heavyTree[u]) {
        dfsTree(i, u);
    }

    if(heavyTree[u] == 0) {
        a[u] = new map<ll, ll>();
    } else {
        dfsTree(heavyTree[u], u);
        a[u] = a[heavyTree[u]];
    }

    for(auto i : edge[u]) if(i != par && i != heavyTree[u]) {
        for(auto &[x, y] : (*a[i])) {
            ll dis = k + 2 * high[u] - x;
            if((*a[u]).find(dis) != (*a[u]).end()) {
                ans += (*a[u])[dis] * y;
            }
        }

        for(auto &[x, y] : (*a[i])) {
            (*a[u])[x] += y; 
        }

        delete a[i];
    }

    ll dis = k + high[u];
    if((*a[u]).find(dis) != (*a[u]).end()) {
        ans += (*a[u])[dis];
    }
    (*a[u])[high[u]] ++;
}

void solve() {
    dfsSize(1, -1);
    dfsTree(1, -1);

    cout << ans;
}

void write() {

}

int main() {
    boost;
    // file("vnoi");
    read();
    solve();
    write();
    return 0;
}
