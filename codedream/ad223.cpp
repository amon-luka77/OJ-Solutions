#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1 << (i))
using namespace std;

const ll N = 3e5, LOG = 20;
ll n, q, high[N + 1];
ll minHigh[2 * N][LOG + 1], minPos[N + 1][LOG + 1], maxPos[N + 1][LOG + 1];
ll state[N + 1], node[2 * N + 1], cntPos = 0, cnt = 0, pos[N + 1];

vector<ll> edge[N + 1];

void read() {
	cin >> n;
	
	FOR(i, 1, n - 1) {
		ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
	}
}

ll MINPOS(ll x, ll y) {
    return (state[x] < state[y] ? x : y);
}

ll MAXPOS(ll x, ll y) {
    return (state[x] > state[y] ? x : y);
}

void buildPos() {
    FOR(i, 1, n) {
        minPos[i][0] = i;
        maxPos[i][0] = i;
    }

    FOR(j, 1, LOG) FOR(i, 1, n - MASK(j) + 1) {
        minPos[i][j] = MINPOS(minPos[i][j - 1], minPos[i + MASK(j - 1)][j - 1]);
        maxPos[i][j] = MAXPOS(maxPos[i][j - 1], maxPos[i + MASK(j - 1)][j - 1]);
    }
}

ll getMinPos(ll l, ll r) {
    ll k = __lg(r - l + 1);

    return MINPOS(minPos[l][k], minPos[r - MASK(k) + 1][k]);
}

ll getMaxPos(ll l, ll r) {
    ll k = __lg(r - l + 1);

    return MAXPOS(maxPos[l][k], maxPos[r - MASK(k) + 1][k]);
}

ll MINHIGH(ll x, ll y) {
    return (high[x] < high[y] ? x : y);
}

void dfs(ll u, ll par){
	node[++cntPos] = u;
	pos[u] = cntPos;
	state[u] = ++cnt;
	for(auto i : edge[u]) if(i != par) {
		high[i] = high[u] + 1;
		dfs(i, u);
		node[++cntPos] = u;
	}
}

void prepare() {
	dfs(1, -1);
	FOR(i, 1, cntPos) minHigh[i][0] = node[i];
	FOR(j, 1, LOG) FOR(i, 1, cntPos - MASK(j) + 1) {
		minHigh[i][j] = MINHIGH(minHigh[i][j - 1], minHigh[i + MASK(j - 1)][j - 1]);
	}
}

ll lca(ll u, ll v) {
    ll pu = pos[u], pv = pos[v];
    if(pu > pv) swap(pu, pv);
    
    ll k = __lg(pv - pu + 1);

    return MINHIGH(minHigh[pu][k], minHigh[pv - MASK(k) + 1][k]);
}

void solve() {
	prepare();
    buildPos();

    cin >> q;

    while(q --) {
        ll x, y; cin >> x >> y;
        
        cout << lca(getMinPos(x, y), getMaxPos(x, y)) << el;
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
