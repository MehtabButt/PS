MAX = (2**(0.size * 8 - 2) - 1)

def print_mst(graph, parent, v)
  total_wt = 0
  (1...v).each do |vi|
    total_wt += graph[parent[vi]][vi]
    puts "#{vi} __ #{parent[vi]} = #{graph[parent[vi]][vi]}"
  end
  puts "total weight: #{total_wt}"
end

def find_vertex(keys, visited)
  min_wt = MAX
  min_wt_ind = nil
  keys.each_with_index do |wt, ind|
    if wt < min_wt && !visited[ind]
      min_wt = wt
      min_wt_ind = ind
    end
  end
  min_wt_ind
end

def find_mst(v, graph)
  visited = Array.new(v, false)
  keys = Array.new(v, MAX)
  parent = [-1]
  keys[0] = 0

  (v - 1).times do
    vi = find_vertex(keys, visited)
    visited[vi] = true

    v.times do |i|
      if graph[vi][i] != 0 && !visited[i] && graph[vi][i] < keys[i]
        parent[i] = vi
        keys[i] = graph[vi][i]
      end
    end
  end

  print_mst(graph, parent, v)
end

v = 5
graph = [[0, 2, 0, 6, 0],
         [2, 0, 3, 8, 5],
         [0, 3, 0, 0, 7],
         [6, 8, 0, 0, 9],
         [0, 5, 7, 9, 0]]
find_mst(v, graph)
