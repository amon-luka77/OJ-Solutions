#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 3e5;
int n, m, k;
int a[N + 1], p[N + 1];

struct QUERY {
    int x, y, z;
} query[N + 1];

ll bit[N + 2];

void updated(int i, ll val) {
    for(; i <= m; i += i & -i) bit[i] += val;
}

ll get(int i) {
    ll res = 0;
    for(; i; i -= i & -i) res += bit[i];
    return res;
}

vector<int> child[N + 1];

int L[N + 1], R[N + 1], Ans[N + 1];

void updatedQuery(int i) {
    auto [x, y, z] = query[i];
    if(x <= y) {
        updated(y + 1, -z);
        updated(x, z);        
    } else {
        updated(1, z);
        updated(x, z);
        updated(y + 1, -z);
    }
}

void parallelBinarySearch() {
    vector<vector<int>> bucket(k + 1);

    while(1) {
        bool ok = 0;
        FOR(i, 1, k) bucket[i].clear();

        FOR(i, 1, n) if(L[i] <= R[i]) {
            int mid = (L[i] + R[i]) >> 1;
            ok = 1;
            bucket[mid].push_back(i);
        }

        if(!ok) break;

        memset(bit, 0, sizeof bit);

        FOR(i, 1, k) {
            updatedQuery(i);

            for(auto id : bucket[i]) {
                ll sum = 0;
                for(auto j : child[id]) sum += get(j);
                if(sum >= p[id]) {
                    R[id] = i - 1;
                    Ans[id] = i;
                } else L[id] = i + 1;
            }
        }

        // FOR(i, 1, m) cout << Ans[i] << ' ';
        // cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    FOR(i, 1, m) cin >> a[i], child[a[i]].push_back(i);
    FOR(i, 1, n) cin >> p[i];

    cin >> k;
    FOR(i, 1, k) {
        cin >> query[i].x >> query[i].y >> query[i].z;
    }

    FOR(i, 1, n) L[i] = 1, R[i] = k, Ans[i] = -1;

    parallelBinarySearch();

    FOR(i, 1, n) {
        if(Ans[i] == -1) cout << "NIE\n";
        else cout << Ans[i] << "\n";
    }
}