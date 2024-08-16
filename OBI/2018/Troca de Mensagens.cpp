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

bool vogal(char c) {
	return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main()
{
    _;

	vector<vector<char>> mp(26, vector<char>(26));
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			mp[i][j] = 'a' + (i + j) % 26;
		}
	}

	string k; cin >> k;
	int n; cin >> n;
	cin.ignore();
	while (n--) {
		string li; getline(cin, li);
		stringstream ss(li);
		int p = 0, l = 0;

		string ki;
		while (ss >> ki) {
			if (vogal(ki[0])) {
				cout << (p ? " " : "") << ki;
				p++;
				continue;
			}

			string res = ki;
			for (int i = 0; i < (int)ki.size(); i++) {
				if (ki[i] == ' ') continue;
				if (l == (int)k.size()) l = 0;
				res[i] = k[l++];
			}

			for (int i = 0; i < (int)ki.size(); i++) {
				if (ki[i] == ' ') continue;
				res[i] = mp[res[i] - 'a'][ki[i] - 'a'];		
			}

			cout << (p ? " " : "") << res;
			p++;
		}
		cout << endl;
	}
    
    return(0);
}
