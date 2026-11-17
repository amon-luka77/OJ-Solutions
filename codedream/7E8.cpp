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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e5;
ll n, ans = N; string s;
ll dp[N + 1], maxVal[4];
char pos[N + 1];
vector<char> a;

void read() {
    cin >> s; n = s.size(); s = ' ' + s;
}

void getAns() {
    memset(dp, 0, sizeof dp); memset(maxVal, 0, sizeof maxVal);
    FOR(i, 0, 3) pos[a[i]] = i;
    ll res = 0;

    FOR(i, 1, n) {
        FOR(j, 0, 3) if(j <= pos[s[i]]) dp[i] = max(dp[i], maxVal[j] + 1);
        maxVal[pos[s[i]]] = max(maxVal[pos[s[i]]], dp[i]);
        res = max(res, dp[i]);
    }

    ans = min(ans, n - res);
}

void solve() {
    string t = "hdcs";
    FOR(i, 0, 3) {
        a.pb(t[i]);
        FOR(j, 0, 3) if(i != j) {
            a.pb(t[j]);
            FOR(k, 0, 3) if(k != i && k != j) {
                a.pb(t[k]);
                ll l = 6 - i - j - k;
                a.pb(t[l]); getAns();
                a.pop_back();
                a.pop_back();
            }
            a.pop_back();
        }
        a.pop_back();
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