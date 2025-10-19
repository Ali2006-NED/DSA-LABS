#include <iostream>
using namespace std;

void FindNumberFrequency(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty.";
        return;
    }

    bool visited[100] = {false}; //visited[5] = {false,false,false,false,false}  (arr = 2,3,2,4,3)

    for (int i = 0; i < size; i++) {
        if (visited[i]) continue; //visited[0] = false //visited[1] = false  visited[2] = true

        int count = 1; 
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {//2==3 FALSE 2==2 TRUE 2==4 FALSE 2==3 FALSE    3==2 FALSE 3==4 FALSE 3==3 TRUE 
                visited[j] = true;//visited[5] = {false,false,true,false,false} visited[5] = {false,false,true,false,true}
                count++; //count = 2 count = 2
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
