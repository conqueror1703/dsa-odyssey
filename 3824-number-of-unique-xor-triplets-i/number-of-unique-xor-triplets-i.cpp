class Solution {
public:
long long xr(long long n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
       if (n <= 2) return n;

    int p = 1;
    while (p <= n) p <<= 1;

    return p;
    }
};