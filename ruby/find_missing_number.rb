def missing_number(nums)
  i = 0
  nums << -1
  missing_number = nums.length - 1
  while i < nums.length
    if nums[i] != i && nums[i] != -1
      nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
      missing_number = i if nums[i] == -1
    else
      i += 1
    end
  end
  missing_number
end
