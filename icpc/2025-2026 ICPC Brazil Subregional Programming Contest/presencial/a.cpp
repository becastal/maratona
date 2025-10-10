#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> A(m);

	for (int i = 0; i < n ; i++) {
		for (int j = 0, x; j < m; j++) {
			cin >> x;
			A[j] = max(A[j], x);
		}
	}
	cout << accumulate(A.begin(), A.end(), 0) << endl;
	
	
	return 0;
}
