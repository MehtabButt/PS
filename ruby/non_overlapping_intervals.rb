# @param {Integer[][]} intervals
# @return {Integer}
def erase_overlap_intervals(intervals)
  intervals.sort! { |a, b| a<=>b }
  repeat = 0
  i = 1
  while i < intervals.length
    if intervals[i][0] < intervals[i-1][1]
      intervals[i][1] >= intervals[i-1][1] ? intervals.delete_at(i) : intervals.delete_at(i-1)
      repeat += 1
      i -= 1
    end
    i += 1
  end
  repeat
end
