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
	int n = (int)s.size();
	vector<char> res(n);

	int imp = 0;
	vector<int> cont(26, 0);
	for (char c : s) cont[c-'A']++;
	for (int i : cont) imp += i & 1;
	
	if ((n & 1 and imp != 1) or (n & 1 ^ 1 and imp)) return cout << "NO SOLUTION" << endl, 0;

	for (int i = 0, l = 0, r = n-1; i < 26; i++) {
		if (cont[i] & 1) cont[i]--, res[n/2] = char('A'+i);
		if (!cont[i]) continue;

		for (int j = 0; j < cont[i]/2; j++) {
			res[l++] = res[r--] = char('A'+i);
		}
	}

	for (char c : res) cout << c; cout << endl;
    
    return(0);
}
