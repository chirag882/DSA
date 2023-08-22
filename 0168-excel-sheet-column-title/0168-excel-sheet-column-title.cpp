class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber){
            columnNumber--;
            int remainder = columnNumber % 26;
            char ch = 'A' + remainder;
            result += ch;
            columnNumber /= 26;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};