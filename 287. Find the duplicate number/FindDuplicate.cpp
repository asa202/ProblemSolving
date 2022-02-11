class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cin.tie(0);
        int slow = 0; int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast!=slow);
        
        int slow2 = 0;
        while(slow!=slow2){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};