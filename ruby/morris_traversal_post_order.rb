# TREE NODE
class Node
  attr_accessor :data, :left, :right

  def initialize(data = nil, left = nil, right = nil)
    @data = data
    @left = left
    @right = right
  end
end

# SOLUTION CLASS
class Solution
  def post_order_morris_traversal(root)
    order = []
    while root
      if root.right
        curr = root.right
        curr = curr.left while curr.left && curr.left != root
        if curr.left
          curr.left = nil
          root = root.left
        else
          curr.left = root
          order.unshift(root.data)
          root = root.right
        end
      else
        order.unshift(root.data)
        root = root.left
      end
    end
    order
  end
end

root = Node.new(1, Node.new(2, Node.new(3), Node.new(4, nil, Node.new(5))), Node.new(6, Node.new(7)))
solve = Solution.new
puts solve.post_order_morris_traversal(root).join(' ')
