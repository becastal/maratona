#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	set<int> S;
	vector<int> R(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		S.insert(i);
	}

	int p = 0;
	for (int i = 0, agr = (1 << n) - 1; i < n; i++, agr >>= 1) {
		S.erase(R[p++] = agr);

		int tam = i - 1;
		//cout << agr << ": " << tam << endl;
		if (tam > 0) for (int k = 1; k < (1 << tam); k++) {
			int agr_ = (k << (__builtin_popcount(agr) + 1)) | agr;	
			//cout << agr << ": " << bitset<8>(agr_).to_string() << endl;
			if (!S.count(agr_)) continue;
			S.erase(R[p++] = agr_);
			S.erase(agr_);
		}
	}

	for (; p < (1 << n); p++){ 
		S.erase(R[p] = *S.begin());
	}

	for (int i = 0; i < (1 << n); i++) { 
		cout << R[i] << " \n"[i==(1<<n)-1];
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
