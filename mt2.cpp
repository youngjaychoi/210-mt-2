#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    // void insert_after(int value, int position) {
    //     if (position < 0) {
    //         cout << "Position must be >= 0." << endl;
    //         return;
    //     }

    //     Node* newNode = new Node(value);
    //     if (!head) {
    //         head = tail = newNode;
    //         return;
    //     }

    //     Node* temp = head;
    //     for (int i = 0; i < position && temp; ++i)
    //         temp = temp->next;

    //     if (!temp) {
    //         cout << "Position exceeds list size. Node not inserted.\n";
    //         delete newNode;
    //         return;
    //     }

    //     newNode->next = temp->next;
    //     newNode->prev = temp;
    //     if (temp->next)
    //         temp->next->prev = newNode;
    //     else
    //         tail = newNode;
    //     temp->next = newNode;
    // }

    // void delete_val(int value) {
    //     if (!head) return;

    //     Node* temp = head;
        
    //     while (temp && temp->data != value)
    //         temp = temp->next;

    //     if (!temp) return; 

    //     if (temp->prev)
    //         temp->prev->next = temp->next;
    //     else
    //         head = temp->next; 

    //     if (temp->next)
    //         temp->next->prev = temp->prev;
    //     else
    //         tail = temp->prev; 

    //     delete temp;
    // }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev) {
            temp->prev->next = temp->next;
        }
    
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    int size() {
        int count = 0;

        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // void print_reverse() {
    //     Node* current = tail;
    //     if (!current) { 
    //         cout << "List is empty." << endl;
    //         return;
    //     }
    //     while (current) {
    //         cout << current->data << " ";
    //         current = current->prev;
    //     }
    //     cout << endl;
    // }
};

vector<string> readName(const string &inFile);
int setRandom(int min, int max);
void simulation(DoublyLinkedList &line, vector<string> &names);

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    DoublyLinkedList coffee;
    vector<string> name = readName("C:/code/names.txt");
    
    return 0;
}

vector<string> readName(const string &inFile) {
    vector<string> names;
    ifstream file(inFile);
    string name;

    while (file >> name) {
        names.push_back(name);
    }

    return names;
}

int setRandom (int min, int max) {
    return rand() % (max - min + 1) + min;
}

void simulation(DoublyLinkedList &line, vector<string> &names) {
    srand(time(0));
    int time = 20;

    for (int i = 0; i < 5; ++i) {
        string name = names[setRandom(0, names.size() - 1)];
        line.push_back(i);
        cout << "    " << name << " joins the line" << endl;
    }

    for (int j = 1; j < time; ++j) {
        cout << "Time step #" << time << ":" << endl;

        if (setRandom(1, 100) <= 40)
        if (setRandom(1, 100) <= 60)
        if (setRandom(1, 100) <= 20)
        if (setRandom(1, 100) <= 10)
        if (setRandom(1, 100) <= 10)
    }
    
}
