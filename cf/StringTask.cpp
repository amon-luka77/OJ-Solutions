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
const ll N = 0;
string s;
void read() {
    cin >> s;
    for(auto i : s) {
        if(i == 'A' || i == 'a'
            || i == 'O' || i == 'o'
            || i == 'y' || i == 'Y' 
            || i == 'E' || i == 'e'
            || i == 'U' || i == 'u'
            || i == 'I' || i == 'i') continue;
        char x = tolower(i);
        cout << '.' << x;
    }
}
void solve() {

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