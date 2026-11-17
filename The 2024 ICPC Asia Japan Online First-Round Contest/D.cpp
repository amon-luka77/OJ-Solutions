#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

int binaryRight(const vector<int> &aa, int val) {
    if(aa.empty() || val > aa.back()) return -1;
    int l = 0, r = aa.size() - 1, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(val <= aa[mid]) {
             r = mid - 1; ans = mid;
        } else l = mid + 1;
    } return aa[ans];
}

int binaryRight(const vector<int> &aa, int val) {
    if(aa.empty() || val < aa.front()) return -1;
    int l = 0, r = aa.size() - 1, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(val >= aa[mid]) {
             l = mid + 1; ans = mid;
        } else r = mid - 1;
    } return aa[ans];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> n) {
        if(n == 0) break;
        cin >> a >> b >> d;
        int direction = 0;

        reset();

        FOR(i, 1, n) {
            int x, y; cin >> x >> y;
            A[x].pb(y);
            B[y].pb(x);
        }

        #define all(x) (x).begin(), (x).end()

        FOR(i, 0, 100) {
            if(!A[i].empty()) sort(all(A[i]));
            if(!B[i].empty()) sort(all(B[i]));
        }

        /*
        dir = 0 -> right;
        dir = 1 -> up
        dir = 2 -> left
        dir = 3 -> down
        */

        while(d) {
            if(check()) {
                if(direction == 0) a += d;
                else if(direction == 1) b += d;
                else if(direction == 2) a -= d;
                else b -= d;
                break;
            } else {
                if(direction == 0) {
                    int nextA = binaryRight(B[b], a)
                    if(nextA == -1 || d <= nextA - a) {a += d; break;}
                    else {d -= (nextA - a); a = nextA;}
                } else if(direction == 1) {
                    int nextB = binaryRight(A[a], b);
                    if(nextB == -1 || d <= nextB - b) {b += d; break;}
                    else {d -= (nextB - b); b = nextB;}
                } else if(direction == 2) {
                    int nextA = binaryLeft(B[b], a)
                    if(nextA == -1 || d <= a - nextA) {a -= d; break;}
                    else {d -= (a - nextA); a = nextA;}
                } else {
                    int nextB = binaryLeft(A[a], b);
                    if(nextB == -1 || d <= b - nextB) {b -= d; break;}
                    else {d -= (b - nextB); b = nextB;}
                }
                direction = (direction + 1) % 4;
            }
        }
    }
}
