#include <bits/stdc++.h>
using namespace std;

// Returns the minimal number of disjoint (pairwise index-disjoint) increasing subsequences
// needed to cover the permutation 'a'.
// By Dilworth: this equals the length of the longest decreasing subsequence.
int min_num_increasing_subseq(const vector<int>& a) {
    vector<int> tails;          // tails[k] = minimum possible tail of an inc. subseq of length k+1 in -a
    tails.reserve(a.size());
    for (int x : a) {
        int y = -x;             // decreasing in a  <=> increasing in -a
        auto it = lower_bound(tails.begin(), tails.end(), y); // strict LIS on y
        if (it == tails.end()) tails.push_back(y);
        else *it = y;
    }
    return static_cast<int>(tails.size()); // = length of LDS in 'a'
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
	cout << min_num_increasing_subseq(a) << endl;
    return 0;
}
