# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
   tn, tnp1, tnp2 = 4294967295, 0, 0
   nums.each do |num|
    tn = tn & ~(num & tn)
    tnp1 = tnp1 | (num & tn)

    tnp1 = tnp1 & ~(num & tnp1)
    tnp2 = tnp2 | (num & tnp1)

    tnp2 = tnp2 & ~(num & tnp2)
    tn = tn | (num & tnp2)
   end
   puts 'tn', tn
   puts 'tn + 1', tnp1
   puts 'tn + 2', tnp2
end

single_number([0,1,0,1,0,1,99])
