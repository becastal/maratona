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

	string s;
	while (getline(cin, s)) {
		if (s.empty()) {
			cout << endl;
			continue;
		}

		vector<int> v(26, 0);
		for (char c : s) if (isalpha(c)) v[c-'a']++;
		vector<string> res;

		for (int l = 0, r; l < 26;) {
			if (!v[l]) {
				l++;
				continue;
			}

			r = l+1;
			while (r < 26 and v[r]) {
				r++;
			}

			string resi = "a:a";
			resi[0] = char('a'+l), resi[2] = char('a'+r-1); 
			res.push_back(resi);
			l = r;
		}

		for (int i = 0; i < (int)res.size(); i++) {
			cout << res[i] << (i == (int)res.size()-1 ? "\n" : ", ");
		}
	}
    
    return(0);
}
