#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1e5, mod = 1e9 + 7;
ll n, m, a[N + 1];

struct SegmentTree {
	struct NODE {
		ll val, add, mul;
	};

	vector<NODE> node;

	SegmentTree (ll n) {
		node.assign(4 * n + 1, {0, 0, 1});
	}

	void build(ll id, ll l, ll r) {
		if(l == r) {
			node[id].val = a[l];
			return;
		}

		ll mid = (l + r) >> 1;

		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);

		node[id].val = (node[id * 2].val + node[id * 2 + 1].val) % mod;
	}

	void push(ll id, ll l, ll r) {
		if(node[id].mul == 1 && node[id].add == 0) return;

		if(node[id].mul != 1) {
			ll k = node[id].mul; node[id].mul = 1;

			node[id * 2].val = (node[id * 2].val * k % mod) % mod;
			node[id * 2].mul = (node[id * 2].mul * k % mod) % mod;
			node[id * 2].add = (node[id * 2].add * k % mod) % mod;

			node[id * 2 + 1].val = (node[id * 2 + 1].val * k % mod) % mod;
			node[id * 2 + 1].mul = (node[id * 2 + 1].mul * k % mod) % mod;
			node[id * 2 + 1].add = (node[id * 2 + 1].add * k % mod) % mod;
		}

		if(node[id].add != 0) {
			ll k = node[id].add; node[id].add = 0;
			ll mid = (l + r) >> 1;

			node[id * 2].val = (node[id * 2].val + k * (mid - l + 1) % mod) % mod;
			node[id * 2].add = (node[id * 2].add + k % mod) % mod;

			node[id * 2 + 1].val = (node[id * 2 + 1].val + k * (r - mid) % mod) % mod;
			node[id * 2 + 1].add = (node[id * 2 + 1].add + k % mod) % mod;
		}

		return;
	}
	
	void add_node(ll id, ll l, ll r, ll val) {
		node[id].val = (node[id].val + val * (r - l + 1) % mod) % mod;
		node[id].add = (node[id].add + val) % mod;

		return;
	}

	void mul_node(ll id, ll l, ll r, ll val) {
		node[id].val = (node[id].val * val % mod) % mod;
		node[id].add = (node[id].add * val % mod) % mod;
		node[id].mul = (node[id].mul * val % mod) % mod;

		return;
	}

	void change_node(ll id, ll l, ll r, ll val) {
		node[id].val = val * (r - l + 1) % mod;
		node[id].mul = 0;
		node[id].add = val;

		return;
	}

	void updated(ll id, ll l, ll r, ll i, ll j, ll val, ll type) {
		if(l > j || r < i) return;
		if(i <= l && r <= j) {
			if(type == 1) {
				add_node(id, l, r, val);
			} else if(type == 2) {
				mul_node(id, l, r, val);
			} else {
				change_node(id, l, r, val);
			}

			return;
		}

		push(id, l, r);
		ll mid = (l + r) >> 1;

		updated(id * 2, l, mid, i, j, val, type);
		updated(id * 2 + 1, mid + 1, r, i, j, val, type);

		node[id].val = (node[id * 2].val + node[id * 2 + 1].val) % mod;
	}

	ll get(ll id, ll l, ll r, ll i, ll j) {
		if(l > j || r < i) return 0;
		if(i <= l && r <= j) return node[id].val;

		push(id, l, r);
		ll mid = (l + r) >> 1;

		return (get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j)) % mod;
	}

	void in(ll id, ll l, ll r) {
		if(l == r) {
			cout << node[id].val << ' ';
			return;
		}

		ll mid = (l + r) >> 1;

		in(id * 2, l, mid);
		in(id * 2 + 1, mid + 1, r);
	}
};

void read() {
	cin >> n >> m;
	for(ll i = 1; i <= n; i ++) {
		cin >> a[i];
	}
}
void solve() {
	SegmentTree node(n);
	node.build(1, 1, n);

	for(ll i = 1; i <= m; i ++) {
		ll x, l, r, k; cin >> x >> l >> r;

		if(x == 4) {
			cout << node.get(1, 1, n, l, r) << el;
		} else {
			cin >> k;
			node.updated(1, 1, n, l, r, k, x);
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