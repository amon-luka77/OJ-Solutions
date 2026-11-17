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
    
    const int N = 3e5, block = 400;

    static int a[N + 1];

    int n; cin >> n;
    FOR(i, 1, n) cin >> a[i];

    static struct QUERY {
        int l, r, id; int64_t ord;

        bool operator < (const QUERY &other) const {
            return ord < other.ord;
        }
    } q[N + 1];

    int numQuery; cin >> numQuery;

    FOR(i, 1, numQuery) {cin >> q[i].l >> q[i].r; q[i].id = i; q[i].ord = hilbertOrder(q[i].l, q[i].r, 21, 0);}

    static int Ans[N + 1];

    sort(q + 1, q + numQuery + 1);

    int l = 1, r = 0;

    static multiset<int> k, kk;

    auto add = [&](int pos) {
        auto it = k.insert(a[pos]);
        auto l = (it == k.begin() ? k.end() : prev(it));
        auto r = next(it);

        if(l != k.end()) kk.insert(abs(*it - *l));
        if(r != k.end()) kk.insert(abs(*it - *r));
        if(l != k.end() && r != k.end()) kk.erase(kk.find(abs(*l - *r)));
    };

    auto remove = [&](int pos) {
        auto it = k.find(a[pos]); if(it == k.end()) return;
        auto l = (it == k.begin() ? k.end() : prev(it));
        auto r = next(it);

        if(l != k.end()) kk.erase(kk.find(abs(*it - *l)));
        if(r != k.end()) kk.erase(kk.find(abs(*it - *r)));
        if(l != k.end() && r != k.end()) kk.insert(abs(*l - *r));

        k.erase(it);
    };

    FOR(i, 1, numQuery) {
        while(l > q[i].l) add(-- l);
        while(r < q[i].r) add(++ r);
        while(l < q[i].l) remove(l ++);
        while(r > q[i].r) remove(r --);

        Ans[q[i].id] = *kk.begin();
    }

    FOR(i, 1, numQuery) cout << Ans[i] << "\n";
}