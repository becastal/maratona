#include <bits/stdc++.h>

using namespace std;
int main() {

	int size, target;
	cin >> size >> target;

	unordered_map<int, int> M;
	for (int i = 0; i < size; i++) {
		int x; cin >> x;

		if (M.count(target - x)) {
			cout << i << ", " << M[target - x] << endl;
			return 0;
		}

		M[x] = i;
	}
	cout << "-1, -1" << endl;


	return 0;
}
