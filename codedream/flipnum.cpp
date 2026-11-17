/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME "flipnum"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 0;
ll n;

void read() {
    cin >> n;
}

namespace Sub1 {
    bool check() {return n <= 10;}
    void solve() {
        if(n < 9) cout << n + 1;
        else cout << 11;
    }
}

namespace Sub2 {
    bool check() {
        ll k = n;
        while(k % 10 == 0) k /= 10;
        return k <= 9;
    }

    void solve() {
        ll num = n + 1;
        string s = to_string(num);
        reverse(all(s)); cout << s;
    }
}

namespace Sub3 {
    bool check() {return 1;}

    bool checkNum(ll num) {
        while(num > 0) {
            if(num % 10 != 9) return 0;
            num /= 10;
        } return 1;
    }

    void solve() {
        if(checkNum(n / 10)) {
            ll x = n % 10;
            ll num;
            if(x < 9) {
                num = n + 1;
            } else {
                num = n + 2;
            }
            string s = to_string(num);
            reverse(all(s)); cout << s;
        } else {
            string s = to_string(n);
            string num = "";
            FOR(i, 0, s.size() - 1) {
                if(s[i] != '9') {num.pb(char(s[i] + 1)); break;}
                num.pb('9');
            }
            ll len = s.size() - num.size() - 1;
            FOR(i, 1, len) num.pb('0');
            num.pb('1');
            reverse(all(num));
            ll ans = stoll(num);

            if(n % 10 == 0) {
                ll kk = n + 1;
                ll NUM = 0;
                while(kk > 0) {
                    NUM = NUM * 10 + (kk % 10);
                    kk /= 10;
                } cout << min(NUM, ans);
            } else cout << ans;
        }
    }
}

void solve() {
    if(Sub1::check()) return Sub1::solve(), void();
    if(Sub2::check()) return Sub2::solve(), void();
    if(Sub3::check()) return Sub3::solve(), void();
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}
