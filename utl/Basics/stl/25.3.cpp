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

	function<bool(string)> solve = [&] (string s) {
		stack<char> st;	

		for (auto ca : s)
		{
			if (ca == '(' or ca == '{' or ca == '[')
				st.push(ca);
			else if (ca == ')')
			{
				if (st.size() > 0 and st.top() == '(') 
					st.pop();
				else
					return false;
			}
			else if (ca == ']')
			{
				if (st.size() > 0 and st.top() == '[') 
					st.pop();
				else
					return false;
			}
			else if (ca == '}')
			{
				if (st.size() > 0 and st.top() == '{') 
					st.pop();
				else
					return false;
			}
		}
		return st.size() == 0;
	};

	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		cout << (solve(s) ? "YES" : "NO") << endl;
	}
    
    return(0);
}
