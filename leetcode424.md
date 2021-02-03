```c++
class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26]={0};//记录出现次数
        int i=0,j=0;//双指针
        int len = s.length();
        if(len<2) return len;
        int ans = 0;
        int maxcount = 0;
        while(j<len){
            cnt[s[j]-'A']++;
            maxcount=max(maxcount,cnt[s[j]-'A']);
            j++;
            if(j-i>maxcount+k){//左右差距大于最大频数+可修改数量
                cnt[s[i]-'A']--;//减去最左侧的计数
                i++;//左指针+1
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};
题目描述：给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。  
示例：  
输入：s = "ABAB", k = 2  
输出：4  
从暴力到优化：  
直接思路就是从第一个字符开始遍历，尝试全部更换成相同字符。  
优化：设定限制条件，并采取双指针。同时维护一个当前最大频数，若长度超过最大频数+可替换字符长度，则必然无法满足。此时左指针右移，重复上一步动作。
