# TREE NODE
class Node
  attr_accessor :data, :left, :right

  def initialize(data = nil, left = nil, right = nil)
    @data = data
    @left = left
    @right = right
  end
end

# SOLUTION
class Solution
  def draw_morris_traversal_inorder(root)
    while root
      if root.left
        current = root.left
        current = current.right while current.right && current.right != root
        if current.right == root
          current.right = nil
          puts root.data
          root = root.right
        else
          current.right = root
          root = root.left
        end
      else
        puts root.data
        root = root.right
      end
    end
  end
end

root = Node.new(1, Node.new(2, Node.new(3), Node.new(4)), Node.new(5))
Solution.new.draw_morris_traversal_inorder(root)
