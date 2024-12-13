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
    
    vector<int> nums;
    int a1; cin >> a1;
    nums.push_back(a1);
    for (int i = 0; i < 2; i++)
    {
        int n; cin >> n;
        int tam = nums.size();

        nums.push_back(n), nums.push_back(-n);
        for (int i = 0; i < tam; i++)
            nums.push_back(nums[i] + n), nums.push_back(nums[i] - n);
    }

    cout << (find(nums.begin(), nums.end(), 0) != nums.end() ? "S" : "N") << endl;

    return(0);
}
