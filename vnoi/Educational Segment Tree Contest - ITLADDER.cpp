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
ll n, q, a[N + 1];

struct SegmentTree{
	struct NODE {
		ll val, lazy_A, lazy_B;
	};
	
	vector<NODE> node;
	
	SegmentTree(ll n) {
		node.assign(4 * n + 1, {0, 0, 0});
	}
	
	void apply(ll id, ll l, ll r, ll A, ll B) {
		ll sum = (r + l) * (r - l + 1) / 2 % mod;
		
		node[id].val = (node[id].val + (r - l + 1) * B % mod + sum * A % mod) % mod;
		
		node[id].lazy_A = (node[id].lazy_A + A) % mod;
		node[id].lazy_B = (node[id].lazy_B + B) % mod;
		
	}
	
	void push(ll id, ll l, ll r) {
		if(node[id].lazy_A == 0 && node[id].lazy_B == 0) return;
		ll A = node[id].lazy_A, B = node[id].lazy_B;
		node[id].lazy_A = 0, node[id].lazy_B = 0;
		
		ll mid = (l + r) >> 1;
		
		apply(id * 2, l, mid, A, B);
		apply(id * 2 + 1, mid + 1, r, A, B);
		
		return;
	}
	
	void updated(ll id, ll l, ll r, ll i, ll j, ll A, ll B) {
		if(l > j || r < i) return;
		if(i <= l && r <= j) {
			apply(id, l, r, A, B);
			return;
		}
		
		push(id, l, r);
		
		ll mid = (l + r) >> 1;
		
		updated(id * 2, l, mid, i, j, A, B);
		updated(id * 2 + 1, mid + 1, r, i, j, A, B);
		
		node[id].val = (node[id * 2].val + node[id * 2 + 1].val) % mod;
	}
	
	ll get(ll id, ll l, ll r, ll i, ll j) {
		if(l > j || r < i) return 0;
		if(i <= l && r <= j) return node[id].val % mod;
		
		push(id, l, r);
		
		ll mid = (l + r) >> 1;
		
		return (get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j)) % mod;
	}
	
	void print(ll id, ll l, ll r) {
		if(l == r) {
			cout << node[id].val << ' ';
			return;
		}
		
		push(id, l, r);
		
		ll mid = (l + r) >> 1;
		
		print(id * 2, l, mid);
		print(id * 2 + 1, mid + 1, r);
	}
};

void read() {
	cin >> n >> q;
}
void solve() {
	SegmentTree node(n);
	
	for(ll i = 1; i <= q; i ++) {
		ll x, l, r, A, B; cin >> x >> l >> r;
		if(x == 1) {
			cin >> A >> B;
			B -= A * l;
			node.updated(1, 1, n, l, r, A % mod, (mod + B % mod) % mod);
		} else {
			cout << node.get(1, 1, n, l, r) << el;
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
/*
5 4
1 1 5 1 1
-> 1 2 3 4 5
2 1 5
-> 15
1 2 3 1 1
-> 1 3 5 4 5
2 1 5
-> 18
*/
