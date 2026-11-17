/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 2e5;
const ll maxN = 1e7;
const ll maxSnt = 664582;
ll n, q;
ll a[N + 1], ans[N + 1];
ll node[4 * maxSnt + 1];
bool checkSnt[maxN + 1]; ll fac[maxN + 1], posSnt[maxN + 200]; vector<ll> snt;
vector<pair<ll, ll>> lastPos[N + 1];

void sang() {
    FOR(i, 2, maxN) checkSnt[i] = 1;
    for(ll i = 2; i * i <= maxN; i ++) if(checkSnt[i]) {
        for(ll j = i * i; j <= maxN; j += i) {
            checkSnt[j] = 0; 
            if(!fac[j]) fac[j] = i;
        }
    }
    
    ll pos = 0; snt.pb(0);
    FOR(i, 1, maxN) if(checkSnt[i]) {
        snt.pb(i); posSnt[i] = ++pos;
        if(!fac[i]) fac[i] = i;
    }

    snt.pb(10000019); posSnt[10000019] = ++pos;
    // FOR(i, 1, 20) cerr << i << " " << fac[i] <<  " co phai snt khong: " << checkSnt[i] << el;
}

void read() {
    sang(); cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        lastPos[y].pb({x, i});
    }
}

void updated(ll id, ll l, ll r, ll i, ll val) {
    if(l == r) return node[id] = val, void();
    ll mid = (l + r) >> 1;
    if(i <= mid) updated(id << 1, l, mid, i, val);
    else updated(id << 1 | 1, mid + 1, r, i, val);
    node[id] = min(node[id << 1], node[id << 1 | 1]);
}

ll get(ll id, ll l, ll r, ll i) {
    if(l == r) return l;
    ll mid = (l + r) >> 1;
    if(node[id << 1] < i) return get(id << 1, l, mid, i);
    else return get(id << 1 | 1, mid + 1, r, i);
}

void solve() {
    FOR(i, 1, n) {
        ll x = a[i];
        while(x > 1) {
            ll y = fac[x];
            while(x % y == 0) x /= y;
            updated(1, 1, maxSnt, posSnt[y], i);
        }
        
        for(auto &[val, id] : lastPos[i]) {
            ans[id] = snt[get(1, 1, maxSnt, val)];
        }
    }
    
    FOR(i, 1, q) cout << ans[i] << el;
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}

// 7e