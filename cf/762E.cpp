#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

void solve() {
    const int N = 1e5;

    static struct A {
        int pos, r, freq;

        bool operator<(const A &other) const {
            return r > other.r;
        }
    } a[N + 1];

    int n, k; cin >> n >> k;

    FOR(i, 1, n) cin >> a[i].pos >> a[i].r >> a[i].freq;

    sort(a + 1, a + n + 1);

    static vector<int> bit[int(1e4) + 1], aa[int(1e4) + 1];

    FOR(i, 1, n) aa[a[i].freq].push_back(a[i].pos);

    FOR(i, 1, int(1e4)) {
        sort(aa[i].begin(), aa[i].end()); aa[i].erase(unique(aa[i].begin(), aa[i].end()), aa[i].end());
        bit[i].assign((int)aa[i].size() + 1, 0);
    }

    auto add = [&](int id, int val) {
        int i = lower_bound(aa[id].begin(), aa[id].end(), val) - aa[id].begin() + 1;
        for(; i <= (int)aa[id].size(); i += i & -i) bit[id][i] ++;
    };

    auto get = [&] (int id, int val) {
        int i = upper_bound(aa[id].begin(), aa[id].end(), val) - aa[id].begin();
        int cnt = 0;
        for(; i; i -= i & -i) cnt += bit[id][i];
        return cnt;
    };

    ll res = 0;

    FOR(i, 1, n) {
        auto [pos, r, freq] = a[i];

        FOR(j, max(1, freq - k), min(int(1e4), freq + k)) {
            res += get(j, pos + r) - get(j, pos - r - 1);
            // cout << i << ": " << res << "\n";
        }

        add(freq, pos);
        // cerr << "i: " << get(freq, r) - get(freq, r - 1) << "\n";
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t --) solve();

    return 0;
}