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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 1e5;
ll n, a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

void solve() {
    map<ll, ll> ts;
    ll cnt = 0;

    FOR(i, 1, n) {
        ll cur = a[i];
        
        FOR(j, 0, 31) {
            ll t = (BIT(cur, 31) & 1);
            cur = ((cur & (MASK(31) - 1)) << 1) + t;
            cnt += ts[cur]; 
        }

        ts[a[i]] ++;

    }

    cout << cnt;
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