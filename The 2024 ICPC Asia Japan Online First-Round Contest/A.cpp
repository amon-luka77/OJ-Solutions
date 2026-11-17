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
        int sum = 0;
        FOR(i, 1, n) {
            int x; cin >> x;
            if(sum + x <= 300) sum += x;
        } cout << sum << "\n";
    }
}
