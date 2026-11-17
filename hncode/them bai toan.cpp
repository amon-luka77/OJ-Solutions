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
ll t, n, m, k;

void read() {
	cin >> t;
}

void solve() {
	while(t --) {
		cin >> n >> m >> k;
		vector<ll> a(n + 5, 0), b(m + 5, 0), c(k + 5, 0);
		ll ans = 0, end_x = 0, start_x = 0;
		ll cur = 0;
		
		for(ll i = 1; i <= n; i ++) {
			cin >> a[i];
			
			if(i > 1) {
				ll diff = a[i] - a[i - 1];
				if(ans < diff) {
					cur = ans;
					ans = a[i] - a[i - 1];
					start_x = i - 1;
					end_x = i;
				} else if(cur < diff) {
					cur = diff;
				}
			}
		}
		
		for(ll i = 1; i <= m; i ++) {
			cin >> b[i];
		}
		
		for(ll i = 1; i <= k; i ++) {
			cin >> c[i];
		}
		
		if(cur == ans) {
			cout << ans << el;
			continue;
		}
		
		sort(c.begin() + 1, c.begin() + k + 1);
		
		for(ll i = 1; i <= m; i ++) {

			ll l = 1, r = k, pos = -1;
			
			while(l <= r) {
				ll mid = (l + r) >> 1;
				
				if(b[i] + c[mid] <= (a[start_x] + a[end_x]) >> 1) {
					l = mid + 1;
					pos = mid;
				} else {
					r = mid - 1;
				}
			}

			if(pos == -1) continue;

			for(ll j = pos; j <= pos + 1; j ++) {
				if(j > k) continue;

				if(b[i] + c[j] < a[start_x] || b[i] + c[j] > a[end_x]) continue;
				
				ans = min(ans, max({cur, (b[i] + c[j]) - a[start_x], a[end_x] - (b[i] + c[j])}));
			}

		}
		
		cout << ans << el;
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


