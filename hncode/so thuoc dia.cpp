
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 0;
ll n, k;

void read() {
    cin >> n >> k;    
    vector<ll> a;

    FOR(i, 1, 9) {
        if(k % i == 0) {
            a.pb(i);
        }
    }

    if(n <= 1e3) {
        ll cnt = 0;

        FOR(i, 1, n) {
            ll t = i % 10;
            for(auto j : a) {
                if(t == j) {
                    cnt ++;
                }
            }
        }

        cout << cnt;
    } else {
        ll cnt = 0;
        
        for(auto i : a) {
            ll l = i, r = (n / 10) * 10 + i;
            if(r > n) r -= 10;

            cnt += (r - l) / 10 + 1;
        }

        cout << cnt;
    }



}

// 114 112 

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