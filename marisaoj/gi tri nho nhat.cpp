/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
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

const ll N = 1e5;
ll n, k, a[N + 1], ans[N + 1];

void read() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
} 

void solve() {
    deque<ll> dq;
    FOR(i, 1, n) {
        while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
        while(!dq.empty() && i - dq.front() + 1 > k) dq.pop_front();
        
        if(!dq.empty()) ans[i] = a[dq.front()];

    }

    FOR(i, k, n) cout << ans[i] << ' ';
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