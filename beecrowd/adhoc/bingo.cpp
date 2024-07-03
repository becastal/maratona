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
	int n, b; 
	while (cin >> n >> b and n and b)
	{
		vector<int> nums(b), ocorr(n + 1, 0);
		int c = n + 1;
		for (int i = 0; i < b; i++)
		{
			cin >> nums[i];
			ocorr[nums[i]] = 1;
			c--;
		}

		for (int i = 0; i < b; i++)
			for (int j = i + 1; j < b; j++)
			{
				int ni = abs(nums[i] - nums[j]);
				if (!ocorr[ni])
				{
					ocorr[ni] = 1;
					c--;
				}
			}
		
		cout << (c ? 'N' : 'Y') << endl;
	}
    
    return(0);
}

