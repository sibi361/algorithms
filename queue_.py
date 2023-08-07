class Queue():
    def __init__(self, max_queue_size=False) -> None:
        self.queue = []
        self.start = 0
        self.end = 0
        if (max_queue_size):
            self.max_queue_size = max_queue_size

    def get_size(self):
        return len(self.queue)

    def insert(self, element):
        if (self.get_size() + 1 > self.max_queue_size):
            return False
        self.queue.append(element)
        return True

    def delete(self):
        try:
            return self.queue.pop(0)
        except IndexError:
            return False

    def clear(self):
        if self.get_size() == 0:
            return False
        while self.get_size() > 0:
            self.delete()
        return True

    def print_queue(self):
        print(self.queue)


# try:
#     MAX_STACK_SIZE = int(input("Enter maximum stack size [default 5]: "))
# except ValueError:
#     MAX_STACK_SIZE = 5
MAX_STACK_SIZE = 5

queue = Queue(MAX_STACK_SIZE)


while (True):
    queue.print_queue()  # for easy debugging

    print("\nAvailable queue operations: \n\
        1 Insert \n\
        2 Delete \n\
        3 Clear \n\
        4 Get Size \n\
        5 Exit \n\
        ")
    try:
        op = int(input("# Enter option: "))
    except ValueError:
        print("Invalid option")
        continue

    if (op == 1):
        temp = input("# Enter element to insert: ")
        if len(temp) == 0:
            print("# input can't be empty")
            continue
        output = queue.insert(temp)
        if (output):
            print("# {} inserted successfully".format(output))
        else:
            print("# QUEUE OVERFLOW !!!")

    elif (op == 2):
        temp = queue.delete()
        if (temp):
            print("# {} was deleted".format(temp))
        else:
            print("# ERROR: queue IS EMPTY")

    elif (op == 3):
        output = queue.clear()
        if (output):
            print("# queue has been cleared")
        else:
            print("# ERROR: queue is already empty")

    elif (op == 4):
        print("# queue size: {}".format(queue.get_size()))

    elif (op == 5):
        queue.clear()
        print("# queue has been cleared")
        print("# Exiting")
        break
