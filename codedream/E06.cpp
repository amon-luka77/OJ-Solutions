#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (int i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 3e5;
ll n, m, bit[N + 1];
set<ll> C;
map<ll, ll> dis;
bool mark[N + 1];

void updatedBit(ll i, ll val) {
    for(; i <= n; i += i & -i) bit[i] += val;
}

ll getSum(ll l, ll r) {
    ll sum = 0; l --;
    for(; l >= 1; l -= l & -l) sum -= bit[l];
    for(; r >= 1; r -= r & -r) sum += bit[r];
    return sum; 
}

vector<vector<ll>> a;
vector<ll> ans;

void read() {
    cin >> n >> m;
    a.assign(m + 1, vector<ll>());
    bool check = 0;

    FOR(i, 1, m) {
        ll t; cin >> t;
        vector<ll> b;
        ll pre = 0;
        FOR(j, 1, t) {
            ll x; cin >> x;
            if(pre != 0) {
                next[pre] = x;
            }
            pre = x;
        }
        mark[b[0]] = 1;
        ans.pb(b[0]);
        C.insert(b[0]);
        updated(b[0], 1);
    }

    if(check) {cout << "NO"; exit(0);};
}

void solve() {
    for(auto i : C) {
        dis[next[i]] = getSum(i, next[i]);
        if(dis[next[i]] == 0) nextPos = i;
    }

    while(nextPos > 0) {
        
    }

    FOR(i, 0, n - 1) if(!mark[i]) {
        auto it = C.upper_bound(i);
        if(it != C.begin()) {
            cout << "NO";
            exit(0);
        } else ans.pb(i);
    }

    cout << "YES" << el;
    for(auto i : ans) cout << i << ' ';
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