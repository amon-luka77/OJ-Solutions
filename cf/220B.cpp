#include<bits/stdc++.h>
#define ll long long
#define FOR(i ,a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    const int N = 1e5;

    static int a[N + 1];
    static vector<int> b, pos[N + 1];

    for(int i = 1; i <= n && cin >> a[i]; i ++) b.push_back(a[i]);
    sort(b.begin(), b.end()); b.erase(unique(b.begin(), b.end()), b.end());

    FOR(i, 1, n) {
        a[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        pos[a[i]].push_back(i);
    }
    
    while(q --) {
        int l, r; cin >> l >> r;
        int res = 0, limit = sqrt(r - l + 1);

        FOR(i, 0, b.size() - 1) {
            if(b[i] > limit) break;
            int pp = i + 1;
            int cnt = int(upper_bound(pos[pp].begin(), pos[pp].end(), r)
                        - lower_bound(pos[pp].begin(), pos[pp].end(), l));
            res += (cnt == pp); 
        }

        cout << res << "\n";
    }
}