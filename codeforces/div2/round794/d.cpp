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

void solve() {
	int a, b, ab, ba; 
	cin >> a >> b >> ab >> ba;

	string s; cin >> s;
	int n = (int)s.size();

	vector<int> cont(2, 0);
	for (char c : s) cont[c - 'A']++;
	
	int ok = 1;
	ok &= cont[0] == a + ab + ba;
	ok &= cont[1] == b + ab + ba;

	vector<int> p_ab, p_ba;

	// tenho que escolher ab's em p_ab tal que sobrem exatos ba's em p_ba e que nao se batam p_ab[i] != p_ba[i]-1
	for (int i = 0; i < n-1 and ok; i++) {
		if (s[i] == 'A' and s[i+1] == 'B') p_ab.push_back(i);
		if (s[i] == 'B' and s[i+1] == 'A') p_ba.push_back(i);
	}

	int q_ab = 0, q_ba = 0, ambos = 0;
	for (int i : p_ab) {
		q_ab += !(p_ba[lower_bound(p_ba.begin(), p_ba.end(), i+1) - p_ba.begin()] == i+1) and 
				!(p_ba[lower_bound(p_ba.begin(), p_ba.end(), i-1) - p_ba.begin()] == i-1);
	}
	for (int i : p_ba) {
		q_ba += !(p_ab[lower_bound(p_ab.begin(), p_ab.end(), i+1) - p_ab.begin()] == i+1) and 
				!(p_ab[lower_bound(p_ab.begin(), p_ab.end(), i-1) - p_ab.begin()] == i-1);
	}

	ambos = (int)p_ab.size() + (int)p_ba.size() - (q_ab + q_ba);

	dbg(q_ab);
	dbg(q_ba);
	dbg(ambos);

	for (int i : p_ab) cout << i << ' '; cout << endl;
	for (int i : p_ba) cout << i << ' '; cout << endl;
	
	cout << (ok ? "YES" : "NO") << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
