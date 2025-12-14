// Contains Duplicate
bool containsDuplicate(int* nums, int numsSize) {
    int size = numsSize * 2 + 1;

    int* table = (int*)malloc(size * sizeof(int));
    char* used = (char*)calloc(size, sizeof(char));

    for (int i = 0; i < numsSize; i++) {
        int key = nums[i];
        int idx = ((key % size) + size) % size;

        while (used[idx]) {
            if (table[idx] == key) {
                free(table);
                free(used);
                return true;
            }
            idx = (idx + 1) % size;
        }

        table[idx] = key;
        used[idx] = 1;
    }

    free(table);
    free(used);
    return false;
}
