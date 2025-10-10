#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n = 10;
	vector<int> A(5, 0);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		A[x]++;
	}

	int res = 0;
	for (int i = 1; i < 5; i++) {
		res += !A[i];
	}
	cout << res << endl;
	
	return 0;
}
