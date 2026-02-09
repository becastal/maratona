#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

/*
	maior string que eh subsequencia de A e B e que nao contem C
	precomputa next[c][i] pra A e B

	uma das dimensoes da dp tem que ser a prefix function do C

	nao tem ciclo com ctz
*/


template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

struct KMPaut : vector<vector<int>> {
	KMPaut(){}
	KMPaut (string& s) : vector<vector<int>>(26, vector<int>(s.size()+1)) {
		vector<int> p = pi(s);
		auto& aut = *this;
		aut[s[0]-'A'][0] = 1;
		for (char c = 0; c < 26; c++)
			for (int i = 1; i <= s.size(); i++)
				aut[c][i] = s[i]-'A' == c ? i+1 : aut[c][p[i-1]];
	}
};

int solve() {
	string A, B, C; cin >> A >> B >> C;
	int n = (int)A.size(), m = (int)B.size(), k = (int)C.size();

	vector<vector<int>> Pa(n+1, vector<int>(26, n)), 
						Pb(m+1, vector<int>(26, m));

	for (int i = n-1; i >= 0; i--) {
		Pa[i] = Pa[i+1];
		Pa[i][A[i] - 'A'] = i;
	}

	for (int i = m-1; i >= 0; i--) {
		Pb[i] = Pb[i+1];
		Pb[i][B[i] - 'A'] = i;
	}

	KMPaut aut(C);

	vector D(n+1, vector(m+1, vector<int>(k, -1))), Ch(D);
	vector P(n+1, vector(m+1, vector<array<int, 3>>(k, {-1, -1, -1})));
	D[0][0][0] = 0;

	int res = 0;
	array<int, 3> u = {0, 0, 0};

	for (int a = 0; a <= n; a++) {
		for (int b = 0; b <= m; b++) {
			for (int c = 0; c < k; c++) {
				if (D[a][b][c] == -1) continue;

				for (int i = 0; i < 26; i++) {
					int a_ = Pa[a][i] + 1, b_ = Pb[b][i] + 1, c_ = aut[i][c];
					if (a_ > n or b_ > m or c_ >= k) continue;

					if (D[a_][b_][c_] < D[a][b][c] + 1) {
						D[a_][b_][c_] = D[a][b][c] + 1;
						P[a_][b_][c_] = {a, b, c};
						Ch[a_][b_][c_] = i;

						if (res < D[a_][b_][c_]) {
							res = D[a_][b_][c_];
							u = {a_, b_, c_};
						}
					}
				}
			}
		}
	}

	if (!res) return cout << 0 << endl, 0;
	string R;
	for (; u[0] or u[1] or u[2]; u = P[u[0]][u[1]][u[2]]) {
		R.push_back(char('A' + Ch[u[0]][u[1]][u[2]]));
	}
	reverse(all(R));
	cout << R << endl;

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

