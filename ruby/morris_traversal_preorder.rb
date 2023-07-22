# frozen_string_literal: true

# TREE NODE
class Node
  attr_accessor :left, :right, :data

  def initialize(data = nil, left = nil, right = nil)
    @data = data
    @left = left
    @right = right
  end
end

# SOLUTION CLASS
class Solution
  def get_morris_traversal_preorder(root)
    while root
      if root.left
        current = root.left
        current = current.right while current.right && current.right != root
        if current.right == root
          current.right = nil
          root = root.right
        else
          current.right = root
          puts root.data
          root = root.left
        end
      else
        puts root.data
        root = root.right
      end
    end
  end
end

root = Node.new(1, Node.new(2, Node.new(3), Node.new(4)), Node.new(5, Node.new(6), Node.new(7)))
sol = Solution.new
sol.get_morris_traversal_preorder(root)
