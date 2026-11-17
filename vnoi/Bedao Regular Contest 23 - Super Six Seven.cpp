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
const ll N = 2e5;
ll n, k, a[5][N + 5];

void read() {
    cin >> n >> k;

    FOR(i, 1, n) cin >> a[0][i];
    FOR(i, 1, n) cin >> a[1][i];
    FOR(i, 1, n) cin >> a[2][i];
    FOR(i, 1, n) cin >> a[3][i];

    sort(a[0] + 1, a[0] + n + 1, greater<ll>());
    sort(a[1] + 1, a[1] + n + 1, greater<ll>());
    sort(a[2] + 1, a[2] + n + 1, greater<ll>());
    sort(a[3] + 1, a[3] + n + 1, greater<ll>());

    // FOR(i, 0, 3) {
    //     FOR(j, 2, n) {
    //         diff[i][j] = a[i][j + 1] - a[i][j];
    //     }
    // }

    // FOR(i, 0, 3) {
    //     FOR(j, 1, n) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << el;
    // }
}   

struct NODE {
    ll x, y, z, t, l;
};

struct cmp {
    bool operator() (const NODE &x, const NODE &y) {
        return x.x < y.x;
    }
};

map<tuple<ll, ll, ll, ll>, ll> check;

void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;

    pq.push({a[0][1] + a[1][1] + a[2][1] + a[3][1], 1, 1, 1, 1});
    check[{1, 1, 1, 1}] = 1;

    while(!pq.empty() && k > 0) {
        auto [x, y, z, t, l] = pq.top();
        pq.pop();
        k --;

        if(k == 0) {
            cout << a[0][y] << ' ' << a[1][z] << ' ' << a[2][t] << ' ' << a[3][l];
            exit(0);
        }

        if(y < n) {
            if(check.find({y + 1, z, t, l}) == check.end()) {
                pq.push({x - a[0][y] + a[0][y + 1], y + 1, z, t, l});
                check[{y + 1, z, t, l}] = 1;
            }
        }
        if(z < n) {
            if(check.find({y, z + 1, t, l}) == check.end()) {
                pq.push({x - a[1][z] + a[1][z + 1], y, z + 1, t, l});
                check[{y, z + 1, t, l}] = 1;
            }
        }
        if(t < n) {
            if(check.find({y, z, t + 1, l}) == check.end()) {
                pq.push({x - a[2][t] + a[2][t + 1], y, z, t + 1, l});
                check[{y, z, t + 1, l}] = 1;
            }
        }

        if(l < n) {
            if(check.find({y, z, t, l + 1}) == check.end()) {
                pq.push({x - a[3][l] + a[3][l + 1], y, z, t, l + 1});
                check[{y, z, t, l + 1}] = 1;
            }
        }
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
