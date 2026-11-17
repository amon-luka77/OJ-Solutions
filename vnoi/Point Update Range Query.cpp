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
const ll N = 5e4;
ll n, m, a[N + 1];
ll block, startBlock[N + 1], endBlock[N + 1], blockId;
unordered_map<ll, ll> blockTs[N + 1];

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    block = sqrt(n);

    ll pos = 0, numBlock = 0;
    while(pos < n) {
        numBlock ++;
        startBlock[numBlock] = pos + 1;
        endBlock[numBlock] = min(n, pos + numBlock);

        pos += numBlock;
        for(ll i = startBlock[numBlock]; i <= endBlock[numBLock]; i ++) {
            blockTs[numBlock][a[i]] ++;
            blockId[i] = numBlock;
        }
    }
}

ll get(ll l, ll r, ll x) {
    ll res = 0;

    if(blockId[l] == blockId[r]) {
        for(ll i = l; i <= r; i ++) {
            res += (a[i] == x);
        }
    } else {
        for(ll i = blockId[l] + 1; i <= endBlock[r] - 1; i ++) {
            res += blockTs[i][x];
        }

        for(ll i = l; i <= endBlock[blockId[l]]; i ++) {
            res += (a[i] == x);
        }

        for(ll i = endBlock[blockId[r]]; i <= r; i ++) {
            res += (a[i] == x);
        }
    }

    return res;
}

void solve() {
    for(ll i = 1; i <= m; i ++) {
        ll x, l, r; cin >> l >> r >> x;
        cout << get(l, r, x) << el;
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