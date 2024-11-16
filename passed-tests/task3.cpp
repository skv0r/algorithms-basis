#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string creatingNumsB(int counter, int numsA[]) {
    int numsB[counter];

    int leftIndex, rightIndex;

    for (int i=0; i != counter; i++) {
    if (i == counter-1) {
        if (counter % 2 == 1) {
            if (numsA[counter-1] % 2 == 0) {
            numsB[counter-1] = numsA[counter-1] + numsA[counter-2];

            }
            else {
                numsB[i] = numsA[i];
            }
        }
        else {
            if (numsA[counter-1] % 2 == 0) {
            numsB[counter-1] = numsA[counter-1] + numsA[counter-2];

            }
            else {
                numsB[i] = numsA[i];
            }
        }
    }
    
    else {
        if (numsA[i] % 2 ==0 ) {
            rightIndex = i + 1;
            leftIndex = i - 1;
            if (rightIndex <= counter) {
                if ((numsA[i] + numsA[rightIndex])% 2 != 0) {
                    numsB[i] = numsA[i] + numsA[rightIndex];
                }
                else {
                    numsA[i] = numsA[i] + numsA[rightIndex+1];
                }
            }
            else {
               if ((numsA[i] + numsA[leftIndex])% 2 != 0) {
                    numsB[i] = numsA[i] + numsA[leftIndex];
               }
               else {
                numsA[i] = numsA[i] + numsA[leftIndex-1];
               }
            }
        }
        else {
            numsB[i] = numsA[i];
        }
    }
    }
    numsA = numsB;
    string outputB = "";
    for (int ii=0; ii != counter; ii++) {
        outputB += to_string(numsA[ii])+ " ";
    }
    return outputB;
}

int main () {
    ifstream file("task3.txt"); 
    ofstream output("task3out.txt"); 

    int lengthOfA;
    file >> lengthOfA;
    int numsA[lengthOfA];

    vector<int> nums(lengthOfA); 
    for (int i = 0; i < lengthOfA; i++) {
        file >> nums[i];
        numsA[i] = nums[i];
    }

    output << lengthOfA << endl;
    output << creatingNumsB(lengthOfA, numsA)  << endl;
    file.close();
    output.close();
}

