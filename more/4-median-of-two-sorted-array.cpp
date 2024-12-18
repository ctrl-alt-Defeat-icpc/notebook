class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        int size = n + m;
        int left = (size + 1) / 2;
        int low = 0, high = n;
        int l1, l2, r1, r2, mid1, mid2;
        while(low <= high) {
            mid1 = (low + high) >> 1;
            mid2 = left - mid1;
            r1 = mid1 < n ? nums1[mid1] : 1e9;
            r2 = mid2 < m ? nums2[mid2] : 1e9;
            l1 = mid1 - 1 >= 0 ? nums1[mid1 - 1] : -1e9;
            l2 = mid2 - 1 >= 0 ? nums2[mid2 - 1] : -1e9;
            if(l1 <= r2 && l2 <= r1)
                if(size % 2) return max(l1, l2);
                else return (static_cast<double>(max(l1, l2) + min(r1, r2))) / 2.0;
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }

        return 0;
    }
};