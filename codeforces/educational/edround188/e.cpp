#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string S; cin >> S;
	int s = 0;

	if (S.size() == 1) return cout << S << endl, 0;

	vector<int> C(10);
	for (char c : S) {
		s += (c - '0');
		C[(c - '0')]++;
	}

	for (int i = 1; i < s; i++) {
		vector<int> C_(C);

		auto f = [&](int x) {
			int res = 0;
			while (x) {
				res += x % 10;
				x /= 10;
			}
			return res;
		};

		int x;
		string S_;
		for (x = i; x > 9; x = f(x)) {
			S_ += to_string(x); 
		}
		S_ += to_string(x); 

		int ruim = 0;
		for (char c : S_) {
			ruim |= (--C_[c - '0'] < 0);
		}
		if (ruim) continue;

		int acum_ = 0;
		for (int j = 1; j <= 9; j++) {
			acum_ += C_[j] * j;
		}

		if (acum_ == i) {
			for (int j = 9; j >= 0; j--) if (C_[j]) {
				cout << string(C_[j], char('0' + j));
			}
			cout << S_ << endl;
			return 0;
		}
	}

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

