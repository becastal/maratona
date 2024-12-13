#include <bits/stdc++.h>
using namespace std;

bool ehprimo(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (ehprimo(x)) {
			cout << "Prime" << endl;
		} else {
			cout << "Not Prime" << endl;
		}
	}
    
    return(0);
}
