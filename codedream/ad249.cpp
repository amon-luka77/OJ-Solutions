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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e6;
string s; ll n;

void read() {
    cin >> s; n = s.size(); s = ' ' + s;
}

vector<int> suffix_array(const string &s) {
    vector<int> sa(n + 1), tmp(n + 1), rank(n + 1);
    FOR(i, 1, n) {sa[i] = i; rank[i] = s[i];}

    for(int gap = 1; gap <= n; gap <<= 1) {
        auto cmp = [&](int a, int b) {
            if(rank[a] != rank[b]) return rank[a] < rank[b];
            int ra = a + gap <= n ? rank[a + gap] : -1;
            int rb = b + gap <= n ? rank[b + gap] : -1;
            return ra < rb;
        };

        sort(sa.begin() + 1, sa.end(), cmp);

        tmp[sa[1]] = 1;
        FOR(i, 2, n) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        
        rank = tmp;

        if(rank[sa[n]] == n) break;
    }

    return sa;
}

vector<int> build_lcp(const string &s, const vector<int> &sa) {
    vector<int> lcp(n + 1), rank(n + 1);

    FOR(i, 1, n) rank[sa[i]] = i;

    int h = 0;

    FOR(i, 1, n) {
        if(rank[i] == 1) {h = 0; continue;}
        int j = sa[rank[i] - 1];
        while(i + h <= n && j + h <= n && s[i + h] == s[j + h]) h ++;
        lcp[rank[i]] = h;
        if(h) h --;
    }

    return lcp;
}

void solve() {
    vector<int> sa = suffix_array(s);
    vector<int> lcp = build_lcp(s, sa);

    ll res = 0;
    for(auto i : lcp)  res += i;

    cout << n * (n + 1) / 2 - res;
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