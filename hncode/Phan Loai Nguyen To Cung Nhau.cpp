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

const ll N = 1e6;

ll n, d = 0, snt[N + 1], a[N + 1], b[N + 1];
bool sub1 = 1;


void sang() {
	for(ll i = 2; i * i <= N; i ++) {
		if(!snt[i]) {
			for(ll j = i * i; j <= N; j += i) {
				snt[j] = i;
			}
		}
	}
	
	for(ll i = 1; i <= N; i ++) {
		if(!snt[i]) snt[i] = i;
	}
}

void fac(ll n) {
	while(n > 1) {
		if(sub1 && b[snt[n]] > 0) sub1 = 0;
		
		b[snt[n]] ++;
		
		ll k = snt[n];
		
		while(n % k == 0) {
			n /= k;
		}
	}	
}

void read() {
	sang();
	cin >> n;
	
	for(ll i = 1; i <= n; i ++) {
		cin >> a[i];
		fac(a[i]);
		
		if(i == 1) {
			d = a[i];
		} else {
			d = __gcd(d, a[i]);
		}
	}
}
void solve() {
	if(sub1) {
		cout << "pairwise coprime";
	} else if(d == 1) {
		cout << "setwise coprime";
	} else {
		cout << "not coprime";
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

