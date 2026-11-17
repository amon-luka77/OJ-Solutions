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
const ll N = 1e7;
ll n, prefix[N + 1];
bool check[N + 1];
void sang() {
    check[0] = 1, check[1] = 1;
    for(ll i = 2; i * i <= N; i ++) {
        if(check[i] == 1) continue;
        for(ll j = i * i; j <= N; j += i) {
            check[j] = 1;
        }
    }
    for(ll i = 1; i <= N; i ++) {
        prefix[i] = prefix[i - 1] + (!check[i]);
    }
}
void read() {
    cin >> n;
}
void solve() {
    while(n --) {
        ll l, r; cin >> l >> r;
        cout << ((prefix[r + l] - prefix[max(r - l - 1, 0LL)]) > 0) << el;
    }
}
void write() {

}
int main() {
    boost;
    //file();
    sang();
    read();
    solve();
    write();
    return 0;
}