class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;

        if(nums.size() == 1 && k == 1) return nums;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        vector<pair<int,int>> temp;

        for(auto p : mp) {
            temp.push_back({p.second, p.first});
        }

        sort(temp.rbegin(), temp.rend());

        for(int i = 0; i < k; i++) {
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};