class Stack():
    def __init__(self, max_stack_size) -> None:
        self.stack = []
        self.i = 0
        self.max_stack_size = max_stack_size

    def get_size(self):
        return self.i

    def push(self, element):
        if (self.i < 0):
            self.i = 0
        if (self.i + 1 > self.max_stack_size):
            return "# STACK OVERFLOW !!!"
        self.stack.append(element)
        self.i += 1
        return self.i

    def pop(self):
        try:
            popped = self.stack.pop()
            self.i -= 1
            return popped
        except:
            return "# STACK IS EMPTY"

    def clear(self):
        while self.i > 0:
            print(self.i)
            self.pop()


MAX_STACK_SIZE = 2

a = Stack(MAX_STACK_SIZE)
print("pushed:", a.push(1))
print("stack size:", a.get_size())
print()

print("pushed:", a.push(999))
print("stack size:", a.get_size())
print()

print("pushed:", a.push("cow"))
print("stack size:", a.get_size())
print()

# print(a.clear())

print("popped:", a.pop())
print("stack size:", a.get_size())
print()

print("popped:", a.pop())
print("stack size:", a.get_size())
print()

print("popped:", a.pop())
print("stack size:", a.get_size())
print()

print("popped:", a.pop())
print("stack size:", a.get_size())
print()
