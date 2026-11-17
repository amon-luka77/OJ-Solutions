#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define ft first
#define sc second

using namespace std;

const int N = 3e5;
int n, a;
pair<int, int> node[N + 1];

namespace Sub2 {
    bool check() {return n <= 10000;}

    void solve() {
        ll res = 0;
        FOR(i, 1, n) {
            ll sum = 0;
            ll maxVal = 0;
            FOR(j, i, n) {
                sum += (ll)a - node[j].sc;
                if(j > i) maxVal = max(maxVal, (ll)(node[j].ft - node[j - 1].ft) * (node[j].ft - node[j - 1].ft));
                res = max(res, sum - maxVal);
            }
        }

        cout << res;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a;
    FOR(i, 1, n) cin >> node[i].ft >> node[i].sc;

    if(Sub2::check()) return Sub2::solve(), 0;

}
