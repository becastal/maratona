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

int main() {
    _;

    int n, S = 0;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i, S += i;

    if (S & 1) return cout << -1 << endl, 0;

    int s = S/2;
    vector<int> dp(s + 1, 0), pai(s + 1, -1);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = s; j >= v[i]; j--) {
            if (dp[j - v[i]] and !dp[j]) {
                dp[j] = 1;
                pai[j] = i;
            }
        }
    }

    if (!dp[s]) return cout << -1 << endl, 0;

    vector<int> A, B, usei(n, 0);

    int sum = s;
    while (sum > 0 and pai[sum] != -1) {
        int idx = pai[sum];
        A.push_back(v[idx]);
        usei[idx] = true;
        sum -= v[idx];
    }

    for (int i = 0; i < n; i++) {
        if (!usei[i]) {
            B.push_back(v[i]);
        }
    }

	int a = 0, b = 0;
    int sa = 0, sb = 0;
	for (int i = 0; i < n; i++) {
        if (sa <= sb and a < A.size()) {
            cout << A[a] << ' ';
            sa += A[a++];
        } else if (b < B.size()) {
            cout << B[b] << ' ';
            sb += B[b++];
        }
    }
    cout << endl;

	//cout << "A: "; for (int i : A) cout << i << ' '; cout << endl;
	//cout << "B: "; for (int i : B) cout << i << ' '; cout << endl;

    return 0;
}

