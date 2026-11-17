#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 25e4, maxN = 5e4;
ll n, m, block, a[N + 1];
ll blockId[N + 1], startBlock[N + 1], endBlock[N + 1]; 
long long cnt = 0;

struct BIT {
    ll n;
    vector<ll> bit;

    void resize(ll m) {
        n = m;
        bit.assign(n + 1, 0);
    }

    void updated(ll i, ll val) {
        for(; i <= n; i += i & -i) bit[i] += val;
    }

    ll getSum(ll i) {
        ll res = 0;
        for(; i >= 1; i -= i & -i) res += bit[i];
        return res;
    }

    ll get(ll l, ll r) {
        return getSum(r) - getSum(l - 1);
    }
};

BIT bit[501];

void read() {
    cin >> n;
    block = sqrt(n);

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }    
    
    for(ll i = 1; i <= (n + block - 1) / block; i ++) {
        bit[i].resize(maxN);
    }

    ll pos = 0, numBlock = 0;
    while(pos < n) {
        numBlock ++;
        startBlock[numBlock] = pos + 1;
        endBlock[numBlock] = min(pos + block, n);

        pos += block;

        for(ll i = startBlock[numBlock]; i <= endBlock[numBlock]; i ++) {
            bit[numBlock].updated(a[i], 1);
            blockId[i] = numBlock;
        }
    }
}

ll get_max(ll l, ll r, ll k) {
    long long res = 0;
    if(l > r) return 0;

    if(blockId[l] == blockId[r]) {
        for(ll i = l; i <= r; i ++) {
            res += (a[i] > k);
        }
    } else {
        for(ll i = blockId[l] + 1; i <= blockId[r] - 1; i ++) {
            res += bit[i].get(k + 1, maxN);
        }

        for(ll i = l; i <= endBlock[blockId[l]]; i ++) {
            res += (a[i] > k);
        }

        for(ll i = startBlock[blockId[r]]; i <= r; i ++) {
            res += (a[i] > k);
        }
    }

    return res;
}

ll get_min(ll l, ll r, ll k) {
    long long res = 0;
    if(l > r) return 0;

    if(blockId[l] == blockId[r]) {
        for(ll i = l; i <= r; i ++) {
            res += (a[i] < k);
        }
    } else {
        for(ll i = blockId[l] + 1; i <= blockId[r] - 1; i ++) {
            res += bit[i].get(1, k - 1);
        }

        for(ll i = l; i <= endBlock[blockId[l]]; i ++) {
            res += (a[i] < k);
        }

        for(ll i = startBlock[blockId[r]]; i <= r; i ++) {
            res += (a[i] < k);
        }
    }

    return res;
}

void updated_query(ll i, ll val) {
    
    cnt -= get_max(1, i - 1, a[i]);
    cnt -= get_min(i + 1, n, a[i]);
    bit[blockId[i]].updated(a[i], -1);

    cnt += get_max(1, i - 1, val);
    cnt += get_min(i + 1, n, val);
    bit[blockId[i]].updated(val, 1);
    
    a[i] = val;
}

void solve() {
    cin >> m;
    BIT new_bit;
    new_bit.resize(maxN);

    for(ll i = 1; i <= n; i ++) {
        cnt += new_bit.get(a[i] + 1, maxN);
        new_bit.updated(a[i], 1);
    }

    for(ll j = 1; j <= m; j ++) {
        ll i, val; cin >> i >> val;
        updated_query(i, val);

        cout << cnt << el;
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
