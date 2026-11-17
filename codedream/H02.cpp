#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (int i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 100001;
ll n, cnt = 0, parent[N + 1], sz[N + 1]; 

vector<pair<ll, ll>> edge[N + 1];

bool sub3 = 1;

struct QUERY {
    ll x, y, z;
};

vector<QUERY> query;

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void union_set(ll u, ll v) {
    ll x = find_set(u), y = find_set(v);
    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        cnt --;
    }
}

multiset<pair<ll, ll>> node;

void read() {
    cin >> n;
    FOR(i, 1, n) {
        ll x, y; cin >> x >> y;
        query.pb({x, y, i});
        if(y - x > 20) sub3 = 0;
    }
}

void solve() {    
    if(sub3) {
        map<pair<ll, ll>, ll> check;
        FOR(v, 0, n - 1) {
            auto [i, j, t] = query[v];
            FOR(k, 1, 21) {
                FOR(l, i, j - k + 1) {
                    ll r = l + k - 1;
                    if(check.find({l, r}) != check.end()) {
                        edge[t].pb({t, check[{l, r}]});
                    }
                }            
                
                FOR(l, j - k + 1, i) {
                    ll r = l + k - 1;
                    if(l <= i && j <= r && check.find({l, r}) != check.end()) {
                        edge[t].pb({t, check[{l, r}]});
                    }
                }
            }

            check[{i, j}] = t;
        }
    } else {
        sort(all(query), [](const QUERY &x, const QUERY &y) {
            if(x.x != y.x) return x.x < y.x;
            return x.y > y.y;
        });
        FOR(i, 0, n - 1) {
            auto [l, r, t] = query[i];

            auto it = node.lower_bound({r, -1e9});
            auto cur = it;
            if(it != node.end()) {
                while(it != node.end()) {
                    auto [x, y] = *it;
                    it = next(it);
                    edge[max(y, t)].pb({y, t});
                }
            }
            
            if(n <= 2000) node.insert({r, t});
            else if(cur == node.end()) node.insert({r, t});
        }        
    }
    
    FOR(i, 1, n) {
        cnt ++; parent[i] = i, sz[i] = 1;
        for(auto &[x, y] : edge[i]) {
            union_set(x, y);
        } 
        cout<< cnt << el;
    }
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