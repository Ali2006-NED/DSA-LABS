#include <iostream>
using namespace std;

void FindNumberFrequency(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty.";
        return;
    }

    bool visited[100] = {false};

    for (int i = 0; i < size; i++) {
        if (visited[i]) continue;

        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << "Number " << arr[i] << " occurs " << count << " times." << endl;
    }
}

int main() {
    int arr[8];
    cout << "Enter 8 integers: ";
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }
    FindNumberFrequency(arr, 8);
    return 0;
}
