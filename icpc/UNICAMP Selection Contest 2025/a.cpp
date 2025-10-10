#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	vector<int> A(4);
	for (int& i : A) cin >> i;
	int n; cin >> n;

	int tot = accumulate(all(A), 0) + n;

	vector<string> res, S = {
		"Rafael",
		"Leonardo",
		"Donatello",
		"Michelangelo"
	};

	for (int i = 0; i < 4; i++) {
		if (A[i] + n > tot / 2) {
			res.push_back(S[i]);	
		}
	}

	if (res.empty()) return cout << "sem vencedores" << endl, 0;
	sort(all(res));
	for (auto& i : res) cout << i << endl;

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

