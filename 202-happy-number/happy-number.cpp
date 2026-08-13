class Solution {
public:

    int ss(int n) {
        int sum = 0;

        while (n > 0) {
            int dig = n % 10;
            n = n / 10;
            sum += dig * dig;
        }

        return sum;
    }

    bool isHappy(int n) {

        int slow = ss(n);
        int fast = ss(ss(n));

        while (slow != fast) {
            slow = ss(slow);
            fast = ss(ss(fast));
        }

        return slow == 1;
    }
};