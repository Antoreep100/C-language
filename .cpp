#include<iostream>
using namespace std;

const int n = 5;
const int m = 3;

int available[m] = {3, 2, 2};

int Max[n][m] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

int Allocation[n][m] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};

int need[n][m];

void calculateNeed() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}

bool isSafe() {
    int Work[m];
    bool Finish[n] = {0};
    int safeSequence[n];
    int counter = 0;
    bool found;

    for(int i = 0; i < m; i++) {
        Work[i] = available[i];
    }

    while (counter < n) {
        found = false;

        for (int i = 0; i < n; i++) {
            if (!Finish[i]) {
                bool possible = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > Work[j]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    for (int j = 0; j < m; j++) {
                        Work[j] += Allocation[i][j];
                    }
                    safeSequence[counter++] = i;
                    Finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "System is not in a safe state.\n";
            return false;
        }
    }

    cout << "System is in a safe state.\n";
    cout << "Safe sequence is: ";
    for (int i = 0; i < n; i++) {
        cout << "P" << safeSequence[i] << " ";
    }
    cout << endl;

    return true;
}

int main() {
    calculateNeed();
    isSafe();
    return 0;
}
