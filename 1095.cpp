/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 1, r = mountainArr.length() - 2;
        int peak = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int a = mountainArr.get(mid - 1), b = mountainArr.get(mid), c = mountainArr.get(mid + 1);
            if (a < b && b > c) {
                peak = mid;
                break;
            }
            if (a < b && b < c) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l = 0, r = peak;
        while (l <= r) {
            int mid = (l + r) / 2;
            int v = mountainArr.get(mid);
            if (v == target) {
                return mid;
            }
            if (v < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l = peak + 1, r = mountainArr.length() - 1; 
        while (l <= r) {
            int mid = (l + r) / 2;
            int v = mountainArr.get(mid);
            if (v == target) {
                return mid;
            }
            if (v < target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } 
        return -1;
    }
};