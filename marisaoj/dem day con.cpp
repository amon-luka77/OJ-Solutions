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

    const ll N = 1000, mod = 1e9 + 7;
    ll n, k;

    vector<ll> Prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    ll ts[51], a[N + 1];

    void read() {
        cin >> n >> k;
        FOR(i, 0, n - 1) {
            cin >> a[i];

            ts[a[i]] ++;
        }
    }

    ll power(ll x, ll y) {
        ll res = 1;;
        x %= mod;
        while(y > 0) {
            if(y % 2) res = (res * x) % mod;
            x = (x * x) % mod;
            y /= 2;
        }
        return res;
    }

    void solve() {
        ll ans = 0;

        FOR(mask, 1, MASK(15) - 1) {
            ll d = 1, cnt = 1;

            for(ll temp = mask; temp > 0; temp ^= temp & -temp) {
                ll i = __lg(temp & -temp);
                d = lcm(d, Prime[i]);
                cnt = (cnt * (power(2, ts[Prime[i]]) - 1)) % mod;
            }

            if(d <= k) ans = (ans + cnt) % mod;
        }

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