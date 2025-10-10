#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	vector<int> A, B;
	for (int i = 0; i < n; i++) {
		if (S[i] == 'a') A.push_back(i);
		else if (S[i] == 'b') B.push_back(i);
	}

	ll res = LLONG_MAX, a = 0, b = 0;
	for (int i = 0; i < (int)A.size(); i++) {
		a += llabs(A[i] - i);
	}

	res = min(res, a);
	for (int i = (int)A.size()-1, j = n-1; i >= 0; i--) {
		a -= llabs(A[i] - i);
		a += llabs(A[i] - j--);
		res = min(res, a);
	}

	for (int i = 0; i < (int)B.size(); i++) {
		b += llabs(B[i] - i);
	}

	res = min(res, b);
	for (int i = (int)B.size()-1, j = n-1; i >= 0; i--) {
		b -= llabs(B[i] - i);
		b += llabs(B[i] - j--);
		res = min(res, b);
	}

	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

