#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int _1e9 = 1e9+9;
const int MAX = 1010;
const int p = 696969;

int solve() {
	int n; cin >> n;
	set<int> S;

	vector<int> Base(MAX, 1);
	for (int i = 1; i < MAX; i++) {
		Base[i] = Base[i-1] * p % _1e9;
	}

	vector<int> Hash(n), Soma(n);
	vector<string> A(n);
	map<int, int> C;
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		Hash[i] = 0;
		for (char c : A[i]) {
			Hash[i] = (Hash[i] * p + c) % _1e9;
		}
		C[Hash[i]]++;
	}
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int Ak = Hash[i] * Hash[j] % _1e9;
			res += 2 * C[Ak];

			cout << "~~~~~~~~~~~~~~~" << endl;
			cout << A[i] << ": " << Hash[i] << endl;
			cout << A[j] << ": " << Hash[j] << endl;
			cout << Ak << endl;
		}
	}
	cout << res << endl;

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

