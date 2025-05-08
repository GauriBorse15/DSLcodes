#include <iostream>
using namespace std;

class Queue {
public:
    int front, rear;
    int q[20];

    Queue() {
        front = rear = 0;
    }

    void insert(int key) {
        if (rear < 20) {
            q[rear++] = key;
        } else {
            cout << "Queue is full";
        }
    }

    int Delete() {
        if (rear != front) {
            return q[front++];
        } else {
            cout << "Queue is empty";
            return -1;
        }
    }

    bool isEmpty() {
        return front == rear;
    }
};

class Stack {
public:
    int top;
    int s[20];

    Stack() {
        top = -1;
    }

    void push(int key) {
        if (top < 19) {
            s[++top] = key;
        } else {
            cout << "Stack is full";
        }
    }

    int pop() {
        if (top != -1) {
            return s[top--];
        } else {
            cout << "Stack is empty";
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

class Graph {
    int vcnt;
    int a[20][20];
    int visited[20]; // used for both bfs and dfs

public:
    Graph() {
        vcnt = 0;
    }

    void adj_matrix();
    void dis_adj_matrix();
    void bfs();
    void dfs();
    void reset_visited();
};

void Graph::adj_matrix() {
    cout << "Enter number of vertices: ";
    cin >> vcnt;
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < vcnt; i++) {
        for (int j = 0; j < vcnt; j++) {
            cin >> a[i][j];
        }
    }
}

void Graph::dis_adj_matrix() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vcnt; i++) {
        for (int j = 0; j < vcnt; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::reset_visited() {
    for (int i = 0; i < vcnt; i++) {
        visited[i] = 0;
    }
}

void Graph::bfs() {
    int start;
    cout << "Enter start vertex (0 to " << vcnt - 1 << "): ";
    cin >> start;

    Queue q;
    reset_visited();

    cout << "BFS Traversal: ";
    visited[start] = 1;
    q.insert(start);

    while (!q.isEmpty()) {
        int curr = q.Delete();
        if (curr == -1) break;
        cout << curr << " ";
        for (int i = 0; i < vcnt; i++) {
            if (a[curr][i] == 1 && visited[i] == 0) {
                q.insert(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

void Graph::dfs() {
    int start;
    cout << "Enter start vertex (0 to " << vcnt - 1 << "): ";
    cin >> start;

    Stack s;
    reset_visited();

    cout << "DFS Traversal: ";
    s.push(start);

    while (!s.isEmpty()) {
        int curr = s.pop();
        if (!visited[curr]) {
            cout << curr << " ";
            visited[curr] = 1;
            // Push neighbors in reverse order for correct DFS
            for (int i = vcnt - 1; i >= 0; i--) {
                if (a[curr][i] == 1 && visited[i] == 0) {
                    s.push(i);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    Graph g;
    int choice;

    do {
        cout << "\n***** MENU *****";
        cout << "\n1. Enter adjacency matrix";
        cout << "\n2. Display adjacency matrix";
        cout << "\n3. BFS Traversal";
        cout << "\n4. DFS Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.adj_matrix();
            break;
        case 2:
            g.dis_adj_matrix();
            break;
        case 3:
            g.bfs();
            break;
        case 4:
            g.dfs();
            break;
        case 5:
            cout << "Exiting program.";
            break;
        default:
            cout << "Enter a valid choice.";
            break;
        }
    } while (choice != 5);

    return 0;
}
