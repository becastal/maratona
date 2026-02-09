#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	int neg = 0, agr = 0;
	for (char c : S) {
		agr += (c == '0' ? +1 : -1);
		if (agr < 0) neg = 1;
	}

	if (!neg and !agr) return cout << 0 << endl, 0;
	if (!neg and agr) return cout << 1 << endl, 0;
	cout << 2 << endl;

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

