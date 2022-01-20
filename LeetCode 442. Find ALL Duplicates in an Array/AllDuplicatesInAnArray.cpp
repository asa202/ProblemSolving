class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> ret;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[abs(nums[i])-1] < 0)ret.push_back(abs(nums[i]));
            nums[abs(nums[i])-1] *=-1;
        }
        return ret;
    }
};