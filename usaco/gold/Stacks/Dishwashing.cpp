#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

4
5
2
3

*/

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	auto da = [&A](int m) {
		vector<int> B(A.begin(), A.begin() + m), Comp(B);
		sort(all(Comp));

		for (int& i : B) {
			i = lower_bound(all(Comp), i) - Comp.begin();
		}

		int pos = 0, quero = 0;
		vector<stack<int>> S;
		for (int i : B) {
			int l = pos, r = (int)S.size() - 1, onde = -1;
			while (l <= r) {
				int mid = l + (r - l) / 2;

				if (S[mid].size() and S[mid].top() > i) {
					r = mid - 1;
					onde = mid;
				} else {
					l = mid + 1;
				}
			}

			if (onde == -1) {
				S.push_back(stack<int>());
				S.back().push(i);
			} else {
				S[onde].push(i);
			}

			while (pos < S.size() and S[pos].size() and S[pos].top() == quero) {
				S[pos].pop();
				quero++;
				if (S[pos].empty()) {
					pos++;
				}
			}
		}

		int ok = 1;
		for (stack<int>& s : S) {
			ok &= s.empty();
		}

		return ok;
	};

	int l = 1, r = n, res = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (da(mid)) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

signed main()
{
    _;
	setIO("dishes");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
