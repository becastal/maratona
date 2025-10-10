#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 1 << 21;
int F[MAX];

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	string B(S);
	sort(all(B));
	B.erase(unique(all(B)), B.end());
	int m = (int)B.size();

	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		A[i] = lower_bound(all(B), S[i]) - B.begin();
	}

	ll res = 0;
	memset(F, 0, sizeof(F)); F[0]++;
	for (int i = 0, a = 0; i < n; i++) {
		a ^= (1 << A[i]);

		for (int j = 0; j < m; j++) {
			int c = (1 << j);
			res += F[a ^ c];
		}
		res += F[a];
		F[a]++;
	}
	cout << res  << endl;

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

