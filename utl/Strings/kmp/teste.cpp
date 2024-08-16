#include <bits/stdc++.h>
using namespace std;

vector<int> computePrefixFunction(const string &s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> pi = computePrefixFunction(s);

    vector<int> periods;
    for (int i = 1; i <= n; i++) {
        int k = i - pi[i - 1];  // Length of the period
        if (i % k == 0) {
            periods.push_back(k);
        }
    }

    for (int period : periods) {
        cout << period << ' ';
    }
    cout << endl;

    return 0;
}
