class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> A(arr);
        
        vector<int> L(n), R(n);
        stack<int> S;
        for (int i = 0; i < n; i++) {
            while (S.size() and A[S.top()] > A[i]) S.pop();
            L[i] = (S.size() ? S.top() : -1);
            S.push(i);
        }
    
        while (S.size()) S.pop();
        for (int i = n-1; i >= 0; i--) {
            while (S.size() and A[S.top()] >= A[i]) S.pop();
            R[i] = (S.size() ? S.top() : n);
            S.push(i);
        }
    
        const int mod = 1e9+7;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + (1LL * (i - L[i]) * (R[i] - i) % mod * A[i] % mod) % mod) % mod;
        }
    
        return res;
    }
};
