def find(parent, n)
  return n if parent[n] == n

  parent[n] = find(parent, parent[n])
end

def union(parent, rank, n1, n2)
  if rank[n1] == rank[n2]
    parent[n2] = n1
    rank[n1] += 1
  elsif rank[n1] > rank[n2]
    parent[n2] = n1
  else
    parent[n1] = n2
  end
end

def find_mst(n, _e, edges)
  edges.sort! { |e1, e2| e1[2] <=> e2[2] }

  parent = Array.new(n) { |i| i }
  rank = Array.new(n, 0)

  mst_wt = 0

  edges.each do |edge|
    n1 = find(parent, edge[0])
    n2 = find(parent, edge[1])
    wt = edge[2]

    next unless n1 != n2

    union(parent, rank, n1, n2)
    mst_wt += wt
    puts "#{edge[0]} __ #{edge[1]} == #{wt}"
  end

  puts "total weight: #{mst_wt}"
end

n = 4
e = 5
edges = [[0, 1, 10],
         [0, 2, 6],
         [0, 3, 5],
         [1, 3, 15],
         [2, 3, 4]]

find_mst(n, e, edges)
