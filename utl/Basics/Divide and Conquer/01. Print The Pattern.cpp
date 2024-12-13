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
	vector<string> v = {"A"};
	int j = 1;
	for (int i = 1; i < n; i++) {
		char b = 'A' + j++;
		v.push_back(v.back() + b + v.back());
	}
	cout << v.back();
    
    return(0);
}
