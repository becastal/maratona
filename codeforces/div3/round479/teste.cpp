#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; 
    cin >> n >> k;
    vector<int> v(n);
    for (int& i : v) 
        cin >> i;
    sort(v.begin(), v.end());

    // Case when k equals n: choose the largest number.
    if (k == n) {
        cout << v.back() << "\n";
        return 0;
    }
    
    // Case when k equals 0: choose any number smaller than the smallest element.
    if (k == 0) {
        cout << (v[0] > 1 ? 1 : -1) << "\n";
        return 0;
    }
    
    // For 0 < k < n, candidate is the k-th smallest element (0-indexed: v[k-1])
    int candidate = v[k - 1];
    
    // Check if candidate gives exactly k numbers <= candidate.
    // That is, v[k] (the (k+1)-th element) must be strictly greater than candidate.
    if (v[k] == candidate) {
        cout << -1 << "\n";
    } else {
        cout << candidate << "\n";
    }
    
    return 0;
}
