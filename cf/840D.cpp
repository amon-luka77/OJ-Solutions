#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    const int N = 3e5 + 1;

    static int a[N + 1];

    FOR(i, 1, n) cin >> a[i];

    struct QUERY {
        int l, r, k, idx;
        int64_t ord;

        bool operator < (const QUERY &other) const {
            return ord < other.ord;
        }
    };

    static QUERY query[N + 1];

    FOR(i, 1, q) cin >> query[i].l >> query[i].r >> query[i].k, query[i].ord = hilbertOrder(query[i].l, query[i].r, 21, 0), query[i].idx = i;

    sort(query + 1, query + q + 1);

    int curl = 0, curr = 0;

    static int ans[N + 1];
    static int cnt[N + 1];

    mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

    auto remove = [&](const auto &pos){return cnt[a[pos]] --, void();};

    auto add = [&](const auto &pos) {return cnt[a[pos]] ++, void();};

    fill(ans + 1, ans + q + 1, 1e9);

    FOR(i, 1, q) {
        while(curl < query[i].l) remove(curl ++);
        while(curl > query[i].l) add(-- curl);
        while(curr < query[i].r) add(++ curr);
        while(curr > query[i].r) remove(curr --);

        int len = query[i].r - query[i].l + 1;

        FOR(ii, 1, 80) {
            int val = a[query[i].l + rd() % len];

            if(cnt[val] > len / query[i].k) ans[query[i].idx] = min(ans[query[i].idx], val);
        }
    }

    FOR(i, 1, q) cout << (ans[i] == 1e9 ? -1 : ans[i]) << "\n";
}