class Solution {
public:
    //O(S)Time
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int k = prefix.size();
        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            while(prefix[j] == strs[i][j] && j<k){
                j++;
            }
            if(j == 0){
                return "";
            }else{
                k = j;
            }
        }
        return prefix.substr(0,k);
    }
};