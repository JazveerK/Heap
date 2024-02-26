//Jazveer Kaler
// 02/25/2024
// Heap: Program that creates a heap. Takes in up to 100 numbers and prints it out as a tree-based data structure

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void add(int num, int heap[], int& count);
void print(int heap[], int count); //just for testing rn
int removeMax();
void removeAll();

int main() {
    bool running = true;
    char command[15];
    int heap[101];
    int count = 0;
    cout << "WELCOME TO HEAP" << endl;

    //Main program loop
    while (running) {

        //Takes in commands
        cout << "Type in a command: ADD, PRINT, DELETE, or QUIT" << endl;
        cin.get(command, 16);
        cin.ignore(16, '\n');

        //ADD
        if (strcmp(command, "ADD") == 0) {
            int num;
            cout << "Enter a number to add: ";
            cin >> num;
            cin.ignore();
            add(num, heap, count);
        }
        
        //PRINT
        else if (strcmp(command, "PRINT") == 0) {
            print(heap, count);
        }

        //DELETE
        else if (strcmp(command, "DELETE") == 0) {
            int removed = removeMax(heap, count);
            cout << "Removed: " << removed << endl;
        }

        //QUIT
        else if (strcmp(command, "QUIT") == 0) {
            cout << "Program ended." << endl;
            running = false;
        }
    }

    return 0;
}

void add(int num, int heap[], int& count) {
    int index = count;
    heap[count++] = num;

    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void print(int heap[], int count) {
    cout << "Heap: ";
    for (int i = 0; i < count; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int removeMax(int heap[], int& count) {


void removeAll(int heap[], int& count) {

}
