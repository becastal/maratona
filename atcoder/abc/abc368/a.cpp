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

	int n, k; cin >> n >> k;
	vector<int> v(n); 
	for (int& i : v) cin >> i;
	vector<int> res;
	for (int i = 0; i < k; i++) {
		res.push_back(v.back());
		v.pop_back();
	}
	reverse(res.begin(), res.end());

	for (int i = 0; i < (int)v.size(); i++) {
		res.push_back(v[i]);
	}

	for (int i : res) cout << i << ' ';
	cout << endl;
    
    return(0);
}
