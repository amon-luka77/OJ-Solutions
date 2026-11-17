#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];

    vector<ll> num, len;

    FOR(i, 1, n) {
        int j = i;
        while(j <= n && a[i] == a[j]) j ++;
        num.push_back(a[i]);
        len.push_back(j - i);
        i = j - 1;
    }

    ll res = 0;
    for(auto i : len) res += i * (i - 1) / 2;

    vector<ll> d; d.push_back(0);
    FOR(i, 1, num.size() - 1) {
        d.push_back((num[i] < num[i - 1] ? 1 : -1));
    }

    // 6
    // 1 2 4 4 3 3
    // num: 1 2 4 3
    // len: 1 1 2 2
    // d:   1 1 -1

    ll sum = 0;
    FOR(i, 0, num.size() - 1) {
        if(i > 0 && d[i] == d[i - 1]) {
            sum = len[i - 1];
        }

        res += sum * len[i];
        sum += len[i];
    }

    cout << res;
}
