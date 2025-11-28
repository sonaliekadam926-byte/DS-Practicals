#include <iostream>
using namespace std;

int stringLength(char str[]) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void stringCopy(char src[], char dest[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void stringReverse(char str[], char rev[]) {
    int len = stringLength(str);
    for (int i = 0; i < len; i++)
        rev[i] = str[len - i - 1];
    rev[len] = '\0';
}

void stringConcat(char s1[], char s2[], char result[]) {
    int i = 0, j = 0;

    while (s1[i] != '\0') {
        result[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0') {
        result[i] = s2[j];
        i++;
        j++;
    }
    result[i] = '\0';
}

int main() {
    char str1[100], str2[100], result[200];
    int choice;

    cout << "\nEnter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Length of String 1\n";
        cout << "2. Copy String 1 into another\n";
        cout << "3. Reverse String 1\n";
        cout << "4. Concatenate String1 + String2\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Length = " << stringLength(str1) << endl;
            break;

        case 2:
            stringCopy(str1, result);
            cout << "Original String: " << str1 << endl;
            cout << "Copied String:   " << result << endl;
            break;

        case 3:
            stringReverse(str1, result);
            cout << "Reversed String: " << result << endl;
            break;

        case 4:
            stringConcat(str1, str2, result);
            cout << "Concatenated String: " << result << endl;
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}

