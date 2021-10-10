/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
         int len = digits.size()-1;
        for(int i=len;i>=0;i--){
            //如果发生了进位
            if((digits[i]+1==10&&i == len)||digits[i]>=10){
                digits[i] = 0;
                if(i==0){
                    digits.insert(digits.begin(),1);
                }
                else{
                    digits[i-1]+=1;
                }
            }
            //如果第一位没有发生进位
            else{
                if(i == len){
                     digits[i]+=1;
                }
                break;
            }
        }
        return digits;

    }
};
// @lc code=end

