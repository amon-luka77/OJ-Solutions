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
const ll N = 6000;
ll n;
vector<pair<ll, ll>> a;
map<pair<ll, ll>, ll> check;
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        ll x, y; cin >> x >> y;
        if(check[{x, y}] == 0) a.pb({x, y});
        check[{x, y}] ++;
    }
    sort(a.begin(), a.end());
}
void solve() {
    ll cnt = 0;
    for(ll i = 0; i < a.size(); i ++) {
        for(ll j = i + 1; j < a.size(); j ++) {
            if(a[i].ft < a[j].ft && a[i].sc < a[j].sc && check[{a[i].ft, a[j].sc}] > 0 && check[{a[j].ft, a[i].sc}] > 0) cnt ++;
        }
    }
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