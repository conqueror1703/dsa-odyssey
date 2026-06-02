class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int l= landStartTime.size();
        int w=waterStartTime.size();
          int ans = INT_MAX;

        for (int i = 0; i < l; i++) {

            int land = landStartTime[i] + landDuration[i];

            for (int j = 0; j < w; j++) {

                int water = waterStartTime[j] + waterDuration[j];

                // Land -> Water
                if (land >= waterStartTime[j]) {
                    ans = min(ans, land + waterDuration[j]);
                } else {
                    ans = min(ans,
                              land +
                              (waterStartTime[j] - land) +
                              waterDuration[j]);
                }

         
                if (water > landStartTime[i]) {
                    ans = min(ans, water + landDuration[i]);
                } else {
                    ans = min(ans,
                              water +
                              (landStartTime[i] - water) +
                              landDuration[i]);
                }
            }
        }

        return ans;
    }
};
        
    