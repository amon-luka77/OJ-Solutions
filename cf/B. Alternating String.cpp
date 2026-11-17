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
ll t1;
void read() {
    cin >> t1;
}
void solve() {
    while(t1 --) {
        string s; cin >> s;
        s = ' ' + s;

        ll sl = 0, sl1 = 0;
        for(ll i = 1; i < s.size(); i ++) {
            ll k = i % 2;
            if(s[i] - 'a' != k && s[i - 1] - 'a' != k) sl ++;
        }

        for(ll i = 1; i < s.size(); i ++) {
            ll k = (i + 1) % 2;
            if(s[i] - 'a' != k && s[i - 1] - 'a' != k) sl1 ++;
        }

        sl = min(sl, sl1);

        if(sl >= 2) cout << "NO";
        else cout << "YES";
        cout << el;
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