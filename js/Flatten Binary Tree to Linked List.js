// Definition for a binary tree node.
class Node {
    constructor(val) {
        this.val = val
        this.left = null
        this.right = null
    }
}

const flatten = function(root) {
    let cur;
    while(root != null) {
        if(root.left != null) {
            cur = root.left
            while(cur.right != null) cur = cur.right
            cur.right = root.right
            root.right = root.left
            root.left = null
            root = root.right
        }
        else root = root.right
    }
};

let root = null
root = new Node(1)
root.left = new Node(2)
root.right = new Node(3)
root.left.left = new Node(4)
root.left.right = new Node(5)

flatten(root)

while(root) {
    console.log(root.val)
    root = root.right
}
