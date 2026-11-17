#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 3e5, LOG = 25;
int n, a;
pair<int, int> b[N + 1];

struct RMQ {
    vector<int> a;
    vector<vector<int>> value;
    int n;
    int maxBit;

    #define MASK(i) (1LL << (i))

    #define VALUE(x, y) (a[x] > a[y] ? x : y)

    void build(const vector<int> &_value) {
        a = _value;
        n = value.size();
        maxBit = 31 - __builtin_clzll(n);
        value.resize(maxBit + 1);

        FOR(i, 1, n) value.resize(n - MASK(i) + 1);

        FOR(i, 1, n) value[0][i] = i;
        FOR(j, 1, LOG) FOR(i, 1, n) {
            value[j][i] = VALUE(value[j - 1][i], value[j - 1][i + MASK(j - 1)]);
        }
    }

    int getMax(int l, int r) {
        int k = __lg(r - l + 1);
        return VALUE(value[k][l], value[k][r - MASK(k) + 1]);
    }
};

RMQ max_diff, min_prefix, max_prefix;

vector<int> prefix, diff, C, D;

ll dnc(int l, int r) {
    if(l == r) return 0;

    int mid = max_diff.getMax(l, r);

    ll res = max(dnc(l, mid), dnc(mid + 1, r));
    return max(res, (ll)max_prefix.getMax(mid, r) + min_prefix.getMax(l, mid) - diff[mid]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a;
    D.resize(n + 1);
    C.resize(n + 1);
    prefix.resize(n + 1);
    diff.resize(n + 1);
    FOR(i, 1, n) cin >> D[i] >> C[i];

    FOR(i, 1, n) prefix[i] = prefix[i - 1] + a - C[i];
    FOR(i, 2, n) diff[i] = (D[i] - D[i - 1]) * (D[i] - D[i - 1]);

    max_diff.build(diff);
    max_prefix.build(prefix);

    FOR(i, 1, n) prefix[i] = -prefix[i];

    min_prefix.build(prefix);

    cout << dnc(1, n);
}
