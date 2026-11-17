#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1e6;
ll n, q, block = 0, cnt = 0, sum = 0, a[N + 1], blockDiff[N + 1];
vector<ll> b;

ll binary(ll k) {
    ll l = 1, r = b.size() - 1, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;

        if(b[mid] <= k) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

ll curL = 1, curR = 0;

struct QUERY {
    ll x, y, z, t;
};

vector<pair<ll, vector<QUERY>>> query;

void read() {
    cin >> n >> q;
    block = sqrt(n); 

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    ll pos = 0;
    ll numBlock = 0;
    while(pos < n) {
        numBlock ++;
        blockStart[numBlock] = pos + 1;
        blockEnd[numBlock] = min(n, pos + block);
        pos += block;
        
        FOR(i, blockStart[numBlock], blockEnd[numBlock]) {
            blockId[i] = numBlock;
            blockTs[a[i]] ++;
            if(blockTs[a[i]] == 1) blockSum[numBlock] += a[i];
        }
    }
}

void updated(ll pos, ll val) {
    blockTS[a[pos]] --;
    if(blockTs[a[pos]] == 0) blockSum[blockId[pos]] -= a[pos];
    blockTs[val] ++;
    if(blockTs[a[pos]] == 1) blockSum[blockId[pos]] += val;
    a[pos] = val;
}

void get(ll l, ll r) {
    ll ans = 0;
    if(blockId[l] == blockId[r]) {
        mem
        FOR(i, l, r) {
        
        }
    }

}

void solve() {
    while(q --) {
        ll x, y, z; cin >> x >> y >> z;
        if(x == 1) updated(y, z);
        else get(y, z);
    }
}

void write() {
}

int main() {
    boost;
    // freopen("ad265"".inp", "r", stdin);
    // freopen(""".out", "r", stdout);
    read();
    solve();
    write();
    return 0;
}