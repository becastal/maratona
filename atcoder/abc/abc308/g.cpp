#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int q; cin >> q;
	
	multiset<int> S;
	map<int, int> M;

	while (q--) {
		int tp; cin >> tp;

		if (tp == 1) {
			int x; cin >> x;
			S.insert(x);
			auto b = S.find(x);
			auto a = (b != S.begin() ? prev(b) : S.end());
			auto c = next(b);

			if (c != S.end() and a != S.end()) {
				if (--M[*a ^ *c] == 0) M.erase(*a ^ *c);
			}
			if (a != S.end()) {
				M[*a ^ *b]++;
			}
			if (c != S.end()) {
				M[*b ^ *c]++;
			}
		} else if (tp == 2) {
			int x; cin >> x;
			auto b = S.find(x);
			auto a = (b != S.begin() ? prev(b) : S.end());
			auto c = next(b);

			if (a != S.end()) {
				if (--M[*a ^ *b] == 0) M.erase(*a ^ *b);
			}
			if (c != S.end()) {
				if (--M[*b ^ *c] == 0) M.erase(*b ^ *c);
			}
			if (a != S.end() and c != S.end()) {
				M[*a ^ *c]++;
			}
			S.erase(b);
		} else if (tp == 3) {
			cout << M.begin()->first << endl;
		}
	}

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

