#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve(string& S) {
	int n = (int)S.size();

	auto period = [&](int l, int r) {
		int nn = (r - l + 1);
		string s = S.substr(l, nn);
		

		vector<int> p(nn);
		for (int i = 1, j = 0; i < nn; i++)  {
			while (j and s[i] != s[j]) j = p[j-1];
			if (s[i] == s[j]) j++;
			p[i] = j;
		}

		int tam = nn - p.back();
		if (tam < nn and nn % tam == 0) return tam;
		return nn;
	};

	vector<vector<int>> C(n + 1, vector<int>(n + 1, -1));
	function<int(int, int)> calc = [&](int l, int r) {
		int& res = C[l][r];

		if (res != -1) return res;
		if (l == r) return res = 1;

		res = (r - l + 1);
		for (int m = l; m < r; m++) {
			res = min(res, calc(l, m) + calc(m + 1, r));
		}

		int p = period(l, r);
		if (p < (r - l + 1)) {
			res = min(res, calc(l, l + p - 1));
		}

		return res;
	};
	cout << calc(0, n-1) << endl;
	// C[i][j]: custo pra transformar a substring de [i, ..., j] em uma string do tipo do enunciado

	return(0);
}

signed main()
{
    _;

	string s;	
	//int t = 1; //cin >> t;
	while (cin >> s and s != "*") {
		solve(s);
	}
    
    return(0);
}

