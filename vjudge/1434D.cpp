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

const ll N = 5e5;
ll n, q, r1, r2, high[N + 1];
pair<ll, ll> canh[N + 1];
vector<pair<ll, ll>> edge[N + 1];

void read() {
	cin >> n;
	FOR(i, 1, n - 1) {
		ll x, y, z; cin >> x >> y >> z;
		edge[x].pb({y, z}); edge[y].pb({x, z});
		canh[i] = {x, y};
	}
}

void dfs(ll u, ll par) {
	for(auto &[i, j] : edge[u]) if(i != par) {
		high[i] = high[u] + 1;
		dfs(i, u);
	}
}

struct GRAPH {
	ll root, cnt = 0;
	ll startTour[N + 1], endTour[N + 1], high[N + 1], val[N + 1];
	ll node[N << 2][2], lazy[N << 2], a[N + 1], b[N + 1];

	void dfs(ll u, ll par, ll x) {
		startTour[u] = ++cnt; high[u] = high[par] + 1; val[u] = x;
		a[startTour[u]] = x; b[startTour[u]] = high[u] - 1;
		for(auto &[i, j] : edge[u]) if(i != par) {
			dfs(i, u, x ^ j);
		}
		endTour[u] = cnt;
	}

	void build(ll id, ll l, ll r) {
		if(l == r) return node[id][a[l]] = b[l], void();
		ll mid = (l + r) >> 1; build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
		node[id][0] = max(node[id << 1][0], node[id << 1 | 1][0]);
		node[id][1] = max(node[id << 1][1], node[id << 1 | 1][1]);
	}

	void push(ll id) {
		if(lazy[id]) {
			ll k = lazy[id]; lazy[id] = 0;
			swap(node[id << 1][0], node[id << 1][1]); lazy[id << 1] ^= k;
			swap(node[id << 1 | 1][0], node[id << 1 | 1][1]); lazy[id << 1 | 1] ^= k;
		}
	}

	void updated(ll id, ll l, ll r, ll i, ll j) {
		if(l == i && r == j) {
			swap(node[id][0], node[id][1]);
			lazy[id] ^= 1; return;
		}

		ll mid = (l + r) >> 1; push(id);
		if(j <= mid) updated(id << 1, l, mid, i, j);
		else if(i > mid) updated(id << 1 | 1, mid + 1, r, i, j);
		else updated(id << 1, l, mid, i, mid), updated(id << 1 | 1, mid + 1, r, mid + 1, j);

		node[id][0] = max(node[id << 1][0], node[id << 1 | 1][0]);
		node[id][1] = max(node[id << 1][1], node[id << 1 | 1][1]);
	}

	void prepare() {
		dfs(root, 0, 0); build(1, 1, n);
	}

	ll getAns(ll k) {
		ll u = canh[k].ft, v = canh[k].sc;
		if(high[u] < high[v]) swap(u, v);
		updated(1, 1, n, startTour[u], endTour[u]);
		return node[1][0];
	}
} amon, klein;

void solve() {
	dfs(1, 0); FOR(i, 1, n) if(high[i] > high[r1]) r1 = i;
	memset(high, 0, sizeof high);
	dfs(r1, 0); FOR(i, 1, n) if(high[i] > high[r2]) r2 = i;
	amon.root = r1, klein.root = r2;
	// cerr << "begin\n";
	amon.prepare(); klein.prepare();
	// cerr << "end\n";
	cin >> q;
	FOR(i, 1, q) {
		ll x; cin >> x;
		cout << max(amon.getAns(x), klein.getAns(x)) << el;
	}
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