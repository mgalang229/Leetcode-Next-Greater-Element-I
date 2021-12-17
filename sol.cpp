class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int n = nums2.size();
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            res[i] = (!s.empty() ? s.top() : -1);
            s.push(nums2[i]);
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = res[i];
        }
        int m = nums1.size();
        vector<int> ans(m, 0);
        for (int i = 0; i < m; i++) {
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};
