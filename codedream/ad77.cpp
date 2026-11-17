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

const ll N = 2015;
ll dp[N + 1][N + 1];
vector<ll> a = {2, 0, 1, 5};

void read() {
    
}

ll getCount(ll numDigit, ll modDigit, ll mod) {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    FOR(i, 0, numDigit - 1) FOR(j, 0, modDigit - 1) if(dp[i][j]) {
        for(auto t : a) {
            ll newJ = (j * 10 % modDigit + t) % modDigit;

            dp[i + 1][newJ] += dp[i][j];
            dp[i + 1][newJ] %= mod;
        }
    }

    return dp[numDigit][0];
}

void solve() {
    ll n, m, k; cin >> n >> k >> m;
    cout << getCount(n, k, m) << el;
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