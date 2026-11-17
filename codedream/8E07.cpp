#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define el "\n"
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) << (i)) & 1LL)
#define NAME "8E07"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
ll n, q, sumT = 0;
ll query[N + 1];
vector<vector<ll>> a;

void read() {
    cin >> n >> q; vector<ll> b;
    FOR(i, 1, n) {
        ll k; cin >> k; sumT += k;
        FOR(i, 1, k) {ll x; cin >> x; b.pb(x);}
        sort(all(b), greater<ll>()); a.pb(b); b.clear();
    }
    FOR(i, 1, q) cin >> query[i];
}

namespace Sub1 {
    bool check() {
        return ((n <= 1000 && q <= 1000 && sumT <= 1000) || (n <= 25));
    }

    void solveQ(ll AMON) {
        ll x = query[AMON];
        ll maxCnt = 0, ans = 0;

        FOR(i, 0, a.size() - 1) {
            auto &b = a[i];
            ll l = 0, r = b.size() - 1, res = 0;
            while(l <= r) {
                ll mid = (l + r) >> 1;
                if(b[mid] >= x) {
                    l = mid + 1; res = mid + 1;
                } else r = mid - 1;
            }
            if(maxCnt <= res) {ans = i + 1; maxCnt = res;}
        } cout << ans << el;
    }

    void solve() {
        FOR(i, 1, q) solveQ(i);
    }
}

namespace Sub2 {
    bool check() {
        FOR(i, 1, q) if(query[i] > 10) return 0;
        return 1;
    }

    ll getAns[11];

    void solveQ(ll x) {
        ll maxCnt = 0, ans = 0;

        FOR(i, 0, a.size() - 1) {
            auto &b = a[i];
            ll l = 0, r = b.size() - 1, res = 0;
            while(l <= r) {
                ll mid = (l + r) >> 1;
                if(b[mid] >= x) {
                    l = mid + 1; res = mid + 1;
                } else r = mid - 1;
            }
            if(maxCnt <= res) {ans = i + 1; maxCnt = res;}
        } getAns[x] = ans;
    }

    void solve() {
        FOR(i, 1, 10) solveQ(i);
        FOR(i, 1, q) cout << getAns[query[i]] << el;
    }
}

namespace Sub3 {
    bool check() {return 1;}

    pair<ll, ll> newQuery[N + 1];
    ll Ans[N + 1];

    struct cmp {
        bool operator() (const pair<ll, ll> &x, const pair<ll, ll> &y) {
            return a[x.sc][x.ft] < a[y.sc][y.ft];
        }
    };

    void solve() {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
        FOR(i, 0, a.size() - 1) pq.push({0LL, i});
        FOR(i, 1, q) newQuery[i] = {query[i], i};
        sort(newQuery + 1, newQuery + q + 1, greater<pair<ll, ll>>());

        ll maxCnt = -1, ans = n;
        FOR(i, 1, q) {
//            cerr << pq.top().sc << ' ' << pq.top().ft << ' ' << newQuery[i].ft << el;
            while(!pq.empty() && a[pq.top().sc][pq.top().ft] >= newQuery[i].ft) {
                auto [valPos, pos] = pq.top(); pq.pop();
//                cerr << "type: " << pos + 1 << " vi tri : " << valPos << el;
                if(maxCnt < valPos) {ans = pos + 1; maxCnt = valPos;}
                else if(maxCnt == valPos) ans = max(ans, pos + 1);
                if(valPos < a[pos].size() - 1) pq.push({valPos + 1, pos});
            } Ans[newQuery[i].sc] = ans;
        }

        FOR(i, 1, q) cout << Ans[i] << el;
    }
}

void solve() {
    if(Sub1::check()) {Sub1::solve(); return;}
    if(Sub2::check()) {Sub2::solve(); return;}
    if(Sub3::check()) {Sub3::solve(); return;}
}


void write() {

}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    file();
    read();
    solve();
    write();
    return 0;
}
