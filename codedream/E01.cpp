#include <bits/stdc++.h>
#define ll long long
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
const ll N = 4e5;
ll t, n, a[N + 1], c[N + 1];
vector<ll> b;

void read() {
    cin >> t;
}

ll binaryPos(ll tg) {
    int l = 1, r = b.size() - 1, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(b[mid] <= tg) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

ll binaryP(ll tg) {
    int l = 1, r = b.size() - 1, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(b[mid] + tg <= 0) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

struct BIT {
    int maxN;
    vector<ll> bit;

    BIT() {
        bit.assign(N + 1, 0);
    }

    void resize(int n) {
        maxN = n;
        fill(bit.begin() + 1, bit.begin() + maxN + 1, 0);
    }

    void updated(int i, ll val) {
        for(; i <= maxN; i += i & -i) bit[i] += val;
    }

    ll get(int i) {
        if(i <= 0) return 0;
        ll res = 0;
        for(; i >= 1; i -= i & -i) res += bit[i];
        return res;
    }

    ll getSum(int l, int r) {
        if(l > r) return 0;
        return get(r) - get(l - 1);
    }
};

BIT bit, bitCnt, bitSum;

void solve() {
    while(t --) {
        cin >> n;
        bit.resize(n);
        b.clear(); b.pb(0);
        FOR(i, 1, n) {
            cin >> a[i];
            a[i + n] = a[i];
            b.pb(a[i] - i); b.pb(a[i + n] - (i + n));
        }

        sort(b.begin() + 1, b.end());
        b.erase(unique(b.begin() + 1, b.end()), b.end());
        int bSize = b.size() - 1;
        bitCnt.resize(bSize); 
        bitSum.resize(bSize);
        vector<ll> ans;

        FOR(i, 1, (n << 1)) {
            c[i] = binaryPos(a[i] - i);
        }

        ll inv = 0, p = 0, allSum = 0;
        FOR(i, n + 1, (n << 1)) {
            inv += bit.getSum(a[i], n);
            bit.updated(a[i], 1);
            p += abs(a[i] - (i - n));
            allSum += a[i] - i;
            bitCnt.updated(c[i], 1);
            bitSum.updated(c[i], a[i] - i);
        }

        // FOR(i, 1, b.size() - 1) {
        //     cout << b[i] << ' ';
        // }
        // cout << el;

        if(inv <= (p >> 1)) ans.pb(0);
        int pos = 0;

        FORD(l, n, 2) {
            int r = l + n - 1; p = 0;
            inv -= bit.getSum(a[r + 1] + 1, n);
            allSum -= (a[r + 1] - (r + 1));
            allSum += (a[l] - l);

            bit.updated(a[r + 1], -1);
            inv += bit.getSum(1, a[l] - 1);
            bit.updated(a[l], 1);
            bitCnt.updated(c[r + 1], -1); bitCnt.updated(c[l], 1);
            bitSum.updated(c[r + 1], -(a[r + 1] - (r + 1)));
            bitSum.updated(c[l], a[l] - l);

            pos = binaryP(l - 1);
            ll cnt = bitCnt.get(pos);
            ll sum = bitSum.get(pos);

            // a[i] - i + (l - 1);
            p = allSum - (sum << 1) + (l - 1) * (r - l + 1 - (cnt << 1));
            if(inv <= (p >> 1)) ans.pb(n - l + 1);
        }

        cout << ans.size() << el;
        for(auto i : ans) cout << i << ' ';
        cout << el;
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