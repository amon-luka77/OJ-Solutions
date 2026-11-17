#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

namespace {
vector<int> hidden;
int limit = 0;
int calls = 0;
bool active = false;

bool run_case(vector<int> permutation, const vector<int>& expected) {
    hidden = std::move(permutation);
    limit = static_cast<int>(hidden.size() * hidden.size());
    calls = 0;
    active = true;
    vector<int> received = solve(static_cast<int>(hidden.size()));
    active = false;
    return received == expected;
}
}  // namespace

int query(int i, int j) {
    if (!active || i < 0 || j < 0 || i >= static_cast<int>(hidden.size()) ||
        j >= static_cast<int>(hidden.size()) || ++calls > limit) {
        cerr << "FAIL: invalid or excessive query" << '\n';
        exit(2);
    }
    return hidden[i] ^ hidden[j];
}

int main() {
    if (!run_case({2, 0, 3, 1}, {0, 2, 1, 3})) {
        cerr << "FAIL: wrong answer for the four-element permutation" << '\n';
        return 1;
    }
    if (!run_case({0}, {0})) {
        cerr << "FAIL: wrong answer for the one-element permutation" << '\n';
        return 1;
    }
    cout << "PASS" << '\n';
    return 0;
}
