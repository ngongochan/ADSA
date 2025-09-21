class Node:
    def __init__(self, value = 0, left = None, right = None):
        self.value = value
        self.right = right
        self.left = left

class BST:
    def __init__(self, root = None):
        self.root = root

    def search(self, target, node=None):
        if node == None:
            node = self.root
        if(node == None or node.value == target):
            return node
        if(target > node.value):
            return self.search(target, node.right)
        else:
            return self.search(target, node.left)

    def traverse(self, order):
        if order == "PRE":
            self.preorder(self.root)
        elif order == "IN":
            self.inorder(self.root)
        elif order == "POST":
            self.postorder(self.root)
        else:
            print("invalid")

    def inorder(self, node):
        if node == None:
            return
        self.inorder(node.left)
        print(node.value)
        self.inorder(node.right)

    def preorder(self, node):
        if node == None:
            return
        print(node.value)
        self.preorder(node.left)
        self.preorder(node.right)
        
    def postorder(self, node):
        if node == None:
            return
        self.postorder(node.left)
        self.postorder(node.right)
        print(node.value)
        # works the same way
        # if root != None:
        #     self.postorder(root.left)
        #     self.postorder(root.right)
        #     print(root.value)


#        5
# 1             10
root = Node(5, Node(1), Node(10))
bst = BST(root)
# bst.postorder(root)   # bst.traverse("POST")
node = bst.search(1)
if node:
    print(node.value)
else:
    print("not found")