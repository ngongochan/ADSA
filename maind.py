class Node:
    def __init__(self, value = 0):
        self.value = value
        self.right = right
        self.left = left
        self.height = 1

class AVLTree:
    def __init__(self, root = None):
        self.root = root

    def height(self, node):
        # if node exits, return its height, which is 1
        if node:
            return node.height
        else:
            return 0

    def search(self, target, node=None):
        if node == None:
            node = self.root
        if(node == None or node.value == target):
            return node
        if(target > node.value):
            return self.search(target, node.right)
        else:
            return self.search(target, node.left)

    def delete(self, target):
        # root == None -> return (None)
        # root.value == target
            # leaf:
                # root.left == None and root.right == None
                # -> del root
            # 1 child:
                # root.left != None or root.right != None
                    # if root.left:
                        # temp = root.left
                        # del root.left
                    # else:
                        # temp = root.right
                        # del root.right
                    # root = temp
            # 2 children:
                # root.left != None and root.right != None
                    # temp = maxLeft(root)
                    # root.value = temp.value
                    # del temp


                # def maxLeft(node):
                #   if (node == None):
                    #     return
                    # current = node.left
                    # while node.right:
                    #     current = current.right
                    # return current


#         4
#     2       8
# 1      3 7      10




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
avl = AVLTree(root)
# avl.postorder(root)   # avl.traverse("POST")
node = avl.search(1)
if node:
    print(node.value)
else:
    print("not found")