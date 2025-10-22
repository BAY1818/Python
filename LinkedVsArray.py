# ----------- ARRAYLIST (Python list) -----------
print("===Array list Example ===")

arr = [] #dynamic arr
arr.append(10)
arr.append(20)
arr.append(30)

print("ArrayList contents: " , arr)
print("Access index 1 (0(1)): " , arr[1])

arr.insert(1,12)
print("After inserting 12 at index 1: " , arr)

# ----------- LinkedList -------------------

print ("\n==== Linked List Example ===")

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        seff.head = None
    
