#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n), R(n);
	for (int& i : A) cin >> i;

	stack<int> S;

	for (int i = 0; i < n; i++) {
		while (S.size() and A[S.top()] <= A[i]) {
			S.pop();
		}
		R[i] = (S.size() ? S.top() + 1 : -1);
		S.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << R[i] << " \n"[i==n-1];
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

