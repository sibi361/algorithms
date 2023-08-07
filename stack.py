class Stack():
    def __init__(self, max_stack_size=False) -> None:
        self.stack = []
        self.i = 0
        if (max_stack_size):
            self.max_stack_size = max_stack_size

    def get_size(self):
        return self.i

    def push(self, element):
        if (self.i + 1 > self.max_stack_size):
            return False
        self.stack.append(element)
        self.i += 1
        return True

    def pop(self):
        try:
            popped = self.stack.pop()
            self.i -= 1
            return popped
        except:
            return False

    def clear(self):
        while self.i > 0:
            print(self.i)
            self.pop()


# try:
#     MAX_STACK_SIZE = int(input("Enter maximum stack size [default 5]: "))
# except ValueError:
#     MAX_STACK_SIZE = 5
MAX_STACK_SIZE = 5

stack = Stack(MAX_STACK_SIZE)

while (True):
    print("\nAvailable stack operations: \n\
        1 Push \n\
        2 Pop \n\
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
        temp = input("# Enter element to push: ")
        if len(temp) == 0:
            print("# input can't be empty")
            continue
        output = stack.push(temp)
        if (output):
            print("# {} pushed successfully".format(output))
        else:
            print("# STACK OVERFLOW !!!")
    elif (op == 2):
        temp = stack.pop()
        if (temp):
            print("# {} was popped".format(temp))
        else:
            print("# ERROR: STACK IS EMPTY")
    elif (op == 3):
        stack.clear()
        print("# stack has been cleared")
    elif (op == 4):
        print("# stack size: {}".format(stack.get_size()))
    elif (op == 5):
        stack.clear()
        print("# stack has been cleared")
        print("# Exiting")
        break
