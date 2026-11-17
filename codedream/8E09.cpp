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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
ll n, a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n - 1) cin >> a[i];
}

namespace Sub1 {
    bool check() {return 1500;}

    const ll maxN = 1500;

    struct Segtree {
        ll node[4 * maxN + 1];

        void updated(ll id, ll l, ll r, ll i, ll val) {
            if(l == r) return node[id] = min(node[id], val), void();
            ll mid = (l + r) >> 1;
            if(i <= mid) updated(id << 1, l, mid, i, val);
            else updated(id << 1 | 1, mid + 1, r, i, val);
            node[id] = min(node[id << 1], node[id << 1 | 1]);
        }

        ll getMin(ll id, ll l, ll r, ll i, ll j) {
            if(l > r || i > j) return 1e18;
            if(make_pair(l, r) == make_pair(i, j)) return node[id];
            ll mid = (l + r) >> 1;
            if(j <= mid) return getMin(id << 1, l, mid, i, j);
            else if(i > mid) return getMin(id << 1 | 1, mid + 1, r, i, j);
            else return min(getMin(id << 1, l, mid, i, mid), getMin(id << 1 | 1, mid + 1, r, mid + 1, j));
        }
    } st1, st2;

    ll dp[maxN + 1][3];

    void solve() {
        memset(dp, 0x3f, sizeof dp); ll ans = n - 1; dp[0][1] = 0;
        FOR(i, 1, n - 1) dp[i][1] = i;

        FOR(j, 2, n - 1) {
            memset(st1.node, 0x3f, sizeof st1.node);
            memset(st2.node, 0x3f, sizeof st2.node);
            FOR(i, 0, n - 1) st1.updated(1, 0, n, i, dp[i][(j + 1) % 2]);
            FOR(i, 0, n - 1) dp[i][j % 2] = 1e18;

            FOR(i, 1, n - 1) {
                ll lastPos = max(0LL, i - j);
                ll lastPos2 = max(0LL, i - j + 1);
                dp[i][j % 2] = 1 + min(st1.getMin(1, 0, n, lastPos2, i - 1) + a[i], st2.getMin(1, 0, n, lastPos, i - 1));
                st2.updated(1, 0, n, i, dp[i][j % 2]);
                if(i + j >= n) ans = min(ans, dp[i][j % 2]);
            }
        } cout << ans;
    }
}

namespace Sub2 {
    bool check() {return 1;}

    ll dp[N + 1][3];

    void solve() {
        memset(dp, 0x3f, sizeof dp); dp[0][1] = 0;
        FOR(i, 1, n - 1) dp[i][1] = i;
        ll ans = n - 1; ll k = sqrt(n);

        FOR(j, 2, k) {
            deque<ll> st1, st2;
            FOR(i, 0, n - 1) dp[i][j % 2] = 1e18;

            FOR(i, 1, n - 1) {
                ll lastPos1 = max(0LL, i - j);
                ll lastPos2 = max(0LL, i - j + 1);

                while(!st1.empty() && dp[st1.back()][j % 2] >= dp[i - 1][j % 2]) st1.pop_back();
                st1.push_back(i - 1);
                while(st1.front() < lastPos1) st1.pop_front();


                while(!st2.empty() && dp[st2.back()][(j + 1) % 2] >= dp[i - 1][(j + 1) % 2]) st2.pop_back();
                st2.push_back(i - 1);
                while(st2.front() < lastPos2) st2.pop_front();

                dp[i][j % 2] = 1 + min(dp[st1.front()][j % 2], dp[st2.front()][(j + 1) % 2] + a[i]);
                if(i + j >= n) ans = min(ans, dp[i][j % 2]);
            }
        } cout << ans;
    }
}

void solve() {
//    if(Sub1::check()) return Sub1::solve(), void();
    if(Sub2::check()) return Sub2::solve(), void();
}

void write() {

}

int main() {
    boost;
//    file();
    read();
    solve();
    write();
    return 0;
}
