#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<string> A(n);
	vector<int> B(n);
	
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	for (int i = 0, p = min_element(all(B)) - B.begin(); i < n; i++, p = (p + 1) % n) {
		cout << A[p] << endl;
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

