#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    int priority;
    int arrival;

    bool operator<(const Patient &other) const {
        if (priority != other.priority) {
            return priority > other.priority;
        }
        return arrival > other.arrival;
    }
};

priority_queue<Patient> pq;
int counter = 0;

string priorityName(int p) {
    if (p == 1) {
        return "Critical";
    } else if (p == 2) {
        return "Serious";
    }
    return "Normal";
}

int readInt(string message) {
    int value;
    cout << message;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a number: ";
    }
    return value;
}

void showMenu() {
    cout << "\n===== HOSPITAL PATIENT QUEUE =====\n";
    cout << "1. Add a patient\n";
    cout << "2. Show next patient\n";
    cout << "3. Treat highest-priority patient\n";
    cout << "4. Show all waiting patients\n";
    cout << "5. Exit\n";
}

void printPatient(const Patient &p) {
    cout << "ID: " << p.id;
    cout << " | Name: " << p.name;
    cout << " | Age: " << p.age;
    cout << " | Priority: " << p.priority;
    cout << " (" << priorityName(p.priority) << ")\n";
}

void addPatient() {
    Patient p;
    counter++;
    p.id = counter;
    p.arrival = counter;
    cout << "Enter name (one word): ";
    cin >> p.name;
    p.age = readInt("Enter age: ");
    cout << "1=Critical 2=Serious 3=Normal\n";
    p.priority = readInt("Enter priority (1-3): ");
    while (p.priority < 1 || p.priority > 3) {
        p.priority = readInt("Enter 1, 2 or 3 only: ");
    }
    pq.push(p);
    cout << p.name << " was added as ";
    cout << priorityName(p.priority) << ".\n";
}

void showNextPatient() {
    if (pq.empty()) {
        cout << "No patients are waiting.\n";
        return;
    }
    cout << "Next patient to be treated:\n";
    printPatient(pq.top());
}

void treatPatient() {
    if (pq.empty()) {
        cout << "No patients are waiting.\n";
        return;
    }
    Patient p = pq.top();
    pq.pop();
    cout << "Treating patient:\n";
    printPatient(p);
    cout << "Still waiting: " << pq.size() << "\n";
}

void showAllPatients() {
    if (pq.empty()) {
        cout << "No patients are waiting.\n";
        return;
    }
    priority_queue<Patient> temp = pq;
    int position = 1;
    cout << "Waiting patients (by priority):\n";
    while (!temp.empty()) {
        cout << position << ". ";
        printPatient(temp.top());
        temp.pop();
        position++;
    }
}

int main() {
    int choice;
    do {
        showMenu();
        choice = readInt("Enter your choice: ");
        if (choice == 1) {
            addPatient();
        } else if (choice == 2) {
            showNextPatient();
        } else if (choice == 3) {
            treatPatient();
        } else if (choice == 4) {
            showAllPatients();
        } else if (choice == 5) {
            cout << "Exiting program. Goodbye!\n";
        } else {
            cout << "Invalid choice. Enter 1 to 5.\n";
        }
    } while (choice != 5);
    return 0;
}