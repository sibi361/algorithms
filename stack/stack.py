class Stack():
    def __init__(self, max_stack_size=False) -> None:
        self.stack = []
        if (max_stack_size):
            self.max_stack_size = max_stack_size

    def get_size(self):
        return len(self.stack)

    def push(self, element):
        if (self.get_size() + 1 > self.max_stack_size):
            return False
        self.stack.append(element)
        return True

    def pop(self):
        try:
            return self.stack.pop()
        except IndexError:
            return False

    def clear(self):
        if self.get_size() == 0:
            return False
        while self.get_size() > 0:
            self.pop()
        return True

    def print_stack(self):
        print(self.stack)


# try:
#     MAX_STACK_SIZE = int(input("Enter maximum stack size [default 5]: "))
# except ValueError:
#     MAX_STACK_SIZE = 5
MAX_STACK_SIZE = 5

stack = Stack(MAX_STACK_SIZE)

while (True):
    stack.print_stack()  # for easy debugging

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
            print("# {} pushed successfully".format(temp))
        else:
            print("# STACK OVERFLOW !!!")

    elif (op == 2):
        temp = stack.pop()
        if (temp):
            print("# {} was popped".format(temp))
        else:
            print("# ERROR: STACK IS EMPTY")

    elif (op == 3):
        output = stack.clear()
        if (output):
            print("# stack has been cleared")
        else:
            print("# ERROR: stack is already empty")

    elif (op == 4):
        print("# stack size: {}".format(stack.get_size()))

    elif (op == 5):
        stack.clear()
        print("# stack has been cleared")
        print("# Exiting")
        break
