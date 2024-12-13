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
	getline(cin, s);
	int t = stoi(s);

	while (t--) {
		getline(cin, s);
		stringstream ss(s);

		vector<int> v;
		int x, tot = 0, n = 1;
		while (ss >> x) {
			v.push_back(x);
			tot += x;
			n++;
		}

		if (tot & 1) {
			cout << "NO" << endl;			
			continue;
		}
		tot /= 2;

		vector<int> dp(tot+1, 0);
		dp[0] = 1;

		for (int k : v) {
			for (int j = tot; j >= k; j--) {
				dp[j] |= dp[j - k];
			}
		}

		cout << (dp[tot] ? "YES" : "NO") << endl;
	}
    
    return(0);
}
