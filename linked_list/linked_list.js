function log_single_line(text) {
    process.stdout.write(text);
}

class Node {
    constructor(data = null, nextNode = null) {
        this.data = data;
        this.nextNode = nextNode;
    }
}

class LinkedList {
    constructor(headData) {
        this.head = new Node(headData);
        this.tail = this.head;
        return this;
    }

    append(data) {
        let node = this.head;
        if (!node) {
            this.head = new Node(data);
            return true;
        }

        while (node.nextNode !== null) node = node.nextNode;

        node.nextNode = new Node(data);
        this.tail = node.nextNode;
        return true;
    }

    prepend(data) {
        if (!this.head) return this.append(data);
        this.head = new Node(data, this.head);
        return true;
    }

    size() {
        let node = this.head,
            counter = 1;
        if (!node) return 0;

        while (node.nextNode !== null) {
            node = node.nextNode;
            counter++;
        }

        return counter;
    }

    at(index) {
        const size = this.size();
        if (index < 0 || index > size - 1) return null;

        let node = this.head,
            counter = 0;

        while (counter !== index) {
            node = node.nextNode;
            counter++;
        }

        return node.data;
    }

    pop() {
        const size = this.size();
        let node = this.head;

        if (!size) return false;
        else if (size === 1) {
            this.head = null;
            return node.data;
        } else {
            while (node.nextNode.nextNode !== null) node = node.nextNode;

            const popped = node.nextNode.data;
            node.nextNode = null;
            return popped;
        }
    }

    contains(query) {
        let node = this.head;
        if (!node) return false;

        while (node.nextNode !== null) {
            if (node.data === query) return true;
            node = node.nextNode;
        }

        if (node.data === query) return true;
        return false;
    }

    find(query) {
        let node = this.head,
            counter = 0;
        if (!node) return null;

        while (node.nextNode !== null) {
            if (node.data === query) return counter;
            node = node.nextNode;
            counter++;
        }

        if (node.data === query) return counter;
        return null;
    }

    toString() {
        let node = this.head;
        if (!node) return false;

        do {
            if (node.nextNode) log_single_line(`( ${node.data} ) -> `);
            else log_single_line(`( ${node.data} ) -> null`);
            node = node.nextNode;
        } while (node !== null);

        console.log();
        return true;
    }

    insertAt(value, index) {
        const size = this.size();
        let node = this.head,
            counter = 0;
        if (index < 0 || index > size) return false;

        if (index === 0) {
            this.prepend(value);
            return true;
        } else if (index === size) {
            this.append(value);
            return true;
        }

        while (counter !== index - 1) {
            node = node.nextNode;
            counter++;
        }

        node.nextNode = new Node(value, node.nextNode);

        return true;
    }

    removeAt(index) {
        const size = this.size();
        let node = this.head,
            counter = 0;
        if (index < 0 || index >= size) return false;

        if (index === 0) {
            if (size === 1) this.head = null;
            else this.head = node.nextNode;
            return true;
        }

        while (counter < index - 1) {
            node = node.nextNode;
            counter++;
        }

        node.nextNode = node.nextNode.nextNode;

        return true;
    }
}

console.log("Initializing linked list");
const list = new LinkedList("0");

list.append("10");
list.append("20");
list.append("30");
list.prepend("-100");
list.toString();
console.log();

console.log("HEAD:", list.head.data);
console.log("TAIL:", list.tail.data);
console.log("SIZE:", list.size());
console.log();

console.log("Popping elements");
console.log(`Popped ${list.pop()}`);
console.log(`Popped ${list.pop()}`);
list.toString();
console.log();

const index = 2;
console.log(`At index ${index}:`, list.at(index));

const query = "10";
console.log(`List contains "${query}": ${list.contains(query)}`);
console.log(`Index of "${query}": ${list.find(query)}`);
console.log();

console.log("Inserting elements at index");
list.insertAt("-200", 0);
list.insertAt("50", 5);
list.insertAt("middle", 3);
list.toString();
console.log();

console.log("Removing elements at index");
list.removeAt(0);
list.toString();
list.removeAt(2);
list.toString();
console.log();

console.log("Popping elements");
console.log(`Popped ${list.pop()}`);
list.toString();
console.log(`Popped ${list.pop()}`);
list.toString();
console.log(`Popped ${list.pop()}`);
list.toString(); // list is empty
console.log();
