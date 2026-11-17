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

const ll N = 300;
ll n, m, a[N + 1][N + 1], prefix[N + 1][N + 1][8];

void read() {
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) {
        char x; cin >> x;
        a[i][j] = x - '0';
    }

    FOR(i, 1, n) FOR(j, 1, m) FOR(k, 1, 7) {
        prefix[i][j][k] = prefix[i - 1][j][k] + prefix[i][j - 1][k] - prefix[i - 1][j - 1][k] + (a[i][j] == k);
    }
}

ll getSum(ll i, ll j, ll x, ll y, ll t) {
    return prefix[x][y][t] - prefix[i - 1][y][t] - prefix[x][j - 1][t] + prefix[i - 1][j - 1][t];
}

bool check(vector<ll> &b) {
    FOR(i, 1, 7) if(b[i] == 0) return 0;
    return 1;
}

void add(vector<ll>&b, ll i, ll j, ll x, ll y, ll t) {
    FOR(k, 1, 7) {
        b[k] += t * getSum(i, j, x, y, k); 
    }
}

void solve() {
    ll ans = 0;

    FOR(i, 1, n) FOR(j, i, n) {
        vector<ll> cnt(8, 0);
        ll l = 1;

        FOR(r, 1, m) {
            add(cnt, i, r, j, r, 1);
            
            while(l <= r) {
                add(cnt, i, l, j, l, -1);

                if(!check(cnt)) {
                    add(cnt, i, l, j, l, 1);
                    break;
                }

                l ++;
            }

            if(check(cnt)) ans += l;
        }
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