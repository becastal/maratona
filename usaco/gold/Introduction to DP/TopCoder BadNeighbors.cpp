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
	int xi; 
	vector<int> v;
	while (cin >> xi) {
		v.push_back(xi);	
		char c; cin >> c;
	}
	int n = (int)v.size();

	vector<int> dp1(n, 0), dp2(n, 0);
	dp1[0] = v[0];
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < i - 1; j++) {
			dp1[i] = max(dp1[i], v[i] + dp1[j]);
		}
		if (i) dp1[i] = max(dp1[i], dp1[i-1]);
	}

	dp2[1] = v[1];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i - 1; j++) {
			dp2[i] = max(dp2[i], v[i] + dp2[j]);
		}
		if (i) dp2[i] = max(dp2[i], dp2[i-1]);
	}

	//for (int i : dp1) cout << i << ' '; cout << endl;
	//for (int i : dp2) cout << i << ' '; cout << endl;
	cout << max(*max_element(dp1.begin(), dp1.end()), *max_element(dp2.begin(), dp2.end())) << endl;

    return(0);
}
