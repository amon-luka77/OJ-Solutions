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

const ll N = 1e5;
ll t, n, m, cnt = 0, scc = 0, num[N + 1], low[N + 1], inDeg[N + 1], comp[N + 1];
bool deleted[N + 1];
stack<ll> st;
vector<ll> edge[N + 1], newEdge[N + 1];
vector<pair<ll, ll>> canh;

void read() {
    cin >> t;
}

void dfs(ll u) {
    num[u] = low[u] = ++cnt;
    st.push(u);

    for(auto i : edge[u]) if(!deleted[i]) {
        if(num[i]) low[u] = min(low[u], num[i]);
        else {
            dfs(i);
            low[u] = min(low[u], low[i]);
        }
    }

    if(num[u] == low[u]) {
        ++scc;
        while(1) {
            ll v = st.top(); st.pop();
            deleted[v] = 1;
            comp[v] = scc;
            if(v == u) break;
        }
    }
}

void solve() {
    while(t --) {
        cin >> n >> m;

        canh.clear(); scc = 0; cnt = 0;
        FOR(i, 1, n) {
            edge[i].clear(); newEdge[i].clear();
            num[i] = 0; low[i] = 0; deleted[i] = 0;
            inDeg[i] = 0; comp[i] = 0;
        }

        vector<ll> c;
        
        FOR(i, 1, m) {
            ll x, y; cin >> x >> y;
            c.pb(x); c.pb(y);
            canh.pb({x, y});
            edge[x].pb(y);
        }

        sort(all(c)); c.erase(unique(all(c)), c.end());
        set<pair<ll, ll>> b;

        FOR(i, 0, c.size() - 1) if(!num[c[i]]) dfs(c[i]);
        // cout << el;
        // FOR(i, 1, n) cout << i << ' ' << comp[i] << el;
        // cout << el;

        for(auto &[i, j] : canh) if(comp[i] != comp[j] && b.find({comp[i], comp[j]}) == b.end()) {
            b.insert({comp[i], comp[j]});
            newEdge[comp[i]].pb({comp[j]});
            inDeg[comp[j]] ++;
        }

        ll cntDeg = 0; 
        // cout << scc << el;
        queue<ll> q;
        FOR(i, 1, scc) if(inDeg[i] == 0) {cntDeg ++; q.push(i);}

        if(cntDeg > 1) {cout << "NO"<< el; continue;}
        else {
            vector<ll> topo;
            while(!q.empty()) {
                ll v = q.front(); q.pop();
                for(auto i : newEdge[v]) {
                    inDeg[i] --;
                    if(inDeg[i] == 0) q.push(i);
                } 
            }

            bool ok = 1;
            FOR(i, 1, topo.size()) {
                if(b.find({topo[i - 1], topo[i]}) == b.end()) {ok = 0; break;}
            }
            if(ok) cout << "YES" << el;
            else cout << "NO" << el;
        }
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