class Solution {
public:
    int addDigits(int num) {
        if (num != 0){
            if ( num % 9 == 0){
                return 9;
            }
            int a = num % 9;
            return a;
        }
    return 0;
    }
};