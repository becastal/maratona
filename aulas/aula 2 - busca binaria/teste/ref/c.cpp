#include <bits/stdc++.h>
using namespace std;

bool da(double tempo, vector<int>& X, vector<int>& V) {
	int n = (int)X.size();
	
	double minr = 1e18, maxl = -1e18;
	for (int i = 0; i < n; i++) {
		double r = X[i] + tempo * V[i];	
		double l = X[i] - tempo * V[i];	
		maxl = max(maxl, l);
		minr = min(minr, r);
	}
	return maxl <= minr;
}

int main() {
	int n; cin >> n;
	vector<int> X(n), V(n);
	for (int i = 0; i < n; i++) {
		cin >> X[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> V[i];
	}

	double l = 0, r = 1e9;
	for (int t = 0; t < 1000; t++) {
		double m = (l + r) / 2.0;

		if (da(m, X, V)) {
			r = m;
		} else {
			l = m;
		}
	}
	cout << fixed << setprecision(13) << l << "\n";
	
	return 0;
}
