class Slot:
    def __init__(self):
        self.value = None
        self.status = "never used"

class HashTable:
    def __init__(self):
        self.slots = [Slot() for _ in range(26)]

    def search(self, word):
        start_index = ord(word[-1]) - ord('a')
        current_index = start_index

        while True:
            slot = self.slots[current_index]
            if slot.value == word:
                return True
            if slot.status == "never used":
                return False

            current_index = (current_index + 1) % 26
            if current_index == start_index:
                return False

    def insert(self, word):
        if self.search(word):
            return

        index = ord(word[-1]) - ord('a')
        start_index = index

        while True:
            slot = self.slots[index]
            if slot.status in ("tombstone", "never used"):
                slot.value = word
                slot.status = "occupied"
                return

            index = (index + 1) % 26
            if index == start_index:
                return

    def delete(self, word):
        if not self.search(word):
            return  # not found, nothing to do

        index = ord(word[-1]) - ord("a")
        start_index = index

        while True:
            slot = self.slots[index]

            if slot.value == word:
                slot.value = None
                slot.status = "tombstone"
                return

            index = (index + 1) % 26
            if index == start_index:
                return
                
    def traverse(self):
        for i, slot in enumerate(self.slots):
            if (slot.status == "occupied"):
                print(slot.value, end=" ")


if __name__ == "__main__":
    ht = HashTable()
    moves = input().split()

    for move in moves:
        action = move[0]
        word = move[1:]

        if action == "A":
            ht.insert(word)
        else:
            ht.delete(word)

    ht.traverse()
