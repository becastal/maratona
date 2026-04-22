#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll


struct Trie {
	vector<vector<int>> to;
	vector<int> end, pref;
	int sigma; char norm;
	Trie(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
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
	vector<int> follow(string s) {
		vector<int> Res((int)s.size(), 0);
		int x = 0, p = 0;
		for (auto c : s) {
			x = to[x][c-norm];
			if (!x) break;
			Res[p++] = pref[x];
		}
		return Res;
	}
	int count_pref(string s) {
		int id = find(s);
		return id >= 0 ? pref[id] : 0;
	}
};

int solve() {
	int n; cin >> n;
	vector<string> A(n);
	for (auto& s : A) {
		cin >> s;
	}

	int res = 0;
	Trie T(26, 'a');

	for (int i = 0; i < n; i++) {
		string S = A[i];

		int add = 0;
		vector<int> B = T.follow(S);
		for (int j = (int)B.size() - 1, acum  = 0; j >= 0; j--) {
			B[j] -= acum;
			add += B[j] * (j + 1);
			acum += B[j];
		}

		res += add;
		T.insert(S);
	}
	cout << res << endl;

//	auto lcp = [&](string& a, string& b) {
//		int p = 0;
//		while (p < (int)a.size() and p < (int)b.size() and a[p] == b[p]) {
//			p++;
//		}
//		return p;
//	};
//	cout << "certo: " << endl;
//	for (int i = 0; i < n; i++){ 
//		int add = 0;
//		for (int j = 0; j < i; j++) { 
//			add += lcp(A[j], A[i]);	
//		}
//		cout << A[i] << ": " << add << endl;
//	}

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

