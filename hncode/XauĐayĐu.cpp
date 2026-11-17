#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 30;
ll n, cnt = 0;
vector<string> a;

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        string s; cin >> s;
        a.pb(s);
    }
}

bool check(const vector<string> &k) {
    vector<ll> m(N, 0);
    ll sl = 0;

    for(auto i : k) {
        for(ll j = 0; j < i.size(); j ++) {
            ll x = i[j] - 'a';
            m[x] ++;
            if(m[x] == 1) sl ++;
        }
    }

    return (sl >= 26);
}

void backtrack(ll pos, vector<string> &t) {
    if(pos >= n) {
        if(check(t)) cnt ++;
        return;
    }

    backtrack(pos + 1, t);
    t.pb(a[pos]);
    backtrack(pos + 1, t);
    t.pop_back();
}

void solve() {
    vector<string> k;
    backtrack(0, k);

    cout << cnt;
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