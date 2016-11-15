//*****************************************************************************
// David Poss                                                                 *
// CPSC 335                                                                   *
// 9/6/2016                                                                   *
// Professor Bein                                                             *
//*****************************************************************************

/* Program Description:
User inputs an integer, n, to signify the number of light colored disks.
Light disks are represented with a 0, dark disks with 1.
The program uses two versions of bubble sort to sort the disks.
*/

#include <iostream>

void setDisks(int n, int* list);   // initializes disks
void printDisks(int n, int* list); // prints the list of disks

int main() {
    std::cout << "\nEnter the the number of light disks: ";
    int  n;
    std::cin >> n;
    int  numSwaps = 0; //number of swaps made for each algorithm
    int  two_n = 2 * n; //two * n for iterating through loops
    int* disks = new int[two_n];
    bool keepSorting = false;

    ///--------------------Left to Right Method--------------------///   
    setDisks(n, disks);
    std::cout << "\nLeft to Right Method \n\tDisks before sorting: ";
    printDisks(n, disks);
    for (int i = 0; i < two_n; i++) {
        keepSorting = false;
        for (int k = i; k < two_n - 1; k++) {
            if (disks[k] > disks[k + 1]) {  //disk[k] is dark
                disks[k] = 0;     //disk[k] becomes light
                disks[k + 1] = 1; //disk[k+1] becomes dark
                numSwaps++;              //increment step counter
                keepSorting = true;
            }
        }
        if (!keepSorting) {
                break;
            }
    }
    std::cout << "\n\tDisks after sorting:  ";
    printDisks(n, disks);
    std::cout << "\n\tNumber of swaps: " << numSwaps << std::endl;

    ///----------------------Lawnmower Method----------------------///
    numSwaps = 0;
    setDisks(n, disks);
    std::cout << "\nLawnmower Method \n\tDisks before sorting: ";
    printDisks(n, disks);
    for (int i = 0; i < n; i++) {
        keepSorting = false;
        for (int j = i; j < two_n - 1 - i; j++) {// -i b/c we sort to the back
            if (disks[j] > disks[j + 1]) { //disk[j] is dark
                disks[j] = 0;
                disks[j + 1] = 1;
                keepSorting = true;
                numSwaps++;
            }
        }
        for (int k = two_n - 2 - i; k > i; k--) {
            if (disks[k] > disks[k + 1]) { //disk[k] is dark
                disks[k + 1] = 1;
                disks[k] = 0;
                keepSorting = true;
                numSwaps++;
            }
        }
        if (!keepSorting) { 
            break; 
            }
    }
    std::cout << "\n\tDisks after sorting:  ";
    printDisks(n, disks);
    std::cout << "\n\tNumber of swaps: " << numSwaps << std::endl << std::endl;
    delete[] disks;
    return 0;
}

void setDisks(int n, int *list) {
    for (int i = 0; i < n; i++) {
        list[2 * i] = 1; // light disk
        list[2 * i + 1] = 0; // dark disk
    }
}

void printDisks(int n, int* list) {
    for (int i = 0; i < 2 * n; i++) {
        std::cout << list[i];
    }
}
