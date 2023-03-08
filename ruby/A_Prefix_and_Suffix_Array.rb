def is_palindrome p_and_s
  palindrome = {}
  p_and_s.each do |ps|
    palindrome.key?(ps.reverse) ? palindrome[ps.reverse] += 1 : palindrome[ps] = 1
  end
  palindrome.keys.length == p_and_s.length/2.0 ? 'Yes' : 'No'
end

t = gets.to_i
p_and_s = []
while t > 0 do
  n = gets.to_i
  p_and_s = gets.split(' ')
  puts is_palindrome(p_and_s)
  t -= 1
end
