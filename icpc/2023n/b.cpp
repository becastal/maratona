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

	int n; cin >> n;
	vector<int> v(3*n);
	map<int, int> freq;
	for (int& i : v) cin >> i, freq[i]++;

	vector<int> cont(3, 0);
	for (auto& [a, b] : freq) {
		cont[b%3]++;
	}

	if (!cont[1] and !cont[2]) return cout << 'N' << endl, 0;
	cout << 'Y' << endl;
    
    return(0);
}
