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
const ll N = 1e5;
ll n, a[N + 1], b[N + 1], prefixA[N + 1], prefixB[N + 1];
pair<ll, ll> T1[N + 1];

void read() {
    cin >> n;
    bool sub1 = (n <= 100);
    for(ll i = 1; i <= n; i ++) {
        cin >> T1[i].ft >> T1[i].sc;
        if(sub1 && (T1[i].ft > 100 || T1[i].sc > 100)) sub1 = 0;
        a[i] = T1[i].ft;
        b[i] = T1[i].sc;
    }

    if(sub1) {
        ll ans = 1e18;
        for(ll i = 1; i <= 100; i ++) {
            for(ll j = 1; j <= 100; j ++) {
                ll kc = 0;
                for(ll k = 1; k <= n; k ++) {
                    kc += abs(i - T1[k].ft) + abs(j - T1[k].sc);
                }
                ans = min(ans, kc);
            }
        }
        cout << ans;
        exit(0);
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
}

ll tinh(ll tg, ll cg) {
    if(cg == 0) {
        ll l = 1, r = n, ans = 0;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(a[mid] <= tg) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ll sumL = tg * ans - prefixA[ans];
        ll sumR = prefixA[n] - prefixA[ans] - (n - ans) * tg;
        return sumL + sumR;
    } else {
        ll l = 1, r = n, ans = 0;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(b[mid] <= tg) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ll sumL = tg * ans - prefixB[ans];
        ll sumR = prefixB[n] - prefixB[ans] - (n - ans) * tg;
        return sumL + sumR;
    }
}

void solve() {
    for(ll i = 1; i <= n; i ++) {
        prefixA[i] = prefixA[i - 1] + a[i];
        prefixB[i] = prefixB[i - 1] + b[i];
    }

    ll l = 1, r = 1e9, ansX = 0;
    while(l <= r) {
        ll mid = (l + r) / 2;
        ll x = tinh(mid, 0), y = tinh(mid - 1, 0);
        if(x < y) {
            ansX = x;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    l = 1, r = 1e9; ll ansY = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        ll x = tinh(mid, 1), y = tinh(mid - 1, 1);
        if(x < y) {
            ansY = x;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ansX + ansY;
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