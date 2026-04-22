#include <bits/stdc++.h>
using namespace std; 

int main() {
 
    int s, va, vb; 
    while (cin >> s >> va >> vb) {    
        if (vb >= va) {
			cout << "impossivel\n", 0;
			continue;
		}
        double res = 1.0 * s / (va - vb);
        cout << fixed << setprecision(2) << res << "\n";
    }
 
    return 0;
}
