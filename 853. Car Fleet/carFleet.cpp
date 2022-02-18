class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> indexes(position.size());
        iota(indexes.begin(),indexes.end(), 0);
        sort(indexes.begin(), indexes.end(),[&position](int a , int b){
            return position[a] < position[b];
        });
        int noOfCarFleets = 0;
        double maxTimeToFinish = 0.0;
        for(int i = indexes.size()-1; i>=0; i--){
            double timeTakenByCurrentFleet = 1.0*(target-position[indexes[i]])/speed[indexes[i]];
            if(maxTimeToFinish < timeTakenByCurrentFleet){
                noOfCarFleets++;
                maxTimeToFinish = timeTakenByCurrentFleet;
            }
        }
       return noOfCarFleets;
    }
};