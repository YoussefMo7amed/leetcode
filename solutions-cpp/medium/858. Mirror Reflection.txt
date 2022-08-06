// You can see the Explanation from this video:
// https://youtu.be/_xIBOUWEq1c

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int ex = q, ref = p;
        while(ex%2 == 0 && ref%2 ==0){
            ex/=2;
            ref/=2;
        }
        if(ex&1){
            if(ref&1){
                return 1;
            } else {
                return 2;
            }
        }else {
            return 0;
        }
    }
};

