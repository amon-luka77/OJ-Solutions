#include <bits/stdc++.h>
using namespace std;

const string NAME = "ad262_brute";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const int NTEST = 10;           // number of tests
const string xau ="0123456789abcdefghijklmnopqrstuvxy";
#define int long long
#define ll long long
#define el "\n"
mt19937_64 rd;

int Rand(int lo,int hi){
    assert(lo <= hi);
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, int testId){
    ll n, q;
    n = 5e4, q = 5e4;
    input << n << ' ' << q << el;
    for(ll i = 1; i <= n; i ++) input << Rand(0, 1e5) << ' ';
    for(ll i = 1; i <= q; i ++) {
        ll l = Rand(1, n - 1), r = Rand(l, n), k = Rand(0, 1e5);
        input << l << ' ' << r << ' ' << k << el;
    }
}

signed main(){
    unsigned randomSeed = chrono::system_clock::now().time_since_epoch().count();

    rd.seed(randomSeed);
    for(int _ = 1; _ <= NTEST; _++){
        string id;          // id of current test
        stringstream ss;
        ss << _;
        ss >> id;
       // cerr << _ << ' '  << endl;
        cout << "Making test: " << id << endl;
        string input, output, program = NAME;

        if (TestType == "CMS")
            input  = NAME + id + ".in",
            output = NAME + id + ".out";
        else
            system(("MKDIR " + NAME + "\\Test" + id).c_str()),
            input  = NAME+"\\Test" + id + '\\' + NAME + ".INP",
            output = NAME+"\\Test" + id + '\\' + NAME + ".OUT";


        ofstream inputFile(input.c_str());

        // create input
        makeTest(inputFile, _);
        inputFile.close();

        // create output
        system((program + ".exe < " + input + " > " + output).c_str());
    }
}
