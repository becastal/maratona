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

	int t; cin >> t; cin.ignore();
	while (t--) {
		string s; getline(cin, s);
		stringstream ss(s);
		
		vector<pair<string, int>> v;
		int cont = 0;
		string si;
		while (ss >> si) {
			v.emplace_back(si, cont++);
		}

		sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
			if (a.f.size() == b.f.size()) return a.s < b.s;
			return a.f.size() > b.f.size();
		});

		for (int i = 0; i < (int)v.size(); i++) {
			cout << v[i].f << " \n"[i==(int)v.size()-1];
		}
	}
    
    return(0);
}
