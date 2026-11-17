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
const ll N = 1e5;
ll n, q, cnt = 0, block, a[N + 1];
ll blockId[N + 1], startBlock[N + 1], endBlock[N + 1];

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
        if(l > r) return 0;
        return getSum(r) - getSum(l - 1);
    }
};

BIT bit[500];

void read() {
    cin >> n >> q;
    block = sqrt(n);

    for(ll i = 1; i <= n; i ++) {
        a[i] = i;
    }

    ll pos = 0, numBlock = 0;
    for(ll i = 1; i <= (n + block - 1) / block; i ++) {
        bit[i].resize(N);
    }

    while(pos < n) {
        numBlock ++;
        startBlock[numBlock] = pos + 1;
        endBlock[numBlock] = min(pos + block, n);

        pos += block;

        for(ll i = startBlock[numBlock]; i <= endBlock[numBlock]; i ++) {
            blockId[i] = numBlock;
            bit[numBlock].updated(a[i], 1);
        }
    }


}

ll get_max(ll l, ll r, ll val) {
    ll cntMax = 0;

    if(blockId[l] == blockId[r]) {
        for(ll i = l; i <= r; i ++) {
            cntMax += (a[i] > val);
        }
    } else {
        for(ll i = blockId[l] + 1; i <= blockId[r] - 1; i ++) {
            cntMax += bit[i].get(val + 1, n);
        }

        for(ll i = l; i <= endBlock[blockId[l]]; i ++) {
            cntMax += (a[i] > val);
        }

        for(ll i = startBlock[blockId[r]]; i <= r; i ++) {
            cntMax += (a[i] > val);
        }
    }

    return cntMax;
}

ll get_min(ll l, ll r, ll val) {
    ll cntMin = 0;

    if(blockId[l] == blockId[r]) {
        for(ll i = l; i <= r; i ++) {
            cntMin += (a[i] < val);
        }
    } else {
        for(ll i = blockId[l] + 1; i <= blockId[r] - 1; i ++) {
            cntMin += bit[i].get(1, val - 1);
        }

        for(ll i = l; i <= endBlock[blockId[l]]; i ++) {
            cntMin += (a[i] < val);
        }

        for(ll i = startBlock[blockId[r]]; i <= r; i ++) {
            cntMin += (a[i] < val);
        }
    }

    return cntMin;
}

void updated(ll l, ll r, ll i) {
    if(l > r) swap(l, r);

    cnt -= get_min(l + 1, r - 1, a[l]);
    cnt -= get_max(l + 1, r - 1, a[r]);
    cnt -= (a[l] > a[r]);

    bit[blockId[l]].updated(a[l], -1);
    bit[blockId[r]].updated(a[r], -1);
    bit[blockId[l]].updated(a[r], 1);
    bit[blockId[r]].updated(a[l], 1);
    ll pre = a[l];
    a[l] = a[r];
    a[r] = pre;

    cnt += get_min(l + 1, r - 1, a[l]);
    cnt += get_max(l + 1, r - 1, a[r]);
    cnt += (a[l] > a[r]);
}

void solve() {
    for(ll i = 1; i <= q; i ++) {
        ll l, r; cin >> l >> r;
        updated(l, r, i);

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

/*
5 4
4 5
2 4
2 5
2 2

1 2 3 4 5
1; 1 2 3 5 4
2; 
*/