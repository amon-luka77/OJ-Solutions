/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
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
#define NAME "8E012"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".ans", "w", stdout);
    }
}

const ll N = 5e5;
ll n, q, a[N + 1], cnt[N + 1];
vector<ll> b = {2, 3};

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
}

void solve() {
    while(q --) {
        char opt; ll x, y; cin >> opt >> x >> y;
        if(opt == '+' || opt == '-') {
            ll z = (opt == '+' ? 1 : -1);
            ll i = x, j = 0;
            while(i <= y) {
                cnt[i] += z; if(cnt[i] < 0) cnt[i] = 0;
                i += b[j]; j = (j + 1) % 2;
            }
        } else {
            ll res = 0;
            FOR(i, x, y) if(cnt[i] > 0) res += a[i];
            cout << res << el; cerr << res << el;
        }

//        FOR(i, 1, n) cout << cnt[i] << ' ';
//        cout << el;
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
