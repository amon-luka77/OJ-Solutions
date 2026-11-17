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
string s;
void read() {
    cin >> s;
    string t = "";
    for(ll i = 0; i < s.size(); i ++) {
        t += s[i];
        string v ="";
        if(s.size() % t.size() != 0) continue;
        for(ll i = 1; i <= s.size() / t.size(); i ++) {
            v += t;
        }
        if(v == s) {
            cout << s.size() / t.size() << t << el;
            exit(0);
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