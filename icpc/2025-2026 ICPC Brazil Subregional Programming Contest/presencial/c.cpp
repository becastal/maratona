#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n, a = 0; cin >> n;
	vector<int> A(n+1);
	for (int& i : A) cin >> i;

	reverse(A.begin(), A.end());
	for (int i = 0; i <= n; i++) {
		if (A[i] == 1) {
			a |= (1 << i);
		}
	}

	//cout << a << endl;

	int res = 0;
	while (a != 1) {
		//printf("%d\n", a);
		if (a & 1) {
			a = (a << 1) ^ a & ~1;
		} else {
			a >>= 1;
		}
		res++;
	}
	cout << res << endl;

	return 0;
}
