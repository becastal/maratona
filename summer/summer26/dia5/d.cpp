#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve(string in, vector<array<string, 2>>& T) {
//	cout << "in: " << in << endl;
//	for (auto [a, b] : T) {
//		cout << a << " -> " << b << endl;
//	}
	int ruim = 0;
	unordered_set<string> S;

	function<void(string&)> dfs = [&](string& u) {
		S.insert(u);
		if (S.size() > 1000) {
			ruim = 1;
			return;
		}

		for (auto& [a, b] : T) {
			int p = u.find(a);
			while (p != std::string::npos) {
				string v = u.substr(0, p) + b + u.substr(p + (int)a.size());
				if (!S.count(v)) {
					dfs(v);
				}
				if (ruim) return;
				p = u.find(a, p + 1);
			}
		}
	};
	dfs(in);
	
	if (ruim) return cout << "Too many." << endl, 0;	
	cout << (int)S.size() << endl;

	return(0);
}

void limpa(string& s) {
	s = s.substr(1);
	s.pop_back();
}

signed main()
{
    _;

	int Te; cin >> Te;
	string in; cin >> in; limpa(in);
	for (int t = 0; t < Te; t++) {
		if (t) cout << endl;
		string s;

		vector<array<string, 2>> T;
		while (cin >> s and s.find("->") != std::string::npos) {
			int p = s.find("->");
			string l = s.substr(0, p), r = s.substr(p + 2);
			limpa(l), limpa(r);
			T.push_back({l, r});
		}

		solve(in, T);
		in = s;
		limpa(in);
	}
    
    return(0);
}

