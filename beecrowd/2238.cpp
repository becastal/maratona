#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    
    vector<int> D;
    for (int i = 1; i * i <= c; i++) if (c % i == 0) {
        D.push_back(i);
        if (i * i != c) D.push_back(c / i);
    }
    sort(D.begin(), D.end());
    for (int i : D) {
		//cout << "d: " << i << endl;
        if (i % a == 0 and c % i == 0 and i % b != 0 and d % i != 0) {
            return cout << i << "\n", 0;
        }
    }
    cout << -1 << "\n";
 
    return 0;
}
