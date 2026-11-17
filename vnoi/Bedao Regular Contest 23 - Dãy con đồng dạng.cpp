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
const ll N = 1e5;
ll n, a[N + 1], b[N + 1], prefix[N + 1];

void read() {
    cin >> n;

    FOR(i, 1, n) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
}

void solve() {
    ll medium = b[(n + 1) / 2];

    FOR(i, 1, n) {
        ll t;
        if(a[i] <= medium) t = 1;
        else if(a[i] > medium) t = -1;
        else t = 0;
        prefix[i] = prefix[i - 1] + t;
    }

    ll cnt = 0;
    unordered_map<ll, ll> ts;
    ts[0] ++;

    ll r = 1;

    FOR(i, 1, n) {
        ll pre = cnt;
        if(a[i] == medium) {
            FOR(j, r, i - 1) {
                ts[prefix[j]] ++;
            }

            cnt += ts[prefix[i]];
            cnt += ts[prefix[i] - 1];

            r = i;
        } else {
            cnt += ts[prefix[i]];
            cnt += ts[prefix[i] - 1];
        }

        ll l = i, sl = 0;
        while(l > 0 && prefix[l] == prefix[l - 1] + 1) {
            sl += (a[l] == medium);
            l --;
        } 
        if(l == 0) l = 1;
        if(2 * sl > i - l + 1 && i != l) cnt ++;

        l = i;
        while(l > 0 && prefix[l] - 1 == prefix[l - 1]) {
            l --;
        } 
        if(l == 0) l = 1;
        if(2 * sl > i - l + 1 && i != l) cnt ++;

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