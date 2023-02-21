def sorted_squares(nums)
  left, right = 0, nums.length-1
  while left <= right
    if nums[left].abs() >= nums[right].abs()
      nums.insert(right+1, nums[left]**2)
      nums.shift()
      right -= 1
    else
      nums[right] = nums[right]**2
      right -= 1
    end
  end
  nums
end
