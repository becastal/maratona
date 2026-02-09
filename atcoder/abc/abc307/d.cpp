#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, agr = 0; cin >> n;
	string S, R = ""; cin >> S;

	for (char c : S) {
		if (c == ')' and agr > 0) {
			while (R.back() != '(') R.pop_back();
			R.pop_back();
			agr--;
		} else {
			R.push_back(c);
			agr += (c == '(');
		}
	}
	cout << R << endl;

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

