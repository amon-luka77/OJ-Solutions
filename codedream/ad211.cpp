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

const ll N = 1e6;
ll n, a[N + 1], parent[N + 1], sz[N + 1];

struct QUERY {
    ll x, y, minN, maxN;
};

QUERY query[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        query[i] = {x, y, min(a[x], a[y]), max(a[x], a[y])};
    }
}

#define getMin(x) min(a[x.ft], a[x.sc])
#define getMax(x) max(a[x.ft], a[x.sc])

ll find_set(ll k) {
    return k == parent[k] ? k : parent[k] = find_set(parent[k]);
}

ll union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        ll cnt = sz[x] * sz[y];
        sz[x] += sz[y];

        return cnt;
    }

    return 0;
}

void solve() {
    ll ans = 0;    
    
    FOR(i, 1, n) {
        parent[i] = i;
        sz[i] = 1;
    }

    sort(query + 1, query + n, [](const QUERY &x, const QUERY &y) {
        return x.minN > y.minN;
    });

    FOR(i, 1, n - 1) {
        ll j = i; ll k = query[i].minN;
        while(j <= n - 1 && k == query[j].minN) {
            // cout << query[j].ft << ' ' << query[j].sc << ' ' << k << el;
            ans -= union_set(query[j].x, query[j].y) * k;
            j ++;
        }
        i = j - 1;
    }

    // cout << ans << el;

    FOR(i, 1, n) {
        parent[i] = i;
        sz[i] = 1;
    }

    sort(query + 1, query + n, [](const QUERY &x, const QUERY &y) {
        return x.maxN < y.maxN;
    });

    FOR(i, 1, n - 1) {
        ll j = i; ll k = query[i].maxN;
        while(j <= n - 1 && k == query[j].maxN) {
            // cout << query[j].ft << ' ' << query[j].sc << ' ' << k << el;
            // if(j == query.size() - 1) cout << sz[find_set(query[j].ft)] << ' ' << sz[find_set(query[j].sc)] << el;
            // ll t = union_set(query[j].ft, query[j].sc); cout << t << el;
            ans += union_set(query[j].x, query[j].y) * k;
            j ++;
        }
        i = j - 1;
    }

    cout << ans;
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