// program 2.14
#include <iostream>
#include <conio.h>
using namespace std;

void fungsi_1();
void fungsi_2(int);
void fungsi_3(int);
void fungsi_4(int);
void fungsi_5(int);
void fungsi_6(int);
void fungsi_7(int);
void fungsi_8(int);

int main() {
    int choice;
    int input;
    cout << "Analysis the number of steps of algorithms \n\n";
    cout << "choose fungsi [1 - 8]: ";
    cin >> choice;
    if (choice == 1) {
        fungsi_1();
        cout << "\n";
    }
    else {
        cout << "Masukkan bil. input: ";
        cin >> input;
        switch (choice) {
            case 2:
            fungsi_2(input);
            break;
            case 3:
            fungsi_3(input);
            break;
            case 4:
            fungsi_4(input);
            break;
            case 5:
            fungsi_5(input);
            break;
            case 6:
            fungsi_6(input);
            break;
            case 7:
            fungsi_7(input);
            break;
            case 8:
            fungsi_8(input);
            break;
        }
    }
    getch();
    return 0;
}

void fungsi_1() {
    int counter = 1;
    cout << "Arahan cout kali ke " << counter << "\n";
}

void fungsi_2(int n) {
    int counter = 1;
    int i = 0;
    for (i = 1; i <= n; i++) {
        cout << "Arahan cout kali ke " << counter << "\n";
        counter++;
    }
}
void fungsi_3(int n) {
    int counter = 1;
    int i = 0;
    int j = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout <<"Arahan cout kali ke " <<counter<< "\n";
            counter++;
        }
    }
}
void fungsi_4(int n) {
    int counter = 1;
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                cout << "Arahan cout kali ke " << counter << "\n";
                counter++;
            }
        }
    }
}

void fungsi_5(int n) {
    int counter = 1;
    int i = 0;
    for (i = 2; i <= n; i = i * 2) {
        cout << "Arahan cout kali ke " << counter << "\n";
        counter++;
    }
}

void fungsi_6(int n) {
    int counter = 1;
    int i = 0;
    for (i = 2; i <= n; i = i * 4) {
        cout << "Arahan cout kali ke " << counter << "\n";
        counter++;
    }
}

void fungsi_7(int n) {
    int counter = 1;
    int i = 0;
    int j = 0;
    for (i = 2; i <= n; i = i * 2) {
        j = 1;
        while (j <= n) {
            cout << "Arahan cout kali ke "<<counter << "\n";
            counter++;
            j++;
        }
    }
}

void fungsi_8(int n) {
    int counter = 1;
    int i = 1;
    int j = 1;
    while (i <= n) {
        j = j * 2;
        i++;
    }
    for (i = 1; i <= j; i++) {
        cout <<"Arahan cout kali ke " << counter << "\n";
        counter++;
    }
}
