#include <bits/stdc++.h>

using namespace std;
int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int soma = 0;
	for (int i = 0; i < min(3, n); i++) {
		soma += v[i];	
	}

	cout << soma << endl;
}

