#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	int res = 0;
	for (int i = 0; i < n; i++) {
		int C[2] = {S[i] == '0', S[i] == '1'};
		for (int j = i+1; j < n; j++) {
			C[S[j] - '0']++;

			int cont = (j - i + 1) / 2;
			int preciso = 2 * ((cont + 1) / 2) + 1 * (cont / 2);

			//cout << "(" << i << ", " << j << ")\n";
			if (!(cont / 2) or C[1] < cont / 2) {
				cout << "(" << i + 1 << ", " << j + 1 << ")\n";
				cout << "tam: " << j - i + 1 << endl;
				cout << "cont: " << cont << endl;
				cout << "preciso: " << preciso << endl;
				res++;
			}
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

