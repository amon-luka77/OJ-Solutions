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
ll n, W[N + 1], C[N + 1], dp[N + 1];

pair<ll, ll> a[N + 1];

void read() {
	cin >> n;
	
	FOR(i, 1, n) {
		cin >> W[i];
	}
	
	FOR(i, 1, n) {
		cin >> C[i];
	}
	
	FOR(i, 1, n) {
		a[i] = {W[i], C[i]};
	}
	
	sort(a + 1, a + n + 1, [](const pair<ll, ll> &x, const pair<ll, ll> &y){
		return x.ft + x.sc < y.ft + y.sc;
	});
	
}

void solve() {
	FOR(i, 1, n) dp[i] = 1e18;
	dp[0] = 0;
	
	FOR(i, 1, n) {
		FORD(j, n, 1) {
			if(a[i].sc >= dp[j - 1]) dp[j] = min(dp[j], dp[j - 1] + a[i].ft);
		}
	}
	
	FORD(i, n, 1) {
		if(dp[i] != 1e18) {
			cout << i;
			exit(0);
		}
	}
	
	cout << 0;
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
4
6 2
4 4
7 1
8 4


8 4
7 6
5 4
1 2

2
*/

