class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // check if either rectangle is actually a line
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
            rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            // the line cannot have positive overlap
            return false;
        }
        if(rec2[1]-rec1[3]>=0 || rec2[0] - rec1[2] >=0 || rec2[2]- rec1[0] <= 0 || rec2[3]-rec1[1] <=0){
            return false;
        }
        return true;
    }
};