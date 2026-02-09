#include <bits/stdc++.h>

using namespace std;
int main() {
	int n, q; cin >> n >> q;

	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int t = 0; t < q; t++) {
		int x; cin >> x;

		int l = 0, r = n-1, i = -1;	
		while (l <= r) {
			int m = l + (r - l) / 2;	

			if (A[m] >= x) {
				r = m - 1;	
				i = m;
			} else {
				l = m + 1;				
			}
		}

		if (i == -1 or A[i] != x) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
	
	return 0;
}
