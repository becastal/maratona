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

	vector<tuple<string, int, int>> v;
	vector<string> res;
	int cont = 0;

	int q; cin >> q;
	while (q--) {
		string s; cin >> s;

		if (s == "CHEGA") {
			string si; cin >> si;
			int f; cin >> f;
			v.emplace_back(si, f, cont++);
		} else if (s == "FOME") {
			string si; cin >> si;
			int f; cin >> f;

			for (auto& [a, b, c] : v) {
				if (a != si) continue;
				b += f;
				break;
			}
		} else if (s == "SAI") {
			string si; cin >> si;
			int ii;
			for (int i = 0; i < (int)v.size(); i++) {
				if (si == get<0>(v[i])) {
					ii = i;
					break;
				}	
			}
			v.erase(v.begin() + ii);
		} else if (s == "SERVE") {
	            if (v.empty()) continue;

            int ii = -1, fmax = -INF, fordem = INF;
            for (int i = 0; i < (int)v.size(); i++) {
                auto [a, b, c] = v[i];
                if (b > fmax) {
                    fmax = b;
                    fordem = c;
                    ii = i;
                } else if (b == fmax and c < fordem) {
                    fordem = c;
                    ii = i;
                }
            }
            res.push_back(get<0>(v[ii]));
            v.erase(v.begin() + ii);
        }
	}

	for (auto i : res) {
		cout << i << endl;
	}
    
    return(0);
}
