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

vector<int> pi(string s) {
    int n = (int)s.size();
    vector<int> p(n, 0);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

int main() {
    _;

	int n; cin >> n;

    string s, t; cin >> s >> t;

    cout << (int)s.size() + (int)t.size() - pi(t + "#" + s).back() << endl;

    return (0);
}

