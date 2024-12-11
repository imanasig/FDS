//  Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed cannot be cancelled.
// Write C++ program to simulate the system using circular queue using array.

#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class CircularQueue {
private:
    string orders[MAX];
    int front, rear, size;

public:
    CircularQueue(int maxSize) : front(-1), rear(-1), size(maxSize) {}

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void addOrder(const string& order) {
        if (isFull()) {
            cout << "Queue overflow. Cannot accept more orders.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        orders[rear] = order;
        cout << "Order added: " << order << "\n";
    }

    void deleteOrder() {
        if (isEmpty()) {
            cout << "Queue underflow. No orders to delete.\n";
            return;
        }
        cout << "Order served: " << orders[front] << "\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Current orders in the queue: \n";
        int i = front;
        while (true) {
            cout << orders[i] << "\n";
            if (i == rear) break;
            i = (i + 1) % size;
        }
    }
};

int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the queue can accept: ";
    cin >> maxOrders;
    cin.ignore(); // To handle newline character after integer input

    CircularQueue orderQueue(maxOrders);
    int choice;
    string order;

    do {
        cout << "\nPizza Order Queue Menu:\n";
        cout << "1. Add Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter order description: ";
            getline(cin, order);
            orderQueue.addOrder(order);
            break;
        case 2:
            orderQueue.deleteOrder();
            break;
        case 3:
            orderQueue.displayOrders();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
