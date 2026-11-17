#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 1e5;
int n, a[N + 1];

namespace Sub1 {
    bool check() {
        FOR(i, 1, n) if(a[i] > 1023) return 0;
        return 1;
    }

    void solve() {
        ll ans = 1e18;
        FOR(i, 0, 1024) {
            ll maxVal = 0;
            FOR(j, 1, n) maxVal = max(maxVal, (ll)a[j] ^ i);
            ans = min(ans, maxVal);
        }

        cout << ans;
    }
}

namespace Sub2 {
    bool check() {
        FOR(i, 2, n) if(a[i] != a[1]) return 0;
        return 1;
    }

    void solve() {
        cout << 0;
    }
}

namespace Sub3 {
    bool check() {return 1;}

    #define BIT(x, i) (((x) >> (i)) & 1LL)
    #define MASK(i) (1LL << (i))
    #define pb push_back

    ll dnc(const vector<int> &A, int pos) {
        if(pos < 0) return 0;
        vector<int> numA, numB;

        for(auto i : A) {
            if(BIT(i, pos)) numA.pb(i);
            else numB.pb(i);
        }

        if(numA.empty()) return dnc(numB, pos - 1);
        else if(numB.empty()) return dnc(numA, pos - 1);
        else {
            return MASK(pos) + min(dnc(numB, pos - 1), dnc(numA, pos - 1));
        }
    }

    void solve() {
        vector<int> aa;
        FOR(i, 1, n) aa.pb(a[i]);
        cout << dnc(aa, 30);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

//    if(Sub1::check()) return Sub1::solve(), 0;
//    if(Sub2::check()) return Sub2::solve(), 0;
    if(Sub3::check()) return Sub3::solve(), 0;
}
