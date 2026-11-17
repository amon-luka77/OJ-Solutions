#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 2e5;

int n, q;

pair<int, int> a[N + 1], query[N + 1];

int L[N + 1], R[N + 1], Ans[N + 1];

int bit[N + 1];

void updated(int i) {
    for(; i <= N; i += i & -i) bit[i] ++;
}

int get(int l, int r) {
    l --; if(l > r) return 0;
    int res = 0;

    for(; l; l-= l & -l) res -= bit[l];
    for(; r; r -= r & -r) res += bit[r];

    return res;
}

void parallelBinarySearch() {
    vector<vector<int>> bucket(N + 1);

    while(1) {
        bool ok = 0;
        FOR(i, 1, N) bucket[i].clear();
        
        FOR(i, 1, q) if(L[i] <= R[i]) {
            int mid = (L[i] + R[i]) >> 1;
            ok = 1;
            bucket[mid].push_back(i);
        }

        if(!ok) break;

        memset(bit, 0, sizeof bit);

        int j = 1;
        for(int i = N; i >= 1; i --) {
            while(j <= n && a[j].first >= i) updated(a[j ++].second);

            for(auto id : bucket[i]) {
                auto [x, y] = query[id];

                if(get(x, y) >= i) {
                    L[id] = i + 1;
                    Ans[id] = i;
                } else R[id] = i - 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i].first, a[i].second = i;
    FOR(i, 1, q) {
        cin >> query[i].first >> query[i].second;
        L[i] = 1, R[i] = n, Ans[i] = 0;
    }

    sort(a + 1, a + n + 1, greater<pair<int, int>>());

    parallelBinarySearch();

    FOR(i, 1, q) cout << Ans[i] << "\n";
}