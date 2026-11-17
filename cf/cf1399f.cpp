#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t --) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for(auto &i : a) cin >> i;
        for(auto i : a) cout << i << ' ';
        cout << "\n";
    }
}
