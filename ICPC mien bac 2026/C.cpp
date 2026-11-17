#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 5e4;
const int maxN = 5e5;

int n, a[N + 1];

ll countNum[maxN + 1];
ll ans[maxN + 1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) {
        int cnt = 0, num = a[i];
        int preNum = a[i];

        while(1) {
            if(num == a[i] || (((a[i] >> (cnt - 1)) & 1LL) == 0)) {
                int cnt2 = cnt + 1;
                int newNum = num * 2 + 1;
                while(newNum <= maxN) {
                    countNum[newNum] ++;
                    ans[newNum] += cnt2;
                    newNum = newNum * 2 + 1;
                    cnt2 ++;
                }
            }

              countNum[num] ++;
              ans[num] += cnt;

              if(num == 0) break;
              preNum = num;
              num /= 2; cnt ++;
        }
    }

    ll res = 1e9;

    FOR(i, 0, maxN) if(countNum[i] == n) res = min(res, ans[i]);

    cout << res;
}
