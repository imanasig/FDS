// Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an 
// operating system. If the operating system does not use priorities, then the jobs are processed in the order they 
// enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue

#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Queue {
private:
    string jobs[MAX];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void addJob(const string& job) {
        if (isFull()) {
            cout << "Queue overflow. Cannot add more jobs.\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        jobs[++rear] = job;
        cout << "Job added: " << job << "\n";
    }

    void deleteJob() {
        if (isEmpty()) {
            cout << "Queue underflow. No jobs to delete.\n";
            return;
        }
        cout << "Job removed: " << jobs[front++] << "\n";
    }

    void displayJobs() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Current jobs in the queue: \n";
        for (int i = front; i <= rear; i++) {
            cout << jobs[i] << "\n";
        }
    }
};

int main() {
    Queue jobQueue;
    int choice;
    string job;

    do {
        cout << "\nJob Queue Menu:\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle the newline character after integer input

        switch (choice) {
        case 1:
            cout << "Enter job description: ";
            getline(cin, job);
            jobQueue.addJob(job);
            break;
        case 2:
            jobQueue.deleteJob();
            break;
        case 3:
            jobQueue.displayJobs();
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
