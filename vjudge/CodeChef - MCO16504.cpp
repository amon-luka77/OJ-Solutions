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
ll n, m, q, s;
ll child[N + 1]; pair<ll, ll> canh[N + 1];
struct PLAN{ll type, x, y;}; PLAN plan[N + 1];
struct QUERY{ll u, v, cnt;}; QUERY query[N + 1];
ll parent[N + 1], sz[N + 1], sumChild[N + 1];
ll L[N + 1], R[N + 1], ans[N + 1];
bool mark[N + 1]; map<pair<ll, ll>, ll> edgeId;
vector<ll> bucket[N + 1];

ll find_set(ll k) {return k == parent[k] ? k : parent[k] = find_set(parent[k]);}

void union_set(ll u, ll v) {
    ll x = find_set(u), y = find_set(v);
    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x; sz[x] += sz[y]; sumChild[x] += sumChild[y];
    }
}

ll getSum(ll u, ll v) {
    return sumChild[find_set(u)] + sumChild[find_set(v)];
}

void read() {
    cin >> n >> m >> q >> s;
    FOR(i, 1, n) cin >> child[i];
    FOR(i, 1, n) {parent[i] = i; sz[i] = 1; sumChild[i] = child[i];}
    FOR(i, 1, m) {
        cin >> canh[i].ft >> canh[i].sc; union_set(canh[i].ft, canh[i].sc);
        if(canh[i].ft > canh[i].sc) swap(canh[i].ft, canh[i].sc);
        edgeId[{canh[i].ft, canh[i].sc}] = i;
    }
    FOR(i, 1, q) {
        cin >> plan[i].type >> plan[i].x >> plan[i].y;
        if(plan[i].type == 1 && plan[i].x > plan[i].y) swap(plan[i].x, plan[i].y);
        if(plan[i].type == 1) {plan[i].x = edgeId[{plan[i].x, plan[i].y}];}
    }
    FOR(i, 1, s) {
        cin >> query[i].u >> query[i].v >> query[i].cnt;
        L[i] = 1, R[i] = q, ans[i] = -1; 
        if(getSum(query[i].u, query[i].v) >= query[i].cnt) ans[i] = 0;
    }
}

void parallelBinarySearch() {
    while(1) {
        bool ok = 0;
        FOR(i, 1, q) bucket[i].clear();
        FOR(i, 1, s) if(L[i] <= R[i]) {
            ll mid = (L[i] + R[i]) >> 1;
            bucket[mid].pb(i); ok = 1;
        } if(!ok) break;

        memset(mark, 0, sizeof mark);
        FOR(i, 1, n) {parent[i] = i; sz[i] = 1; sumChild[i] = child[i];}
        FOR(i, 1, q) if(plan[i].type == 1) mark[plan[i].x] = 1;
        FOR(i, 1, m) if(!mark[i]) union_set(canh[i].ft, canh[i].sc);
        FOR(i, 1, q)  if(plan[i].type == 2) sumChild[find_set(plan[i].x)] -= plan[i].y;

        FORD(i, q, 1) {
            for(auto id : bucket[i]) {
                if(getSum(query[id].u, query[id].v) >= query[id].cnt) {
                    ans[id] = i; L[id] = i + 1;
                } else R[id] = i - 1;
            }
            if(plan[i].type == 1) union_set(canh[plan[i].x].ft, canh[plan[i].x].sc);
            else sumChild[find_set(plan[i].x)] += plan[i].y;
        }
    }
}

void solve() {
    parallelBinarySearch();
    FOR(i, 1, s) cout << ans[i] << el;
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