#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*

7
1 1 2 1 2 3 4

*/

const int MAX = 2e5+10;
namespace seg {
	int n;
	int seg[4*MAX];

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = LLONG_MIN;
		int m = (l + r) / 2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (r < a or l > b) return LLONG_MAX;
		int m = (l + r) / 2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int update(int a, int x, int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = x;
		int m = (l + r) / 2;

		if (a <= m) update(a, x, 2*p, l, m);
		else update(a, x, 2*p+1, m+1, r);

		return seg[p] = min(seg[2*p], seg[2*p+1]);
	}
};

/*

	em:

	[1, 1, 2, 1]
	       ^  ^  nao pode contar essa aqui.
	tem que ter uma seg pros p's tambem. ult0 na real eh query
	de max nos (p + 1)'s anteriores a i.

	ou alguma coisa assim
	
	talvez uma dp
*/

int solve() {
	int n; cin >> n; seg::n = n;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i; i--;
	}
	seg::build();

	int res = 0;
	for (int i = 0, ult0 = -1; i < n; i++) {
		seg::update(A[i], i);
		int p = seg::query(0, A[i]);

		//for (int j = 0; j < n; j++) {
		//	cout << seg::query(j, j) << " \n"[j==n-1];
		//}

		int add = 0;
		if (ult0 > p or p == LLONG_MIN) {
			ult0 = i;
		} else {
			res += p - ult0;
			add += p - ult0;
		}
		cout << add << " \n"[i==n-1];

		//cout << "i = " << i << ", p: " << p << ", ult0: " << ult0 << endl;
		//cout << endl;
	}
	cout << res << endl;

	auto good = [&n](vector<int> a) {
		vector<int> vis(n);
		for (int i : a) {
			for (int j = 0; j < i; j++) {
				if (!vis[j]) return 0;
			}
			vis[i] = 1;
		}
		return 1;
	};

	vector<int> R(n);
	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) {
			int ok = good(vector<int>(A.begin() + l, A.begin() + r + 1));

			if (ok) {
				R[r]++;
				res++;
				cout << "(" << l << ", " << r << ")\n";
				for (int j = l; j <= r; j++) {
					cout << A[j] + 1 << " \n"[j==r];
				}
				cout << endl;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << R[i] << " \n"[i==n-1];
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

