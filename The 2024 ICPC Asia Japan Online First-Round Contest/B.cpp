
#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n) {
        if(n == 0) break;

        vector<int> a(n + 1, 0), b(n + 1, 0);
        vector<int> ra(n + 1, 0), rb(n + 1, 0);

        FOR(i, 1, n) {cin >> a[i]; ra[i] = ra[i - 1] + a[i];}
        FOR(i, 1, n) {cin >> b[i]; rb[i] = rb[i - 1] + b[i];}

        int type = 0, res = 0;

        FOR(i, 1, n) {
            if(ra[i] == rb[i]) continue;
            if(type == 0 && ra[i] != rb[i]) {
                type = (ra[i] < rb[i] ? 1 : 2);
                continue;
            }
            if(type == 1 && ra[i] > rb[i]) {
                type = 2; res ++; continue;
            }
            if(type == 2 && ra[i] < rb[i]) {
                type = 1; res ++; continue;
            }
        }

        cout << res << "\n";
    }
}
