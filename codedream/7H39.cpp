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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 2e5;
ll n, m, cntBridge = 0, cnt = 0, a[N + 1], num[N + 1], low[N + 1], comp[N + 1], sizeBridge[N + 1];
bool isBridge[N + 1];

struct A {
    ll x, y, z;
};

vector<A> edge[N + 1];
A canh[N + 1];
vector<pair<ll, ll>> newEdge[N + 1];
vector<ll> childScc[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        canh[i] = {x, y, z};
        edge[x].pb({y, z, i});
        edge[y].pb({x, z, i});
    }
}

void dfs(ll u, ll id) {
    num[u] = low[u] = ++cnt;

    for(auto &[i, j, k] : edge[u]) if(k != id) {
        if(num[i]) low[u] = min(low[u], num[i]);
        else {
            dfs(i, k);
            low[u] = min(low[u], low[i]);
            if(low[i] > num[u]) isBridge[k] = 1;
        }
    } 
}

void dfsBridge(ll u) {
    comp[u] = cntBridge;
    sizeBridge[cntBridge] ++;
    childScc[cntBridge].pb(u);

    for(auto &[i, j, k] : edge[u]) if(!comp[i] && !isBridge[k]) {
        dfsBridge(i);
    }
}

namespace Sub1 {
    bool check() {
        return n <= 10000;
    }
    ll ans = 0;

    void dfsAns(ll u, ll par, ll val) {
        for(auto &[i, j] : newEdge[u]) if(i != par) {
            ans += sizeBridge[i] * min(val, j);

            dfsAns(i, u, min(val, j));
        }
    }

    void solve() {
        FOR(i, 1, n) {
            ans = 0;

            dfsAns(comp[i], 0, a[i]);

            cout << ans + a[i] * (sizeBridge[comp[i]] - 1) << el;
        }
    }
}

namespace Sub2 {
    bool check() {
        ll W = canh[1].z;
        FOR(i, 2, m) if(W != canh[i].z) return 0;
        return 1;
    }

    void solve() {
        ll W = canh[1].z;
        FOR(i, 1, n) {
            cout << (n - sizeBridge[comp[i]]) * min(W, a[i]) + (sizeBridge[comp[i]] - 1) * a[i] << el;
        }
    }
}

namespace Sub3 {
    bool check() {
        return 1;
    }

    ll parent[2 * N + 1], sz[2 * N + 1], dsuVal[2 * N + 1], sizeDsuTree[2 * N + 1];
    ll cntPar = 0, ans[N + 1], prefix[2 * N + 1], prefixCnt[2 * N + 1], parDsu[2 * N + 1];
    vector<ll> dsuEdge[2 * N + 1]; vector<pair<ll, ll>> b;

    ll find_set(ll k) {
        return k == parent[k] ? k : parent[k] = find_set(parent[k]);
    }

    void union_set(ll u, ll v, ll w) {
        ll x = find_set(u), y = find_set(v);

        if(x != y) {
            ll Par = ++cntPar;
            // cerr << x << ' ' << y << ' ' << Par << el;
            parent[x] = Par;
            parent[y] = Par;
            parent[Par] = Par;

            dsuEdge[Par].pb(x);
            dsuEdge[Par].pb(y);
            dsuVal[Par] = w;
        }
    } 

    void preDfs(ll u, ll par) {
        parDsu[u] = par;
        if(dsuEdge[u].empty()) {sizeDsuTree[u] = sizeBridge[u]; return;}

        for(auto i : dsuEdge[u]) {
            preDfs(i, u);
            sizeDsuTree[u] += sizeDsuTree[i];
        }
    }

    ll binaryPos(ll target) {
        ll l = 1, r = b.size() - 1, pos = 0;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(b[mid].sc < target) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return pos;
    }

    void dfsDsu(ll u) {
        ll AMON = b.size();
        if(u != cntPar) {
            b.pb({sizeDsuTree[parDsu[u]] - sizeDsuTree[u], dsuVal[parDsu[u]]});
            prefix[AMON] = prefix[AMON - 1] + b.back().ft * b.back().sc; 
            prefixCnt[AMON] = prefixCnt[AMON - 1] + b.back().ft;
            // cerr << parDsu[u] << ' ' << u << ' ' << dsuVal[parDsu[u]] << el;
        }

        if(dsuEdge[u].empty()) {
            // cerr << "SCC la: " << u << el;
            // cerr << el;
            for(auto i : childScc[u]) {
                ll x = binaryPos(a[i]);
                // cerr << i << ' ' << x << ' ';
                if(x) {
                    ans[i] = prefix[x] + (prefixCnt[AMON] - prefixCnt[x]) * a[i]; 
                    // cerr << prefix[x] + (prefixCnt[AMON] - prefixCnt[x]) * a[i] << " loai1\n";
                }
                else {
                    ans[i] = prefixCnt[AMON] * a[i]; 
                    // cerr <<  prefixCnt[AMON] * a[i] << " loai 2\n";
                }
            //     cerr << ans[i] << ' ';
            // }
            }
        }

        for(auto i : dsuEdge[u]) {
            dfsDsu(i);
        }

        b.pop_back(); prefix[AMON] = 0; prefixCnt[AMON] = 0;
    }

    void solve() {
        vector<ll> newDsu; FOR(i, 1, cntBridge) {parent[i] = i;}
        FOR(i, 1, m) if(isBridge[i]) {
            newDsu.pb(i);
        }

        sort(all(newDsu), [](ll x, ll y) {
            return canh[x].z > canh[y].z;
        });


        // cerr << el;
        cntPar = cntBridge;

        for(auto i : newDsu) {
            union_set(comp[canh[i].x], comp[canh[i].y], canh[i].z);
            // cerr << comp[canh[i].x] << ' ' << comp[canh[i].y] << ' ' << canh[i].z << el;
        }

        b.pb({0, 0});
        preDfs(cntPar, 0);
        dfsDsu(cntPar);

        // FOR(i, 1, cntPar) {
        //     cerr << cntPar << el;
        //     for(auto i : dsuEdge[i]) cerr << i << ' ';
        //     cerr << el;
        // }

        FOR(i, 1, n) cout << ans[i] + (sizeBridge[comp[i]] - 1) * a[i] << el; 
    }
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i, 0);
    FOR(i, 1, n) if(!comp[i]) {cntBridge ++; dfsBridge(i);}

    FOR(l, 1, m) if(isBridge[l]) {
        auto [i, j, k] = canh[l];
        // cout << comp[i] << ' ' << comp[j] << ' ' << k << el;
        newEdge[comp[i]].pb({comp[j], k});
        newEdge[comp[j]].pb({comp[i], k});
    }

    if(Sub1::check()) {Sub1::solve(); return;}
    if(Sub2::check()) {Sub2::solve(); return;}
    if(Sub3::check()) {Sub3::solve(); return;}
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