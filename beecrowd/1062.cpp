#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve(int n) {

	while (1) {
		vector<int> A(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
			if (!i and !A[i]) return 0;
		}

		stack<int> S;
		int j = 0;
		for (int i = 0; i < n; i++) {
			S.push(i + 1);

			while (j < n and S.size() and S.top() == A[j]) {
				S.pop();
				j++;
			}
		}

		cout << (j == n and S.empty() ? "Yes" : "No") << endl;
	}


	return(0);
}

signed main()
{
    _;

	int n; //cin >> t;
	while (cin >> n and n) {
		solve(n);
		cout << endl;
	}
    
    return(0);
}

