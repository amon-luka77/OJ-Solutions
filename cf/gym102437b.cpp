#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

const int N = 5e5;
int n, k; string s;

int minLeft[N + 1], minRight[N + 1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> s; n = s.size(); s = ' ' + s;
    cin >> k;

    FOR(i, 1, n) minLeft[i] = (i == 1 ? (int)s[i] : min(minLeft[i - 1], (int)s[i]));
    FORD(i, n, 1) minRight[i] = (i == n ? (int)s[i] : min(minRight[i + 1], (int)s[i]));

    if(k == 1) {cout << char(minLeft[n]); return 0;}


    string ans = "";
    k -= 2;

    FOR(i, 2, n - k) {
        if(ans.empty()) {ans = char(minLeft[i - 1]) + s.substr(i, k) + char(minRight[i + k]); continue;}
        if(((int)ans[0] < minLeft[i - 1]) || ((int)ans[0] == minLeft[i - 1] && ans[1] < s[i])) continue;
        string cur = char(minLeft[i - 1]) + s.substr(i, k) + char(minRight[i + k]);
        ans = min(ans, cur);
    } cout << ans;
}
