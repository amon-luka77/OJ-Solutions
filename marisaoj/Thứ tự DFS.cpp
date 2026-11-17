#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (int i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 2e5;
ll n, ans = 0, w[N + 1];
bool vs[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> w[i];
    }

    for(ll i = 2; i <= n; i ++) {
        ll x; cin >> x;
        edge[x].pb(i);
        edge[i].pb(x);
    }
}

void backtrackSub1(ll u, vector<ll> &a) {

    if(a.size() == n) {
        ll sum = 0;
        for(ll i = 0; i < a.size(); i ++) {
            sum += (i + 1) * a[i];
        }

        ans = max(ans, sum);
        return;
    }

    for(auto i : edge[u]) {
        if(!vs[i]) {
            vs[i] = 1;
            a.pb(w[i]);
            backtrackSub1(i, a);
            a.pop_back();
            vs[i] = 0;
        }
    }
}

void solve() {
    if(n <= 10) {
        vector<ll> a;
        a.pb(w[1]);
        backtrackSub1(1, a);

        cout << ans;
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