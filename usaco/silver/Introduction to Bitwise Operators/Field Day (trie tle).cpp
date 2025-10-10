#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct trie {
	vector<vector<int>> to;
	vector<int> end, pref;
	int sigma, c; char norm;
	trie(int sigma_=26, char norm_='a', int c_ = 30) : sigma(sigma_), norm(norm_), c(c_) {
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
	int query(string s) {
		int res = 0;

		function<void(int, int, int)> dfs = [&](int u, int pos, int cont) {
			if (pos == c) {
				res = max(res, cont);
				return;
			}

			if (cont + (c - pos) <= res) return;
			
			int bit = s[pos] - '0';
			if (to[u][bit^1]) dfs(to[u][bit^1], pos+1, cont+1);
			if (to[u][bit]) dfs(to[u][bit], pos+1, cont);
		};
		
		dfs(0, 0, 0);
		return res;
	}
};

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");

	int c, n; cin >> c >> n;
	vector<string> v(n);

	trie t(2, '0', c);
	for (auto& i : v) {
		cin >> i;
		for (char& c : i) c = (c == 'G' ? '1' : '0');
		t.insert(i);
	}

	for (int i = 0; i < n; i++) {
		cout << t.query(v[i]) << endl;
	}

    return(0);
}
