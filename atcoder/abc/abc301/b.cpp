#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n);

	for (int& i : A) cin >> i;
	vector<int> R = {A[0]};
	for (int i = 1; i < n; i++) {
		int d = (A[i-1] > A[i] ? -1 : +1);
		for (int j = A[i-1] + d; abs(j - A[i]) >= 1; j += d) {
			R.push_back(j);	
		}
		R.push_back(A[i]);
	}

	for (int i = 0; i < (int)R.size(); i++) {
		cout << R[i] << " \n"[i==(int)R.size()-1];
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

