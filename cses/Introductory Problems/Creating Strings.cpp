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

int main()
{
    _;

	string s; cin >> s;
	sort(s.begin(), s.end());

	vector<string> res;
	set<pair<string, string>> memo;
	auto f = [&](auto f, string agr, string falta) -> void {
		if (memo.count({agr, falta})) return;
		if (falta.empty()) {
			res.push_back(agr);	
			return;
		}
		
		for (int i = 0; i < (int)falta.size(); i++) {
			string agri = agr, faltai = falta;
			agri.push_back(falta[i]);
			faltai.erase(faltai.begin() + i);
			f(f, agri, faltai);
		}
		memo.insert({agr, falta});
	};

	f(f, "", s);

	cout << (int)res.size() << endl;
	for (auto si : res) cout << si << endl;
    
    return(0);
}
