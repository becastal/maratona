#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	string S, A = "", B = ""; cin >> S;

	for (int i = 0; i < 2*n; i++) {
		A.push_back((i & 1 ? 'A' : 'B'));
		B.push_back((i & 1 ? 'B' : 'A'));
	}

	auto calc = [&n](string S, string A) {
		set<int> Sa, Sb;
		for (int i = 0; i < 2*n; i++) {
			if (S[i] == 'A') {
				Sa.insert(i);
			} else {
				Sb.insert(i);
			}
		}

		ll res = 0;
		for (int i = 0; i < 2*n; i++) {
			if (S[i] != A[i]) {
				if (A[i] == 'A') {
					auto it = Sa.lower_bound(i);	
					int j = *it;
					res += j - i;

					S[i] = 'A', S[j] = 'B';
					Sa.erase(j), Sa.insert(i);
					Sb.erase(i), Sb.insert(j);
				} else {
					auto it = Sb.lower_bound(i);	
					int j = *it;
					res += j - i;

					S[i] = 'B', S[j] = 'A';
					Sb.erase(j), Sb.insert(i);
					Sa.erase(i), Sa.insert(j);
				}
			}
		}

		return res;
	};

	cout << min(calc(S, A), calc(S, B)) << endl;

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

