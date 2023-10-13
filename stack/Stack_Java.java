import java.util.EmptyStackException;

class Stack<T> {
    private int DEFAULT_MAX_SIZE = 100, max_size, top;
    private T stack[];

    public Stack() {
        this.max_size = DEFAULT_MAX_SIZE;
        initializeStack();
    }

    public Stack(int user_max_size) {
        this.max_size = user_max_size;
        initializeStack();
    }

    private void initializeStack() {
        top = -1;
        stack = (T[]) new Object[max_size];
    }

    public void push(T item) {
        if (top == this.max_size - 1) {
            System.out.println("# ERROR: Stack Overflow");
            return;
        }
        this.stack[++top] = item;
    }

    public T pop() {
        if (top == -1)
            throw new EmptyStackException();

        return this.stack[top--];
    }
}

class Stack_Java {
    public static void main(String args[]) {
        System.out.println("Implementing Stack data structure in Java\n");

        Stack<Integer> st = new Stack<Integer>(5);
        int popped;

        for (int i = 0; i < 6; i++) {
            System.out.println("Pushed " + i);

            st.push(i);
        }

        System.out.println();

        for (int i = 0; i < 6; i++) {
            try {
                popped = st.pop();
                System.out.println("Popped " + popped);
            } catch (EmptyStackException e) {
                System.out.println("# ERROR: Stack Underflow");
            }
        }

        System.out.println();
    }

}
