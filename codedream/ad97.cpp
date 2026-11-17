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

    const ll N = 16;
    ll n, a[N + 1][N + 1], dp[MASK(N) + 1], cost[MASK(N) + 1];

    void read() {
        cin >> n;
        FOR(i, 0, n - 1) FOR(j, 0, n - 1) cin >> a[i][j];
    }

    void solve() {
        memset(dp, -0x3f, sizeof dp);
        dp[0] = 0;
        
        FOR(mask, 0, MASK(n) - 1) {
            ll i = __lg(mask & -mask);
            cost[mask] = cost[mask ^ MASK(i)];
            
            for(ll tmp = mask; tmp > 0; tmp ^= tmp & -tmp) {
                ll pos = __lg(tmp & -tmp);
                cost[mask] += a[pos][i];
            }
        }

        FOR(mask, 0, MASK(n) - 1) {
            ll limit = (MASK(n) - 1) ^ mask;
            FORD(sub, limit, 0) {
                sub &= limit;
                dp[mask | sub] = max(dp[mask | sub], dp[mask] + cost[sub]);
            }
        }

        cout << dp[MASK(n) - 1];
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