class Integer
  N_BYTES = [42].pack('i').size
  N_BITS = N_BYTES * 16
  MAX = 2**(N_BITS - 2) - 1
  MIN = -MAX - 1
end

# @param {Integer[]} nums
# @return {Integer}
def max_sub_array(nums)
  sum = 0
  max_sum = Integer::MIN

  nums.each do |num|
    sum += num
    max_sum = [sum, max_sum].max
    sum = 0 if sum.negative?
  end

  max_sum
end
