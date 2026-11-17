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
const ll N = 1e3;
ll n, m, k;
void read() {
    cin >> n >> m >> k;
}
struct Seg {
    unordered_map<ll, ll> node;

    void updated(ll id, ll l, ll r, ll i) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] = 1;
            return;
        }

        ll mid = l + (r - l) / 2;
        updated(id * 2, l, mid, i);
        updated(id * 2 + 1, mid + 1, r, i);

        node[id] = node[id * 2] + node[id * 2 + 1];
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(r < i || l > j) return -1;
        if(node[id] == r - l + 1) return -1;
        if(l == r) return l;
        ll mid = l + (r - l) / 2;
        
        if(node[id * 2] != mid - l + 1) return get(id * 2, l, mid, i, j);
        else return get(id * 2 + 1, mid + 1, r, i, j);
    }
};
unordered_map<ll, Seg> cot, hang;

void solve() {
    ll cnt = 0;
    for(ll i = 1; i <= k; i ++) {
        ll x, y; char z;
        cin >> x >> y >> z;
        if(z == 'N') {
            while(true) {
                x = cot[y].get(1, 0, n, x + 1, n);
                if(x == -1) break;
                cnt ++;
                cot[y].updated(1, 0, n, x);
                hang[x].updated(1, 0, m, y);
            }
        } else if(z == 'S') {
            while(true) {
                x = cot[y].get(1, 0, n, 0, x - 1);
                if(x == -1) break;
                cnt ++;
                cot[y].updated(1, 0, n, x);
                hang[x].updated(1, 0, m, y);
            }
        } else if(z == 'E') {
            while(true) {
                y = hang[x].get(1, 0, m, y + 1, m);
                if(y == -1) break;
                cnt ++;
                hang[x].updated(1, 0, m, y);
                cot[y].updated(1, 0, n, x);
            }
        } else {
            while(true) {
                y = hang[x].get(1, 0, m, 0, y - 1);
                if(y == -1) break;
                cnt ++;
                hang[x].updated(1, 0, m, y);
                cot[y].updated(1, 0, n, x);
            }
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