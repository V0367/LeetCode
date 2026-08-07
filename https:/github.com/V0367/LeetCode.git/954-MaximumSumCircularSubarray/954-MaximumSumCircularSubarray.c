// Last updated: 07/08/2026, 15:39:51
int maxSubarraySumCircular(int* nums, int numsSize) {
    int maxKadane = nums[0], minKadane = nums[0], total = nums[0];
    int currentMax = nums[0], currentMin = nums[0];

    // Calculate max subarray sum (Kadane's algorithm)
    for (int i = 1; i < numsSize; i++) {
        currentMax = fmax(nums[i], currentMax + nums[i]);
        maxKadane = fmax(maxKadane, currentMax);
        
        currentMin = fmin(nums[i], currentMin + nums[i]);
        minKadane = fmin(minKadane, currentMin);
        
        total += nums[i];
    }
    
    // If total sum is equal to the min subarray sum, that means all numbers are negative
    if (total == minKadane) {
        return maxKadane;
    }
    
    // Return the maximum of Kadane's result or the circular subarray sum
    return fmax(maxKadane, total - minKadane);
}
