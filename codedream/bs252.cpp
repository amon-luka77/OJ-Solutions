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
const ll N = 0;
string s, a, b, k[3];
ll f[3][101][101];
void read() {
    cin >> s >> a >> b;
    k[0] = a;
    k[1] = b;
    memset(f, -1, sizeof(f));
}

ll dp(ll type, ll ps, ll pos) {
    if(ps > s.size()) return 1;
    if(pos > k[type].size()) return 0;
    if(f[type][ps][pos] != -1) return f[type][ps][pos];

    ll cnt = dp(type, ps, pos + 1);
    if(k[type][pos] == s[ps]) cnt += dp((type + 1) % 2, ps + 1, pos + 1);
    
    return f[type][ps][pos] = cnt;
}

void solve() {
    cout << dp(0, 0, 0) + dp(1, 0, 0);
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