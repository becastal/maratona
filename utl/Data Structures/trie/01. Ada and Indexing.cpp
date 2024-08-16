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

struct TRIE {
	vector<vector<int>> to;
	vector<int> end, pref;
	int sigma; char norm;
	TRIE(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
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

int main()
{
    _;

	int n, q; cin >> n >> q;
	TRIE trie;

	while (n--) {
		string si; cin >> si;		
		trie.insert(si);
	}

	while (q--) {
		string si; cin >> si;		
		cout << trie.count_pref(si) << endl;
	}
    
    return(0);
}
