#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 3e3;
ll n;
char a[N + 1][N + 1];
bool vs[N + 1][N + 1];

struct NODE {
    char cr; ll x, y;
};

bool cmp(const NODE& x, const NODE& y) {
    return x.cr < y.cr;
}

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
}
void solve() {
    string ans = "";
    vector<NODE> cur;
    cur.pb({a[1][1], 1, 1});
    vs[1][1] = 1;

    while(!cur.empty()) {
        vector<NODE> temp;      
        auto i = cur[0];
        ans.pb(i.cr);
        for(auto j : cur) {
            if(i.cr == j.cr) {
                if(j.x + 1 <= n && !vs[j.x + 1][j.y]) {
                    temp.pb({a[j.x + 1][j.y], j.x + 1, j.y});
                    vs[j.x + 1][j.y] = true;
                }
                if(j.y + 1 <= n && !vs[j.x][j.y + 1]) {
                    temp.pb({a[j.x][j.y + 1], j.x, j.y + 1});
                    vs[j.x][j.y + 1] = true;
                }
            }
        }
        sort(all(temp), cmp);

        cur = temp;
    }

    cout << ans;
}
void write() {

}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}