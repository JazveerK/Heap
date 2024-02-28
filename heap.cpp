//Jazveer Kaler
// 02/25/2024
// Heap: Program that creates a heap. Takes in up to 100 numbers and prints it out as a tree-based data structure
// numbers.txt from Tejas

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

void add(int num, int heap[], int& count);
int removeMax(int heap[], int& count);
void removeAll(int heap[], int& count);
void print(int heap[], int count, int index = 1, int depth = 0);

int main() {
    int heap[101] = {0};
    int count = 0;
    string command;
    bool running = true;

    cout << "WELCOME TO HEAP" << endl;

    while (running) { // Main Program
        cout << "Type in a command: ADD, PRINT, FILE, REMOVE, WIPE or QUIT" << endl; //Prompts user for input
        getline(cin, command);

        if (command == "ADD") { //ADD
            int num;
            cout << "Enter a number to add: ";
            cin >> num;
            add(num, heap, count);
            cin.ignore();
        }
        
        else if (command == "PRINT") { //PRINT
            if (count == 0)
                cout << "Heap is empty." << endl;
            else {
                cout << "Heap:" << endl;
                print(heap, count);
            }
        }
        
        else if (command == "FILE") { //FILE
            ifstream file("numbers.txt");
            if (!file)
                cout << "Error opening file" << endl;
            else {
                int num;
                
                while (file >> num) {
                    add(num, heap, count);
                }
                
                file.close();
                cout << "Numbers added from file." << endl;
            }
        }
        
        else if (command == "REMOVE") { //REMOVE
            if (count == 0) {
                cout << "Heap is empty." << endl;
            }
            else {
                int removed = removeMax(heap, count);
                cout << "Removed: " << removed << endl;
            }
        }
        
        else if (command == "WIPE") { //WIPE
            removeAll(heap, count);
            cout << "Heap wiped out." << endl;
        }
        
        else if (command == "QUIT") { //QUIT
            cout << "Program ended." << endl;
            running = false;
        }
    }

    return 0;
}

//adds numbers to heap array
void add(int num, int heap[], int& count) {
    int index = ++count;
    heap[index] = num;

    while (index > 1 && heap[index] > heap[index / 2]) {
        swap(heap[index], heap[index / 2]);
        index /= 2;
    }
}

//removes the largest number
int removeMax(int heap[], int& count) {
    int removed = heap[1];
    heap[1] = heap[count--];

    int index = 1;
    while (true) {
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int largest = index;

        if (leftChild <= count && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild <= count && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        }
        else
            break;
    }
    return removed;
}

//removes all the numbers
void removeAll(int heap[], int& count) {
    while (count > 0) {
        int removed = removeMax(heap, count);
        cout << removed << " ";
        //count--;
    }
    cout << endl;
}

//prints everything out
void print(int heap[], int count, int index, int depth) {
    if (index <= count) {
        print(heap, count, 2 * index + 1, depth + 1);
        cout << string(4 * depth, ' ') << heap[index] << endl;
        print(heap, count, 2 * index, depth + 1);
    }
}
