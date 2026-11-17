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
const ll N = 1e5;
ll n, q; string s;
void read() {
    cin >> n >> q >> s;
}

void solve() {

    while(q--) {
        ll x, l, r; cin >> l >> r >> x;
        if(x == 0) {
            sort(s.begin() + l - 1, s.begin() + r, greater<char>());
        } else {
            sort(s.begin() + l - 1, s.begin() + r);
        }
    }

    cout << s;
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