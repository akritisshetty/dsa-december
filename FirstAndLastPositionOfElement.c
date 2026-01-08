// Find First and Last Position of Element in Sorted Array

int findLeft(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, ans = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            ans = mid;
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int findRight(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, ans = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            ans = mid;
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    if (numsSize == 0) {
        result[0] = result[1] = -1;
        return result;
    }
    
    result[0] = findLeft(nums, numsSize, target);
    result[1] = findRight(nums, numsSize, target);
    
    return result;
}
