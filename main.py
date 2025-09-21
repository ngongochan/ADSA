class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.height = 1   # leaf node starts with height 1

class AVLTree:
    def __init__(self):
        self.root = None

    def get_height(self, node):
        if node:
            return node.height
        else:
            return 0

    def get_balance(self, node):
        if node:
            return self.get_height(node.left) - self.get_height(node.right)
        else:
            return 0

    def get_max(self, node):
        current = node
        while current.right:
            current = current.right
        return current

    def rebalance(self, node):
        balance = self.get_balance(node)
        # LL
        if balance > 1 and self.get_balance(node.left) >= 0:
            return self.right_rotate(node)
        # LR
        if balance > 1 and self.get_balance(node.left) < 0:
            node.left = self.left_rotate(node.left)
            return self.right_rotate(node)
        # RR
        if balance < -1 and self.get_balance(node.right) <= 0:
            return self.left_rotate(node)
        # RL
        if balance < -1 and self.get_balance(node.right) > 0:
            node.right = self.right_rotate(node.right)
            return self.left_rotate(node)
        return node

    def right_rotate(self, y):
        x = y.left
        T2 = x.right
        x.right = y
        y.left = T2
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        x.height = 1 + max(self.get_height(x.left), self.get_height(x.right))
        return x

    def left_rotate(self, x):
        y = x.right
        T2 = y.left
        y.left = x
        x.right = T2
        x.height = 1 + max(self.get_height(x.left), self.get_height(x.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        return y

    def insert(self, node, value):
        if not node:
            return Node(value)

        if value < node.value:
            node.left = self.insert(node.left, value)
        else:
            node.right = self.insert(node.right, value)
        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
        return self.rebalance(node)

    def insert_value(self, value):
        self.root = self.insert(self.root, value)

    def delete(self, node, value):
        if not node:
            return node  # value not found, do nothing

        # BST deletion
        if value < node.value:
            node.left = self.delete(node.left, value)
        elif value > node.value:
            node.right = self.delete(node.right, value)
        else:
            # node with value found
            if not node.left and not node.right:
                # leaf node
                return None
            elif node.left and not node.right:
                # only left child
                return node.left
            elif node.right and not node.left:
                # only right child
                return node.right
            else:
                # two children: replace with max of left subtree
                temp = self.get_max(node.left)
                node.value = temp.value
                node.left = self.delete(node.left, temp.value)
        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
        return self.rebalance(node)

    def delete_value(self, value):
        self.root = self.delete(self.root, value)

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

if __name__ == "__main__":
    import sys
    avl = AVLTree()
    moves = input().split()
    for move in moves:
        if move[0] == "A":
            value = int(move[1:])
            avl.insert_value(value)
        elif move[0] == "D":
            value = int(move[1:])
            avl.delete_value(value)
        else:
            avl.traverse(move)
