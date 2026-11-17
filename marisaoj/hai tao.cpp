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

const ll N = 1e5;
ll n, A[N + 1], B[N + 1], treeSize[N + 1], heavy[N + 1], sum[N + 1];
vector<ll> edge[N + 1];

multiset<ll> *a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> A[i];
    FOR(i, 1, n) cin >> B[i];
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    treeSize[u] = 1;
    ll maxSize = 0;

    for(auto i : edge[u]) if(i != par) {
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(maxSize < treeSize[i]) {
            maxSize = treeSize[i];
            heavy[u] = i;
        }
    }
}


void dfsTree(ll u, ll par) {
    for(auto i : edge[u]) if(i != par && i != heavy[u]) {
        dfsTree(i, u);
    }

    if(heavy[u]) {
        dfsTree(heavy[u], u);
        a[u] = a[heavy[u]];
    } else {
        a[u] = new multiset<ll>();
    }

    sum[u] = sum[heavy[u]];

    for(auto i : edge[u]) if(i != par && i != heavy[u]) {
        sum[u] += sum[i];
        for(auto j : (*a[i])) (*a[u]).insert(j);
    }

    (*a[u]).insert(A[u]);
    sum[u] += A[u];

    while((*a[u]).size() > B[u]) {
        auto it = (*a[u]).begin();
        sum[u] -= *it;
        (*a[u]).erase(it); 
    }
}

void solve() {
    dfs(1, -1);
    dfsTree(1, -1);

    cout << sum[1];
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