// Kids With the Greatest Number of Candies

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int max = candies[0];
    
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] > max) {
            max = candies[i];
        }
    }
    
    bool* result = (bool*)malloc(sizeof(bool) * candiesSize);
    
    for (int i = 0; i < candiesSize; i++) {
        result[i] = (candies[i] + extraCandies >= max);
    }
    
    *returnSize = candiesSize;
    return result;
}
