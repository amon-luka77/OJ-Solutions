#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;

    const int N = 2e5, mod = 1e9 + 7;

    static int a[N + 1], dp[N + 1];
    static int prePrefix[N + 1], cntNum[N + 1];

    FOR(i, 1, n) cin >> a[i];
    string s; cin >> s; s = ' ' + s;

    static int posLeft[N + 1];

    int pos = 0;

    vector<int> b; FOR(i, 1, n) b.push_back(a[i]);
    sort(b.begin(), b.end()); b.erase(unique(b.begin(), b.end()), b.end());
    FOR(i, 1, n) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
     
    FOR(i, 1, n) {
        if(s[i] == '1') pos = i;
        posLeft[i] = pos;
    }

    int cnt = 0, l = 1;

    int* prefix = prePrefix + 1;
    prefix[0] = 1;

    FOR(i, 1, n) {
        if(!cntNum[a[i]]) cnt ++;
        cntNum[a[i]] ++;
        while(cnt > k && l <= i) {
            if(cntNum[a[l]] == 1) cnt --;
            cntNum[a[l ++]] --;
        }

        if(l <= posLeft[i]) dp[i] = ((prefix[posLeft[i] - 1] - prefix[l - 2]) % mod + mod) % mod;
        // if(l == 1 && l <= posLeft[i]) dp[i] = (1 + dp[i]) % mod;

        prefix[i] = (prefix[i - 1] + dp[i]) % mod;

        // cout << "INDEX: " << i << ' ' << l << ' ' << posLeft[i] << " dp: " << dp[i] << "\n";
    }

    cout << dp[n];
}
