class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int shr = stoi(startTime.substr(0, 2));
        int ehr = stoi(endTime.substr(0, 2));

        int smin = stoi(startTime.substr(3, 2));
        int emin = stoi(endTime.substr(3, 2));

        int ssec = stoi(startTime.substr(6, 2));
        int esec = stoi(endTime.substr(6, 2));

        int start = shr * 3600 + smin * 60 + ssec;
        int end = ehr * 3600 + emin * 60 + esec;

        return end - start;
    }
};