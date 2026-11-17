#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for(int i = (a), _b = (b); i <=  _b; i ++)

using namespace std;

const int OFFSET = 1e6;

int d[2 * OFFSET + 2];
bool vs[1001];
int n, k;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;  
    vector<int> a;

    FOR(i, 1, k) {
        int x; cin >> x;
        if(!vs[x]) a.push_back(x - n);
        vs[x] = 1;
    }

    FOR(i, 0, 2 * OFFSET) d[i] = -1;
    
    queue<int> q;
    
    for(auto i : a) {
        q.push(i);
        d[i + OFFSET] = 1;
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();

        if(u == 0) {cout << d[OFFSET]; exit(0);}
        
        for(auto i : a) if(d[u + i + OFFSET] == -1) {
            d[u + i + OFFSET] = d[u + OFFSET] + 1;
            q.push(u + i);
        }
    }

    cout << d[OFFSET];
}

/*
(a1 + .. + an) / n * 1000 == k / 1000

(a1 - k) + (a2 - k) + .. + (an - k) == 0;
*/