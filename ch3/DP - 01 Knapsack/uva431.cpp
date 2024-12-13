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
    string s; getline(cin, s);
    int W = stoi(s);

    vector<int> w, v;
    vector<string> desc;

    while (getline(cin, s) and !s.empty()) {
        stringstream ss(s);
        int vi; ss >> vi; v.push_back(vi);
        int wi; ss >> wi; w.push_back(wi);
        string si; getline(ss, si); desc.push_back(si);
    }
    int n = w.size();

    vector<int> dp(W + 1, 0);
	vector<vector<int>> jafoi(W+1, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = W; j >= w[i]; j--) {
			if (dp[j - w[i]] + v[i] > dp[j]) {
				dp[j] = dp[j - w[i]] + v[i];
				jafoi[j] = jafoi[j-w[i]];
				jafoi[j][i] = 1;
			}
		}
	}

	if (!dp[W]) {
		cout << "There is not enough time to present any evidence. Drop the charges." << endl; 
		return;
	}

	vector<tuple<int, int, string>> res;
	int sobra = W;
	for (int i = 0; i < n; i++) {
		if (jafoi[sobra][i]) {
			res.emplace_back(v[i], w[i], desc[i]);
			sobra -= w[i];
		}
	}

    sort(res.begin(), res.end(), [&](tuple<int, int, string> a, tuple<int, int, string> b) {
		int va, wa, vb, wb; 
		string sa, sb;
		tie(va, wa, sa) = a;
		tie(vb, wb, sb) = b;

        if (wa == wb) {
            if (va == vb) return sa < sb;
            return va > vb;
        }
        return wa < wb;
    });

	cout << "Score Time Description" << endl;
	cout << "----- ---- -----------" << endl;

	for (int i = 0; i < (int)res.size(); i++) {
		int vi, wi; 
		string si;
		tie(vi, wi, si) = res[i];
        cout << setw(3) << vi << "   " << setw(3) << wi << " " << si << endl;
	}
	cout << endl << "Total score: " << dp[W] << " points" << endl;
	cout << " Total time: " << W << " hours" << endl;
}

int main()
{
    _;

    string s; getline(cin, s);
    int t = stoi(s);
    while (t--) {
        solve();
    }

    return 0;
}

