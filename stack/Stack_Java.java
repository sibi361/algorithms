// import java.util.Scanner;

class Stack {
    int MAX_SIZE = 100;
    int stack[];
    int top = -1;

    Stack() {
        stack = new int[MAX_SIZE];
    }

    Stack(int user_max_size) {
        this.MAX_SIZE = user_max_size;
        stack = new int[MAX_SIZE];
    }

    void push(int item) {
        if (top == this.MAX_SIZE - 1) {
            System.out.println("# ERROR: Stack Overflow");
            return;
        }
        this.stack[++top] = item;
    }

    int pop() {
        if (top == -1)
            return -999999;

        return this.stack[top--];
    }
}

class Stack_Java {
    public static void main(String args[]) {
        System.out.println("Implementing Stack data structure in Java\n");

        Stack st = new Stack(5);
        int popped;

        for (int i = 0; i < 6; i++) {
            System.out.println("Pushed " + i);

            st.push(i);
        }

        System.out.println();

        for (int i = 0; i < 6; i++) {
            popped = st.pop();
            if (popped == -999999) // handling stack underflow
                System.out.println("# ERROR: Stack Underflow");
            else
                System.out.println("Popped " + popped);
        }

        System.out.println();
    }

}
