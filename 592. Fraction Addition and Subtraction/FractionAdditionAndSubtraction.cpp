class Solution {
public:
    int gcf(int i, int j){
        int smaller = i<=j?abs(i):abs(j);
        int larger = i <=j?abs(j):abs(i);
        int ret = smaller;
        while(ret >1){
            if(larger % ret == 0 && smaller%ret==0 ) return ret;
            ret--;
        }
        return ret == 0 ? 1:ret;
    }
    int calLcm(int i, int j){
        return (i*j)/gcf(i,j);
    }
    string fractionAddition(string expression) {
        char sign = '+';
        int prevDeno = 0;
        int num = 0;
        int numN = 0;
        int lcm = 1;
        int den = 1;
        for(int i = 0; i < expression.size(); i++){
            if(expression[i] == '+' || expression[i] == '-'){
                sign = expression[i] ;
            }
            else if(expression[i] == '/'){
                numN = expression[i-1] - '0';
                if(numN == 0){
                    numN = 10;
                }
                den = expression[i+1] - '0';
                if(den == 1 && i+2 < expression.size() && expression[i+2] == '0' ){
                    den = 10;
                }
                prevDeno = lcm;
                lcm = calLcm(prevDeno,den);
                if(sign == '-' ){
                    num = (num*(lcm/prevDeno)) - (numN*(lcm/den));
                }else{
                    num = (num*(lcm/prevDeno)) + (numN*(lcm/den));
                }
                if(num == 0){
                    lcm = 1;
                }
            }
        }
        int common = gcf(num,lcm);
        num = num/common;
        lcm = lcm/common;
        if(num == 0){
            lcm = 1;
        }
        return to_string(num)+"/"+to_string(lcm);
    }
};