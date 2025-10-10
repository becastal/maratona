#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	string S; cin >> S;
	
	vector<int> cont(26, 0);
	for (char c : S) {
		cont[c-'A']++;	
	}

	string T = "";
	while (cont['T' - 'A']) T.push_back('T'), cont['T' - 'A']--;
	while (cont['F' - 'A']) T.push_back('F'), cont['F' - 'A']--;
	for (int i = 0; i < 26; i++) {
		while (cont[i]) T.push_back(char('A' + i)), cont[i]--;
	}

	assert(T.find("FFT") == string::npos and T.find("NTT") == string::npos);
	cout << T << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
