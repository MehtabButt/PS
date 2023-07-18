# @param {Integer[]} nums
# @return {Integer}
def single_non_duplicate(nums)
  left, right = 0, nums.length-1

  while left <= right
    mid = (left+right)/2
    if mid % 2 == 0
      nums[mid] == nums[mid+1] ? left = mid+2 : right = mid-1
    else
      nums[mid] == nums[mid-1] ? left = mid+1 : right = mid-1
    end
  end

  return nums[left]
end

puts single_non_duplicate([3,3,7,7,10,11,11]) #10
