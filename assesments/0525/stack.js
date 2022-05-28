class node {
    constructor(val, next) {
        this.val = val;
        this.next = next;
    }
}

class stack {
    constructor() {
        this.head = new node(0, null);
        this.count = 0;
    }

    pop() {
        if (this.count == 0) {
            return;
        }

        let n = this.head.next;
        this.head.next = this.head.next.next;
        return n.val;
    }

    push(val) {
        let n = new node(val, this.head.next);
        this.head.next = n;    
        this.count++;
    }

    values() {
        
    }
}