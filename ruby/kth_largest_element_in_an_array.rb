# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer}

def partition(nums, l, r)
  x = nums[r]
  i = l
  (l...r).each do |j|
    if nums[j] >= x
      nums[i], nums[j] = nums[j], nums[i]
      i += 1
    end
  end
  nums[r], nums[i] = nums[i], nums[r]
  i
end

def find_kth_largest_util(nums, l, r, k)
  return unless k >= l && k <= r + 1

  ind = partition(nums, l, r)

  if k - 1 == ind
    nums[ind]
  elsif k - 1 < ind
    find_kth_largest_util(nums, l, ind - 1, k)
  else
    find_kth_largest_util(nums, ind + 1, r, k)
  end
end

def find_kth_largest(nums, k)
  puts find_kth_largest_util(nums, 0, nums.length - 1, k)
end

find_kth_largest([3, 2, 1, 5, 6, 4], 2)
