def make_no_divide div
  div.each_with_index do |d, i|
    div[i] = d + 1 if d == 1
    if d % div[i-1] == 0 and i > 0
      div[i] = d + 1
    end
  end
  div
end

t = gets.to_i
div = []
while t > 0 do
  n = gets.to_i
  div = gets.split(' ').map{ |i| i.to_i }
  puts make_no_divide(div).join(' ')
  t -= 1
end
