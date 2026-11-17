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
using namespace std;

const ll N = 5e3;

ll n2, x, y, z;
ll dp[N + 1][N + 1];
vector<ll> a, b;

void read() {
	a.pb(0), b.pb(0);
	cin >> n2 >> x >> y >> z;
	
	FOR(i, 1, n2) {
		ll ai, bi;
		cin >> ai >> bi;
		
		FOR(j, 1, ai) {
			a.pb(i);
		}
		
		FOR(j, 1, bi) {
			b.pb(i);
		}
	}
}

void solve() {
	ll n = a.size() - 1, m = b.size() - 1;
	FOR(i, 1, n) dp[i][0] = i * y;
	FOR(i, 1, m) dp[0][i] = i * x;
	
	FOR(i, 1, n) FOR(j, 1, m) {
		if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
		else {
			dp[i][j] = min({dp[i - 1][j - 1] + abs(a[i] - b[j]) * z, 
						dp[i - 1][j] + y, dp[i][j - 1] + x});
		}
	}
	
	cout << dp[n][m];
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

