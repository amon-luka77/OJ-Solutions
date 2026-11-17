#include<bits/stdc++.h>
#define ll long long
#define ft first 
#define sc second
using namespace std;
ll a[25][25];
ll so0 = 0;
map<ll, ll> hang[15];
map<ll, ll> cot[15];
map<ll, ll> bang33[15][15];
void backtrack(ll row, ll col, ll pos) {
    if(pos == 81) {
        for(ll i = 1; i <= 9; i ++) {
            for(ll j = 1; j <= 9; j ++) {
                cout << a[i][j] << ' ';
            }
            cout << "\n";
        }
        exit(0);
    }
    if(a[row][col] == 0) {
        for(ll j = 1; j <= 9; j ++) {
            if((hang[row][j] != 0) 
            || (cot[col][j] != 0) 
            || (bang33[(row-1)/3][(col-1)/3][j] != 0)) continue;
            a[row][col] = j;
            hang[row][j] ++;
            cot[col][j] ++;
            bang33[(row-1)/3][(col-1)/3][j] ++;
            if(col == 9) {
                backtrack(row + 1, 1, pos + 1);
            }else {
                backtrack(row, col + 1, pos + 1);
            }
            a[row][col] = 0;
            bang33[(row-1)/3][(col-1)/3][j] --;
            hang[row][j] --;
            cot[col][j] --;
        }
    } else {
        if(col == 9) {
            backtrack(row + 1, 1, pos + 1);
        }else backtrack(row, col + 1, pos + 1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 1; i <= 9; i ++) {
        for(ll j = 1; j <= 9; j ++) {
            cin >> a[i][j];
            if(a[i][j] == 0) so0 ++;
            else {
                hang[i][a[i][j]] ++;
                cot[j][a[i][j]] ++;
                bang33[(i-1)/3][(j-1)/3][a[i][j]] ++;
            }
        }
    }
    backtrack(1, 1, 1);
}