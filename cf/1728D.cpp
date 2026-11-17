#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t --) {
        string s; cin >> s;
        int n = s.size(); s = ' ' + s;

        int i = 1;
        while(i <= n / 2 && s[i] == s[n - i + 1]) i ++;

        int j = n - i + 1;

//        cout << i << ' ' << j << "\n";

        while(i < n && s[i] == s[i + 1]) i += 2;

//        cout << i << ' ' << j << "\n";

        if(i >= j) cout << "Draw";
        else cout << "Alice";
    }
}
