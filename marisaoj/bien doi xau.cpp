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

const ll N = 300;
string s, t;
ll n;

void read() {
	cin >> s >> t;
	n = s.size();
	s = ' ' + s;
	t = ' ' + t;
		
}

void solve() {
	ll sl1 = 0, sl0 = 0;
	ll ans = 0;
	
	FOR(i, 1, n) {
		if(s[i] == '?') {
			ans ++;
			continue;
		}
		
		if(s[i] != t[i]) {
			if(s[i] == '1') sl1 ++;
			else sl0 ++;
		}
	}
	ans += max(sl0, sl1);
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

