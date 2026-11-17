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

const ll N = 0;
ll t, n, h, w;
bool dp[50][105][101];

void read() {
    cin >> t;
    while(t --) {
        cin >> n >> h >> w;
        vector<ll> X(w + 1, 0), S(w + 1, 0), E(w + 1, 0);
        vector<pair<ll, ll>> a(n + 1, {0, 0});

        FOR(i, 0, w - 1) {
            cin >> X[i];
        }
        FOR(i, 0, w - 1) {
            cin >> S[i];
        }
        FOR(i, 0, w - 1) {
            cin >> E[i];
        }

        FOR(i, 0, w - 1) {
            a[X[i]] = {S[i], E[i]};
        }

        memset(dp, 0, sizeof(dp));
        dp[0][h / 2][50] = 1;
        bool ok = 0;
        // dp[i][j][v] o cot i, do cao j va van toc v;

        FOR(i, 0, n - 1) {
            FOR(j, 0, h - 1) {
                FOR(v, -50, 50) {
                    if(a[i + 1].ft == 0) {
                        if(dp[i][j][v + 50]) {
                            FOR(k, -1, 1) {
                                ll newV = v + k;
                                if(j + newV >= h || j + newV < 0) break;
                                dp[i + 1][j + newV][newV + 50] = 1;
                            }
                        }                        
                    } else {
                        if(a[i + 1].ft > j || a[i + 1].sc < j) continue;

                        if(dp[i][j][v + 50]) {
                            FOR(k, -1, 1) {
                                ll newV = v + k;
                                if(j + newV >= h || j + newV < 0) break;
                                dp[i + 1][j + newV][newV + 50] = 1;
                            }
                        } 
                    }

                }
            }
        }

        FOR(i, 0, h + 49) {
            FOR(j, 0, 100) {
                if(dp[n - 1][i][j]) {
                    ok = 1;
                    break;
                }
            }
        }

        if(ok) {
            cout << "YES" << el;
        } else {
            cout << "NO" << el;
        }
    }

}

void solve() {

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