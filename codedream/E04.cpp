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

const ll N = 2e5;
ll n, k, ans = 0, a[N + 1], prefix[N + 1];
unordered_map<ll, ll> ts;
vector<ll> LEFT, RIGHT;
char b[N + 1];

bool sub2 = 1;

void read() {
    cin >> n >> k;
    LEFT.pb(0);
    RIGHT.pb(0);

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) {
        cin >> b[i];
        if(b[i] == 'R') LEFT.pb(a[i]);
        else RIGHT.pb(a[i]);
        if(i >= 2 && b[i] != b[i - 1]) sub2 = 0;
    }

    // FOR(i, 1, n) {
    //     ans += ts[a[i]];
    //     ts[a[i]] ++;
    // }
}

ll binaryLEFT(ll tg) {
    ll l = 1, r = RIGHT.size() - 1, ans = -1;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(tg <= RIGHT[mid]) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

ll binaryRIGHT(ll tg) {
    ll l = 1, r = RIGHT.size() - 1, ans = -1;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(tg >= RIGHT[mid]) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    // if(sub2) cout << ans;
    // else if(n <= 3000) {
    //     FOR(i, 1, n) FOR(j, i + 1, n) {
    //         if(b[i] == 'R' && b[j] == 'L' && a[i] < a[j]) {
    //             if((a[j] + a[i]) % 2 == 0) {
    //                 ll mid = (a[j] + a[i]) / 2;
    //                 if(abs(mid - a[i]) <= k && abs(mid - a[j]) <= k) ans ++;
    //             }
    //         } 

    //         if(b[i] == 'L' && b[j] == 'R' && a[j] < a[i]) {
    //             if((a[i] + a[j]) % 2 == 0) {
    //                 ll mid = (a[j] + a[i]) / 2;
    //                 if(abs(mid - a[i]) <= k && abs(mid - a[j]) <= k) ans ++;
    //             }
    //         }
    //     }

    //     cout << ans;
    // else {
        sort(LEFT.begin() + 1, LEFT.end());
        sort(RIGHT.begin() + 1, RIGHT.end());

        ll x = 1;
        FOR(i, 2, LEFT.size() - 1) {
            if(LEFT[i] == LEFT[i - 1]) x ++;
            else {
                ans += (x - 1) * x / 2;
                x = 1;
            }
        }

        if(x > 1) ans += (x - 1) * x / 2;
        x = 1;

        FOR(i, 2, RIGHT.size() - 1) {
            if(RIGHT[i] == RIGHT[i - 1]) x ++;
            else {
                ans += (x - 1) * x / 2;
                x = 1;
            }
        }

        if(x > 1) ans += (x - 1) * x / 2;
        x = 1;

        FOR(i, 1, RIGHT.size() - 1) {
            prefix[i] = prefix[i - 1] + (RIGHT[i] % 2);
        }

        FOR(i, 1, LEFT.size() - 1) {
            ll leftPos = binaryLEFT(LEFT[i]);
            ll rightPos = binaryRIGHT(LEFT[i] + 2 * k);

            if(leftPos != -1 && rightPos != -1) {
                ll sumCnt = prefix[rightPos] - prefix[leftPos - 1];
                if(LEFT[i] % 2) ans += sumCnt;
                else ans += (rightPos - leftPos + 1 - sumCnt);
            }
        }

        cout << ans;
    // }
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