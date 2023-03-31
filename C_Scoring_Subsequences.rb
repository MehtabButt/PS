$scores = {}

def get_score seq
  local_scores = {0 => 1}
  for i in (0...seq.length)
    for j in (i...seq.length)
      if $scores.key?(seq.slice(i..j).to_s)
        s = $scores[seq.slice(i..j).to_s]
      else
        s = seq.slice(i..j).inject(:*)/((1..(j-i+1)).inject(:*) || 1)
        $scores[seq.slice(i..j).to_s] = s
      end
      if local_scores.key?(j-i+1)
        if local_scores[j-i+1] < s
          local_scores[j-i+1] = s
        end
      else
        local_scores[j-i+1] = s
      end
    end
  end
  local_scores.max { |p1, p2| p1[1] == p2[1] ? p1[0] <=> p2[0] : p1[1] <=> p2[1] }[0]
end

def get_scores seq
  max_score = []
  for i in (1..seq.length)
    max_score.push(get_score(seq.slice(0, i)))
  end
  max_score
end

t = gets.to_i
seq = []
while t > 0
  n = gets.to_i
  seq = gets.split(' ').map{ |i| i.to_i }
  puts get_scores(seq).join(' ')
  t -= 1
end
