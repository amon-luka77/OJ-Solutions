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
ll n, q, block = 0, cnt = 0, sum = 0, a[N + 1];
unordered_map<ll, ll> blockDiff;
pair<ll, ll> ans[N + 1];
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
    vector<QUERY> k;
    for(ll i = 1; i <= q; i ++) {
        ll x, l, r; cin >> x >> l >> r;
        if(x == 1) {
            if(!k.empty()) {
                sort(all(k), [](QUERY &x, QUERY &y) {
                    ll rx = x.y / block;
                    ll ry = y.y / block;

                    if(rx != ry) return rx < ry;
                    else {
                        if(rx % 2) return x.z < y.z;
                        return x.z > y.z;
                    }
                });
                query.pb({2, k});
                k.clear();
            }
            vector<QUERY> t;
            t.pb({x, l, r, i});
            query.pb({1, t});
        } else {
            k.pb({x, l, r, i});
        }
    }

    if(!k.empty()) {
        sort(all(k), [](QUERY &x, QUERY &y) {
            ll rx = x.y / block;
            ll ry = y.y / block;

            if(rx != ry) return rx < ry;
            else {
                if(rx % 2) return x.z < y.z;
                return x.z > y.z;
            }
        });
        query.pb({2 ,k});
    }
}

void change(ll i, ll val) {
    if(curL <= i && i <= curR) {
        blockDiff[a[i]] --;
        if(blockDiff[a[i]] == 0) {
            cnt --;
            sum -= a[i];
        }
        
        blockDiff[val] ++;
        if(blockDiff[val] == 1) {
            cnt ++;
            sum += val;
        }
    }

    a[i] = val;
}

void add(ll k) {
    blockDiff[a[k]] ++;
    if(blockDiff[a[k]] == 1) {
        cnt ++;
        sum += a[k];
    }
}

void remove(ll k) {
    blockDiff[a[k]] --;
    if(blockDiff[a[k]] == 0) {
        cnt --;
        sum -= a[k];
    }
}

void solve() {

    vector<QUERY> ans;

    for(auto &[x, y] : query) {
        if(x == 1) {
            change(y[0].y, y[0].z);
        } else {
            for(auto &[v, i, j, t] : y) {
                while(curL > i) add(-- curL);
                while(curL < i) remove(curL ++);
                while(curR > j) remove(curR --);
                while(curR < j) add(++ curR);

                ans.pb({t, cnt, sum, 0});
            }

        }
    }

    sort(all(ans), [](QUERY &x, QUERY &y) {
        return x.x < y.x;
    });

    for(auto [x, l, r, t] : ans) {
        cout << l << ' ' << r << el;
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
