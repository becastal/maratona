#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	string S, T; cin >> S >> T;

	vector<int> CS(27, 0), CT(27, 0);
	for (char& c : S) {
		c = (c == '@' ? 'z' + 1 : c);
		CS[c - 'a']++;	
	}
	for (char& c : T) {
		c = (c == '@' ? 'z' + 1 : c);
		CT[c - 'a']++;	
	}

	set<char> Se = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

	for (char c : Se) {
		c -= 'a';
		CS[c] -= CT[c];
		if (CS[c] < 0) {
			int mn = min(CS[26], -CS[c]);
			if (CS[26] < -CS[c]) return cout << "No" << endl, 0;
			CS[c] += mn;
			CS[26] -= mn;
		} else if (CS[c] > 0) {
			int mn = min(CT[26], CS[c]);
			if (CT[26] < CS[c]) return cout << "No" << endl, 0;
			CS[c] -= mn;
			CT[26] -= mn;
		}
	}

	for (int i = 0; i < 26; i++) if (!Se.count('a' + i)) {
		if (CS[i] != CT[i]) return cout << "No" << endl, 0;
	}
	cout << "Yes" << endl;

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

