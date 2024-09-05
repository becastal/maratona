#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define f first
#define s second

#define vi vector<int>
#define grafo vector<vector<int>>

#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string longestPalinSubstring(string &s) {
    int n = s.size();
    if (n == 0) return "";
    
    int start = 0, maxLength = 1;

    // Function to expand around the center and find the longest palindrome
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        int length = right - left - 1;
        if (length > maxLength) {
            start = left + 1;
            maxLength = length;
        }
    };

    for (int i = 0; i < n; i++) {
        // Odd length palindrome (single center)
        expandAroundCenter(i, i);
        // Even length palindrome (two centers)
        expandAroundCenter(i, i + 1);
    }

    return s.substr(start, maxLength);
}

int main(){ _
	string s = "abbbba";
	string s2 = "abccbapp";

	cout << longestPalinSubstring(s) << endl;
	cout << longestPalinSubstring(s2) << endl;
	return 0;
}
