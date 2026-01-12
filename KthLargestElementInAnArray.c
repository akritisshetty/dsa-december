// Kth Largest Element in an Array

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int target = numsSize - k;
    int left = 0, right = numsSize - 1;

    srand(time(NULL));

    while (left <= right) {
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];

        int i = left, lt = left, gt = right;
        while (i <= gt) {
            if (nums[i] < pivot)
                swap(&nums[i++], &nums[lt++]);
            else if (nums[i] > pivot)
                swap(&nums[i], &nums[gt--]);
            else
                i++;
        }

        if (target < lt)
            right = lt - 1;
        else if (target > gt)
            left = gt + 1;
        else
            return pivot;
    }

    return -1;
}
