#include <bits/stdc++.h>
 
using namespace std;
int main() {
 
    long long a, b;
    while (cin >> a >> b and (a or b)) {
        cout << __builtin_popcountll(a ^ b) << endl;
    }
    
    return 0;
}
