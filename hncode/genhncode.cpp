#include <bits/stdc++.h>
#define ll long long
#define el "\n"
using namespace std;

const string NAME = "";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const ll NTEST = 10;           // number of tests

mt19937_64 rd;

ll Rand(ll lo,ll hi){
    assert(lo <= hi);
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, ll testId){
    ll n = 400;
    input << n << el;
    for(ll i = 1; i <= n; i ++) input << Rand(-1e6, 1e6) << ' ';
    cout << el;
    for(ll i = 1; i <= n; i ++) input << Rand(-1e6, 1e6) << ' ';
    cout << el;
}

int main(){
    unsigned randomSeed = chrono::system_clock::now().time_since_epoch().count();

    rd.seed(randomSeed);
    for(ll _ = 1; _ <= NTEST; _++){
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
            input  = NAME + "\\Test" + id + "\\" + NAME + ".INP",
            output = NAME + "\\Test" + id + "\\" + NAME + ".OUT";


        ofstream inputFile(input.c_str());

        // create input
        makeTest(inputFile, _);
        inputFile.close();

        // create output
        system((program + ".exe < " + input + " > " + output).c_str());
    }
}