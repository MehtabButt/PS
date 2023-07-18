# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  memo = {}
  nums.each_with_index do |num, idx|
    return [memo[num], idx] if memo[num]
    memo[target-num] = idx
  end
end

puts two_sum([3,2,4], 6)

