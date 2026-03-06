class Solution {
public:
    bool checkOnesSegment(string s) {
        int pos = s.find("01");
        return pos == -1;
    }
};