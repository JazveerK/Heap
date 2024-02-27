//Jazveer Kaler
// 02/25/2024
// Heap: Program that creates a heap. Takes in up to 100 numbers and prints it out as a tree-based data structure

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void add(int num, int heap[], int& count);
void print(int index, int count, int end, int (heap)[101]);
int removeMax(int elements[], int& count);
void removeAll(int elements[], int& count);

int main() {
    bool running = true;
    char command[15];
    int heap[101];
    int count = 0;
    cout << "WELCOME TO HEAP" << endl;
    
    for (int i = 0; i < 101; i++){
       heap[i] = NULL;
     }

    //Main program loop
    while (running) {

        //Takes in commands
        cout << "Type in a command: ADD, PRINT, REMOVE, WIPE or QUIT" << endl;
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
            print(1, 0, count, heap);
        }

        //REMOVE
        else if (strcmp(command, "REMOVE") == 0) {
            int removed = removeMax(heap, count);
            cout << "Removed: " << removed << endl;
        }
        
        //WIPE
        else if (strcmp(command, "WIPE") == 0) {
            removeAll(heap, count);
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

//From Galbraith
void print(int index, int count, int end, int (heap)[101]){
  if (heap[1] == NULL)
    cout << "";
  
  else{
    if((index*2) + 1 < end){
      print((index*2) + 1, count + 1, end, heap);
    }
      
    for (int i = 0; i < count; i++){
      cout << '\t';
    }
    cout << heap[index] << endl;
    
    if((index*2) < end)
      print((index*2), count + 1, end, heap);
    
  }
}

int removeMax(int elements[], int& count) {
    int removed = elements[0];
    elements[0] = elements[--count];

    int index = 0;
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < count && elements[leftChild] > elements[largest]) {
            largest = leftChild;
        }
        if (rightChild < count && elements[rightChild] > elements[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(elements[index], elements[largest]);
            index = largest;
        } else {
            break;
        }
    }

    return removed;
}

void removeAll(int elements[], int& count) {
    while (count > -1) {
        int removed = removeMax(elements, count);
        cout << "Removed: " << removed << endl;
    }
}
