def sort_colors(nums)
   low, mid, high = 0, 0, nums.length-1
   while mid <= high
    nums[mid] == 0 ? (nums[low], nums[mid] = nums[mid], nums[low];mid += 1;low += 1;) : nums[mid] == 2 ? (nums[mid], nums[high] = nums[high], nums[mid];high -= 1;) : mid += 1
   end
end
