class Solution {
public:
    int gcd(int a, int b){
        int gcd = a;
        while(gcd!=1){
            if(b%gcd == 0 && a%gcd == 0 ) return gcd;
           gcd--; 
        }
        return gcd;
    }
    vector<string> simplifiedFractions(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<string> output{};
        for(int i = 1; i < n ; i++){
            for(int j = i+1; j <= n; j++){
                if(gcd(i,j)==1){
                    output.emplace_back(to_string(i)+"/"+to_string(j));
                }
            }
        }
        return output;
    }
};