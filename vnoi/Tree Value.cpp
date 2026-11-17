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
ll n, a[N + 1], ans[N + 1], bit[N + 1];
vector<ll> edge[N + 1];
vector<ll> b;

void updated(ll i, ll val) {
    for(; i <= b.size(); i += i & -i) bit[i] += val;
}

ll get(ll l, ll r) {
    ll sum = 0; l --;
    for(; l >= 1; l -= l & -l) sum -= bit[l];
    for(; r >= 1; r -= r & -r) sum += bit[r];
    return sum;
}

void read() {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        b.pb(a[i]);
    }

    sort(all(b)); b.erase(unique(all(b)), b.end());
    FOR(i, 1, n) {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
    }

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    updated(a[u], 1);
    for(auto i : edge[u]) if(i != par) {
        dfs(i, u);
        ans[i] = get(a[i] + 1, b.size());
    }
    updated(a[u], -1);
}

void solve() {
    dfs(1, -1);
    FOR(i, 1, n) cout << ans[i] << ' ';
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