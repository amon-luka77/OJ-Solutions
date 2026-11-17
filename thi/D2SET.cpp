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
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 0;
ll n, k, ans = 0, cnt = 0;
vector<ll> a;
map<ll, ll> vs;

void read() {
    cin >> n >> k;
}

void backtrack(ll pos, ll sl) {
    if(pos >= n + 1) {
        if(ans == sl) {
            cnt = (cnt + 1) % k;
        }

        if(ans < sl) {
            ans = sl;
            cnt = 1;
        }

        return;
    }

    backtrack(pos + 1, sl);

    if(a[pos] % 2 == 0) {
        if(vs[a[pos] / 2] != 1) {
            vs[a[pos]] = 1;
            backtrack(pos + 1, sl + 1);
            vs[a[pos]] = 0;            
        }
    }

    if(a[pos] % 2) {
        vs[a[pos]] = 1;
        backtrack(pos + 1, sl + 1);
        vs[a[pos]] = 0;
    }
}

void solve() {
    if(n <= 1e6) {
        a.pb(0);
        ans = 0, cnt = 0;
        FOR(i, 1, n) {
            ll x; cin >> x;
            a.pb(x);
        }

        sort(a.begin() + 1, a.end());
        backtrack(1, 0);

        cout << ans << ' ' << cnt;
    }
}

void write() {

}

int main() {
    boost;
    // file("D2SET");
    read();
    solve();
    write();
    return 0;
}