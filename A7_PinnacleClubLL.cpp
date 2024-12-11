// Department of Computer Engineering has student's club named 'Pinnacle Club'. 
// Students of second, third and final year of department can be granted membership on request.
// Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club.
// Write C++ program to maintain club member‘s information using singly linked list.
// Store student PRN and Name. Write functions to: 
// a) Add and delete the members as well as president or even secretary
// b) Compute total number of members of club 
// c) Display members 
// d) Two linked lists exists for two divisions, Concatenate two lists

#include <iostream>
#include <string>
using namespace std;

struct Member {
    string name;
    int prn;
    Member *next;
};

void insertMember(Member *&president, Member *&secretary, Member *member) {
    if (president == nullptr) {
        president = member;
    } else if (secretary == nullptr) {
        Member *temp = president;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = member;
        secretary = member;
    } else {
        Member *temp = president;
        while (temp->next != secretary) {
            temp = temp->next;
        }
        temp->next = member;
        member->next = secretary;
    }
}

void createMember(Member *&president, Member *&secretary) {
    string name;
    int prn;
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter the PRN: ";
    cin >> prn;

    Member *member = new Member;
    member->name = name;
    member->prn = prn;
    member->next = nullptr;

    insertMember(president, secretary, member);
}

void display(Member *president, Member *secretary) {
    Member *temp = president;
    while (temp != nullptr) {
        cout << temp->name << " " << temp->prn;
        if (temp == president) {
            cout << " (President)";
        } else if (temp == secretary) {
            cout << " (Secretary)";
        }
        cout << endl;
        temp = temp->next;
    }
}

int totalMembers(Member *president) {
    int count = 0;
    Member *temp = president;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteMember(Member *&president, Member *&secretary) {
    if (president == nullptr) {
        cout << "The member list is already empty." << endl;
        return;
    }

    int position;
    cout << "Enter the position of the member to be deleted: ";
    cin >> position;

    if (position == 0) {
        Member *toDelete = president;
        president = president->next;
        if (toDelete == secretary) {
            secretary = nullptr;
        }
        delete toDelete;
        return;
    }

    Member *temp = president;
    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position is out of bounds." << endl;
        return;
    }

    Member *toDelete = temp->next;
    if (toDelete == secretary) {
        secretary = temp;
    }
    temp->next = temp->next->next;
    delete toDelete;
}

Member* concatenate(Member *list1, Member *secretary1, Member *list2) {
    if (list1 == nullptr) return list2;
    Member *temp = list1;
    while (temp->next != secretary1) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}

int main() {
    Member *president1 = nullptr;
    Member *secretary1 = nullptr;
    Member *president2 = nullptr;
    Member *secretary2 = nullptr;

    cout << "Enter president-1's name: ";
    string name;
    int prn;
    cin >> name;
    cout << "Enter president-1's PRN: ";
    cin >> prn;
    president1 = new Member{name, prn, nullptr};

    int members1;
    cout << "Enter number of members (excluding president-1): ";
    cin >> members1;
    while (members1--) {
        createMember(president1, secretary1);
    }

    cout << "Enter secretary-1's name: ";
    cin >> name;
    cout << "Enter secretary-1's PRN: ";
    cin >> prn;
    secretary1 = new Member{name, prn, nullptr};
    insertMember(president1, secretary1, secretary1);

    cout << "Enter president-2's name: ";
    cin >> name;
    cout << "Enter president-2's PRN: ";
    cin >> prn;
    president2 = new Member{name, prn, nullptr};

    int members2;
    cout << "Enter number of members (excluding president-2): ";
    cin >> members2;
    while (members2--) {
        createMember(president2, secretary2);
    }

    cout << "Enter secretary-2's name: ";
    cin >> name;
    cout << "Enter secretary-2's PRN: ";
    cin >> prn;
    secretary2 = new Member{name, prn, nullptr};
    insertMember(president2, secretary2, secretary2);

    char decider;
    cout << "Enter Y to continue or N to exit: ";
    cin >> decider;

    while (decider == 'Y') {
        int choice;
        cout << "1- Display members\n2- Display total members\n3- Delete a member\n4- Concatenate two member lists\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                int presChoice;
                cout << "Enter 1 for president-1 or 2 for president-2: ";
                cin >> presChoice;
                if (presChoice == 1) {
                    display(president1, secretary1);
                } else {
                    display(president2, secretary2);
                }
                break;
            }
            case 2: {
                int presChoice;
                cout << "Enter 1 for president-1 or 2 for president-2: ";
                cin >> presChoice;
                if (presChoice == 1) {
                    cout << "Total members: " << totalMembers(president1) << endl;
                } else {
                    cout << "Total members: " << totalMembers(president2) << endl;
                }
                break;
            }
            case 3: {
                int presChoice;
                cout << "Enter 1 for president-1 or 2 for president-2: ";
                cin >> presChoice;
                if (presChoice == 1) {
                    deleteMember(president1, secretary1);
                } else {
                    deleteMember(president2, secretary2);
                }
                break;
            }
            case 4: {
                cout << "Concatenating the two member lists...\n";
                president1 = concatenate(president1, secretary1, president2);
                secretary1 = secretary2;
                break;
            }
            default:
                cout << "Invalid choice." << endl;
                break;
        }
        cout << "Enter Y to continue or N to exit: ";
        cin >> decider;
    }

    cout << "Program exited." << endl;
    return 0;
}
