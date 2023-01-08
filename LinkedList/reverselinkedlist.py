
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None

    def append(self, value):

        if self.head is None:
            self.head = Node(value)
            return

        temp = self.head

        while temp.next is not None:
            temp = temp.next

        temp.next = Node(value)

    def reverse_linked_list(self):
        prev = None
        curr = self.head
        next = None

        while curr is not None:
            # save the next of curr
            next = curr.next

            curr.next = prev

            prev = curr
            curr = next

        self.head = prev

    def printList(self):
        temp = self.head

        while temp is not None:
            print(temp.value, end=" ")
            temp = temp.next

        print()

if __name__ == "__main__":

    l = LinkedList()

    l.append(43)
    l.append(3)
    l.append(43)
    l.append(3)

    l.printList()

    l.reverse_linked_list()

    l.printList()

