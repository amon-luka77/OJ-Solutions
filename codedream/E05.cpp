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

const ll N = 1e5;
ll n, q, sum = 0, a[N + 1], gh = 0;
ll prefix[N + 1], b[N + 1];
bool sub2 = 1, sub3 = 1;

vector<ll> query; 

void read() {
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i];
        sum += a[i];
        b[a[i]] ++;
    }

    FOR(i, 1, N) prefix[i] = prefix[i - 1] + b[i];

    sort(a + 1, a + n + 1);
}

ll binary(ll tg) {
    ll l = 1, r = n, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(a[mid] <= tg) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

bool check(ll k) {
    ll x = (a[n] + k - 1) / k;
    ll cnt = 0;
    
    for(ll l = 1; l <= n; l ++) {
        ll t = a[l] / x;
        ll r = binary((t + 1) * x - 1);
        ll y = a[l] / x;
        cnt += (prefix[a[r]] - prefix[a[l] - 1]) * y;
        l = r;
    }

    return (cnt >= k);
}

void solve() {
    while(q --) {
            ll x; cin >> x;
            if(x <= sum && (x == 1 || check(x))) cout << "YES \n";
            else cout << "NO \n";
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