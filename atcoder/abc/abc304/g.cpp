#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	bb na resposta

	daria pra gerar um grafo que tem (i, j) sse
	A[i] ^ A[j] >= mid, mas seria n**2 arestas

	usar trie pra saber quantos.
*/

struct trie {
	vector<vector<int>> to;
	vector<int> end, pref;
	int sigma; char norm;
	trie(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
		to = {vector<int>(sigma)};
		end = {0}, pref = {0};
	}
	void insert(string s) {
		int x = 0;
		for (auto c : s) {
			int &nxt = to[x][c-norm];
			if (!nxt) {
				nxt = to.size();
				to.push_back(vector<int>(sigma));
				end.push_back(0), pref.push_back(0);
			}
			x = nxt, pref[x]++;
		}
		end[x]++, pref[0]++;
	}
	void erase(string s) {
		int x = 0;
		for (char c : s) {
			int &nxt = to[x][c-norm];
			x = nxt, pref[x]--;
			if (!pref[x]) nxt = 0;
		}
		end[x]--, pref[0]--;
	}
	int find(string s) {
		int x = 0;
		for (auto c : s) {
			x = to[x][c-norm];
			if (!x) return -1;
		}
		return x;
	}
	int count_pref(string s) {
		int id = find(s);
		return id >= 0 ? pref[id] : 0;
	}
};

int solve() {
	int n; cin >> n;

	trie T(2, '0');
	vector<int> A(2 * n);
	for (int& i : A) {
		cin >> i;
		string s = bitset<30>(i).to_string();
		T.insert(s);
	}

	auto da = [&](int m) {
		function<int(int, int, int)> dfs2 = [&](int d, int u, int v) {
			if (!u or !v) return 0;
			if (d == -1) return min(T.pref[u], T.pref[v]);
		};

		int u0 = T.to[u][0], u1 = T.to[u][1];
		int v0 = T.to[v][0], v1 = T.to[v][1];

		if (m & (1 << d)) {
			return dfs2(d - 1, u0, v1) + dfs2(d - 1, u1, v0);
		} else {
		}
	};

	int l = 0, r = *max_element(all(A)), res = 0;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (!da(m)) { 
			r = m - 1;
		} else {
			res = m;
			l = m + 1;
		}
	}
	cout << res << endl;

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

