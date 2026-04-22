#include <bits/stdc++.h>

using namespace std;
int main() {
    int n; cin >> n;
    for (int t = 0; t < n; t++) {
        int a, b; cin >> a >> b;
		cout << gcd(a, b) << "\n";
    }
    
    return 0;
}
