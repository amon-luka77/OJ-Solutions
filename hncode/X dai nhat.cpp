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

string s;
ll n, k, prefix[N + 1];

void read() {
	cin >> s >> k;
	n = s.size();
	s = ' ' + s;

}

void solve() {
	for(ll i = 1; i <= n; i ++) {
		prefix[i] = prefix[i - 1] + (s[i] == '.');
	}
	
	ll l = 1, ans = 0;
	
	for(ll r = 1; r <= n; r ++) {
		while(l <= r && prefix[r] - prefix[l - 1] > k) {
			l ++;
		}
		
		ans = max(ans, r - l + 1);
	}
	
	cout << ans;
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

