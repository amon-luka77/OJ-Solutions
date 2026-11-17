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

const ll N = 2005;
ll t;

ll mergeCount(vector<ll>& arr, ll l, ll r) {
    if (r - l <= 1) return 0;
    ll m = (l + r) / 2;
    ll cnt = mergeCount(arr, l, m) + mergeCount(arr, m, r);
    vector<ll> tmp;
    ll i = l, j = m;
    while (i < m && j < r) {
        if (arr[i] <= arr[j]) tmp.pb(arr[i++]);
        else { 
            cnt += m - i; 
            tmp.pb(arr[j++]); 
            
        }
    }
    while(i < m) tmp.pb(arr[i++]);
    while(j < r) tmp.pb(arr[j++]);
    FOR(k, l, r - 1) arr[k] = tmp[k - l];
    return cnt;
}

void read() {
    cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n + 1), b(n + 1);
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> b[i];

        set<pair<ll, ll>> avail;
        FOR(j, 1, n) avail.insert({b[j], j});

        vector<ll> p(n + 1);
        bool ok = true;
        FOR(i, 1, n) {
            auto it = avail.lower_bound({a[i], -1});
            if (it == avail.end()) { 
                ok = false; 
                break; 
            }
            p[i] = it->sc;
            avail.erase(it);
        }

        if (!ok) { 
            cout << -1 << el; 
            continue; 
        }

        vector<ll> k(p.begin() + 1, p.end());
        cout << mergeCount(k, 0, n) << el;
    }
}

void solve() {

}

void write() {

}

int main() {
    boost;
    //file("");
    read();
    solve();
    write();
    return 0;
}