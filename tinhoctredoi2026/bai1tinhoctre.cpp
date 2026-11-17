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
ll n, k, s, cnt = 0;

void read() {
    cin >> n >> k >> s;
}

void backtrack(ll sum, ll pos, vector<ll> &a) {
    if(cnt == k) return;
    if(sum == s) {
        for(auto &i : a) {
            cout << i << ' ';
        }
        cout << 0 << el;
        cnt ++;
        return;
    }

    if(sum > s) return;

    for(ll i = pos; i >= 1; i --) {
        a.pb(i);
        backtrack(sum + i, i - 1, a);
        a.pop_back();
    }

    return;
}

void solve() {
    vector<ll> a;
    backtrack(0, n, a);
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