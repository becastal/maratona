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

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

template<typename T> vector<int> matching(T& s, T& t) {
	vector<int> p = pi(s), match;
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) match.push_back(i-j+1), j = p[j-1];
	}
	return match;
}

int main()
{
    _;

	string s; cin >> s;
	int n = (int)s.size();

	string t = s + s;

	int i = 0, j = 1, k = 0;
	while (i < n and j < n and k < n) {
		if (t[i+k] == t[j+k]) {
			k++;
			continue;
		}

		if (t[i+k] < t[j+k]) {
			i += k + 1;
			if (i <= j) i = j + 1;
		} else {
			j += k + 1;
			if (j <= i) j = i + 1;
		}
		k = 0;
	}
	int pos = min(i, j);
	string melhor = s.substr(pos) + s.substr(0, pos);

	int res = 0;
	auto ocorr = matching(melhor, t);
	for (int i : ocorr) {
		res += i < n;
	}

	cout << res << ' ' << pos+1 << endl;
    
    return(0);
}
