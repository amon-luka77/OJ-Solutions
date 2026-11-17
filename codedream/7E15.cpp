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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e4;
int n, w, a[N + 1];

void read() {
    cin >> n >> w;
    FOR(i, 1, n) cin >> a[i];
}

namespace Sub1 {
    bool check() {
        return (n <= 100);
    }
 
    ll cnt = 0;
 
    void solve() {
        FOR(i, 1, n) FOR(j, i + 1, n) if(a[i] < a[j]) FOR(k, j + 1, n) if(a[j] < a[k]) {
            cnt += (a[i] + a[j] + a[k] <= w);
        }
 
        cout << cnt;
    }
}

namespace Sub2 {
    bool check() {
        return n <= 2000;
    }

    ll bit[N + 1], cnt = 0;

    void updated(ll i, ll val) {
        for(; i <= n; i += i & -i) bit[i] += val;
    }

    ll getSum(ll l, ll r) {
        l --; if(l > r) return 0;
        ll res = 0;
        for(; l >= 1; l -= l & -l) res -= bit[l];
        for(; r >= 1; r -= r & -r) res += bit[r];
        return res;
    }

    void solve() {
        vector<ll> b;
        FOR(i, 1, n) b.pb(a[i]);
        sort(all(b)); b.erase(unique(all(b)), b.end());
        FOR(i, 1, n) a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
        // FOR(i, 1, n) cout << a[i] << ' ';

        FOR(i, 1, n) {
            FOR(j, i + 1, n) if(a[i] < a[j]) {
                cnt += getSum(1LL, min(a[i] - 1, (int)(upper_bound(all(b), w - (b[a[i] - 1LL] + b[a[j] - 1LL])) - b.begin())));
            }
            updated(a[i], 1);
        }

        cout << cnt;
    }
}

namespace Sub3 {
    bool check() {
        return 1;
    }

    pair<int, int> b[N + 1];
    int Left[N + 1], Right[N + 1];

    void solve() {
        FOR(i, 1, n) b[i] = {a[i], i};
        sort(b + 1, b + n + 1);
        ll res = 0;
        int cntLeft = 0, cntRight = 0;
        
        FOR(i, 2, n) {
            cntLeft = 0, cntRight = 0;

            FOR(j, 1, n) {
                if(b[j].ft < a[i] && b[j].sc < i) Left[++cntLeft] = b[j].ft;
                if(b[j].ft > a[i] && b[j].sc > i) Right[++cntRight] = b[j].ft;
            }

            if(!cntLeft || !cntRight) continue;

            int r = cntRight, limit = w - a[i];
            FOR(j, 1, cntLeft) {
        // cerr << "begin" << el;
                while(Left[j] + Right[r] > limit && r > 0) {r --;}
        // cerr << "end\n";
                if(Left[j] + Right[r] <= limit) res += r;
                // cerr << r << el;
            }
            
            // cerr << i << el;
        }

        cout << res;
    }
}

void solve() {
    // if(Sub1::check()) {Sub1::solve(); return;}
    // if(Sub2::check()) {Sub2::solve(); return;}
    if(Sub3::check()) {Sub3::solve(); return;}
}

void write() {

}

int main() {
    boost;
    // file("7E15");
    read();
    solve();
    write();
    return 0;
}