def longest_substring(s, k)
  max_uniq_char = s.chars.uniq.length
  longest = 0

  for uniq_char in (1..max_uniq_char) do
    window_start = -1
    window_end = 0
    window = ''
    frequency = {}
    for char in s.chars do
      window << char
      window_end += 1
      frequency.key?(char) ? frequency[char] += 1 : frequency[char] = 1
      while frequency.keys.length > uniq_char
        frequency[window[0]] -= 1
        frequency.delete(window[0]) if frequency[window[0]] == 0
        window = window.slice(1..-1)
        window_start += 1
      end
      longest = window.length if frequency.values.all? { |f| f >= k } && window.length > longest
    end
  end
  longest
end


longest_substring('ababbc', 2)
