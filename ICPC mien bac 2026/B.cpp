#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q, p; cin >> n >> m >> q >> p;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<ll>> prefix(n + 1, vector<ll>(m + 1, 0));

    FOR(i, 1, n) FOR(j, 1, m) {
        cin >> a[i][j];
        prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
    }

    auto getSum = [](int i, int j, int x, int y, const vector<vector<ll>> &prefix) {
        return prefix[x][y] - prefix[i - 1][y] - prefix[x][j - 1] + prefix[i - 1][j - 1];
    };

    auto countPairs = [](const vector<ll> &num, ll val, int type) {
        int maxLen = 0; ll cnt = 0;
        int l = 0;
        ll sum = 0;

        FOR(r, 0, num.size() - 1) {
            sum += num[r];
            while(l <= r && sum > val) sum -= num[l ++];

            maxLen = max(maxLen, r - l + 1);
            cnt += r - l + 1;
        }

        return (type == 1 ? maxLen : cnt);
    };

    while(q --) {
        ll L, I, maxVal; cin >> L >> I >> maxVal;

        vector<ll> num;
        FOR(i, L, m) num.push_back(getSum(I - L + 1, i - L + 1, I, i, prefix) * a[I][i]);
        cout << countPairs(num, maxVal, 1) << "\n";
    }

    while(p--) {
        ll L, I, minVal, maxVal; cin >> L >> I >> minVal >> maxVal;

        vector<ll> num;
        FOR(i, L, m) num.push_back(getSum(I - L + 1, i - L + 1, I, i, prefix) * a[I][i]);

        cout << countPairs(num, maxVal, 2) - countPairs(num, minVal - 1, 2) << "\n";
    }
}
