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

	set<int> a, A;
	for (int i = 0; i < n; i++) {
		if (islower(S[i])) {
			a.insert(i);
		} else {
			A.insert(i);
		}
	}

	int q; cin >> q;
	while (q--) {
		int tp, pos; char c;
		cin >> tp >> pos >> c; pos--;

		if (tp == 1) {
			if (a.count(pos)) a.erase(pos);
			if (A.count(pos)) A.erase(pos);
			S[pos] = c;
			if (islower(c)) {
				a.insert(pos);
			} else {
				A.insert(pos);
			}
		} else if (tp == 2) {
			// todo mundo pra a
			if (a.size() > A.size()) {
				swap(a, A);
			}

			for (int i : a) {
				A.insert(i);
			}
			a.clear();
			swap(a, A);

		} else if (tp == 3) {
			if (a.size() > A.size()) {
				swap(a, A);
			}

			for (int i : a) {
				A.insert(i);
			}
			a.clear();
			//swap(a, A);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << char(a.count(i) ? tolower(S[i]) : toupper(S[i]));
	}
	cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

