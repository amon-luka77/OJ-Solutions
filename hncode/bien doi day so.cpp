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

const ll N = 2e5;

ll n, q, a[N + 1], prefix[N + 1];

void read() {
	cin >> n >> q;
	for(ll i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for(ll i = 1; i <= n; i ++) {
		prefix[i] = prefix[i - 1] + a[i];
	}
	
}

void solve() {
	for(ll i = 1; i <= q; i ++) {
		ll x; cin >> x;
		
		ll l = 1, r = n, ans = -1;
		
		while(l <= r) {
			ll mid = (l + r) >> 1;
			
			if(a[mid] <= x) {
				l = mid + 1;
				ans = mid;
			} else {
				r = mid - 1;
			}
		}
		
		cout << (x * ans - prefix[ans]) + (prefix[n] - prefix[ans] - x * (n - ans)) << el;
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

