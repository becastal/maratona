#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string A, B; cin >> A >> B;

	string A_ = "";
	for (char c : A) {
		A_.push_back(c);

		if ((int)A_.size() >= 4 and A_.substr((int)A_.size() - 4) == "(xx)") {
			for (int i = 0; i < 4; i++) {
				A_.pop_back();
			}
			A_.push_back('x');
			A_.push_back('x');
		}
	}

	string B_ = "";
	for (char c : B) {
		B_.push_back(c);

		if ((int)B_.size() >= 4 and B_.substr((int)B_.size() - 4) == "(xx)") {
			for (int i = 0; i < 4; i++) {
				B_.pop_back();
			}
			B_.push_back('x');
			B_.push_back('x');
		}
	}

	cout << (A_ == B_ ? "Yes" : "No") << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

