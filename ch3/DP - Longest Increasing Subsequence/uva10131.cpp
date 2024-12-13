#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
using namespace std;

int main()
{
    _;

	vector<array<int, 3>> v;

    int wi, si, n = 1;
    while (cin >> wi >> si) {
        v.push_back({wi, si, n++});
    }

    sort(v.begin(), v.end(), [&](array<int, 3> a, array<int, 3> b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    vector<int> dp(n, 1), pai(n, -1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j][0] < v[i][0] and v[j][1] > v[i][1] and dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
				pai[i] = j;
            }
        }
    }

	int agr = max_element(dp.begin(), dp.end()) - dp.begin();
	vector<int> res;
	for (int i = agr; i != -1; ) {
		res.push_back(v[i][2]);
		i = pai[i];
	}
	reverse(res.begin(), res.end());

	cout << res.size() << endl;
	for (int i : res) cout << i << endl;

    return 0;
}

