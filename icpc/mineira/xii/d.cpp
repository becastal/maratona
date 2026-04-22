#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {

	vector<int> cont(100, 0);
	for (int a = 1; a <= 6; a++) {
		for (int b = 1; b <= 6; b++) {
			for (int c = 1; c <= 6; c++) {
				cont[a + b + c]++;
			}
		}
	}

	int k; cin >> k;
	cout << fixed << setprecision(13)  << double(cont[k]) / double(6 * 6 * 6) << endl;

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

