#include <bits/stdc++.h>

using namespace std;
int main() {

	int size, target;
	cin >> size >> target;

	vector<int> A(size);
	for (int i = 0; i < size; i++) {
		cin >> A[i];
	}

	unordered_map<int, pair<int, int>> M;
	for (int i = 0; i < size; i++) {
		int x = A[i];

		if (M.count(target - x)) {
			auto [j, k] = M[target - x];
			cout << i << ", " << j << ", " << k << endl;
			return 0;
		}

		for (int j = 0; j < i; j++) {
			M[A[i] + A[j]] = {i, j};
		}
	}

	// n * (n - 1) / 2 ~ O(n ^ 2);
	cout << "-1, -1, -1" << endl;


	return 0;
}
