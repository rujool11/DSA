// Leetcode 860. Lemonade change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;

        for (int x: bills) {
           switch (x) {
                case 5: fives++; break;
                case 10: if (fives) {fives--;} else return false; tens++; break;
                case 20: if (fives && tens) {fives--; tens--;} else {if (fives>=3) fives -=3; else return false;}
           }
        }

        return true;
    }
};