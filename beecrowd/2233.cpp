#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int hexa(string& A) {
	int base = 1, res = 0;
	reverse(all(A));
	for (char c : A) {
		if (isdigit(c)) {
			res += (c - '0') * base;	
		} else {
			res += (10 + (c - 'a')) * base;
		}
		base *= 16;
	}
	return res;
}

string hexa_(int a) {
	string res = "";
	while (a) {
		int r = a % 16;
		if (r < 10) {
			res.push_back(char('0' + r));
		} else {
			res.push_back(char('a' + r - 10));
		}
		a /= 16;
	}
	reverse(all(res));
	return res;
}

int solve() {
	string A, B, C; cin >> A >> B >> C;
	int a = hexa(A), b = hexa(B), c = hexa(C);


	int qb = a / b;
	int qc = b / c;

	int res = qb * qb + qc * qc + 1;
	cout << hexa_(res) << endl;

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

