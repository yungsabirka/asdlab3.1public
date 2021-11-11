#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void bulb(int arr[], int size);

int lin_sorting(const int arr[], int size, int required_number);

int BinarySearch(const int arr[], int, int);
bool expertise(const int arr[], int);

int main() {
    srand(time(0));
    int temp, size = 1000;
    int arr[size];
    for (int i = 0; i <= size; ++i) {
        temp = rand() % 4000-2000;
        arr[i] = temp;
    }
    bulb(arr, size);
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ") " << arr[i] << endl;
    }
    int required_number;
    cout << "enter required number= ";
    cin >> required_number;
    clock_t lin_startTime = clock();
    for (int i = 0; i < 100000; ++i) {
        int rn = rand() % 4000-2000;
        lin_sorting(arr, size, rn);
    }
    cout << "your number using linear sort:" << lin_sorting(arr, size, required_number) << endl;
    clock_t lin_endTime = clock();
    double lin_seconds = (double(lin_endTime - lin_startTime)) / CLOCKS_PER_SEC;
    clock_t BS_startTime = clock();
    for (int i = 0; i < 100000; ++i) {
        int rn = rand() % 4000-2000;
        BinarySearch(arr, size, rn);
    }
    cout << "your number using binary search:" << BinarySearch(arr, size, required_number) << endl;
    clock_t BS_endTime = clock();
    double BS_seconds = (double(BS_endTime - BS_startTime)) / CLOCKS_PER_SEC;
    cout << "linear sort time for 100001 repetitions= " << setprecision(10) << lin_seconds << endl;
    cout << "binary search time 100001 repetitions= " << setprecision(10) << BS_seconds << endl;
    if(expertise(arr,size))
        cout << "result comparison binary search and linear sort for 1000 options is true";
    else
        cout << "result comparison binary search and linear sort for 1000 options is false";
    return 0;
}

void bulb(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        bool exit = true;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                exit = false;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if(exit)
            return;
    }
}

int lin_sorting(const int arr[], int size, int required_number) {
        for (int i = size - 1; i >= 0; i--) {
            if (arr[i] == required_number)
                return i + 1;
        }
    return -1;
}

int BinarySearch(const int arr[], int size, int required_number) {
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] > required_number)
            high = mid - 1;
        else if (arr[mid] < required_number)
            low = mid + 1;
        else
            return mid + 1;
    }
    return -1;
}
bool expertise(const int arr[], int size){
    for (int i = 0; i < 1000; ++i) {
        int rn = rand() % 4000-2000;
        if (arr[BinarySearch(arr, size, rn)-1] != arr[lin_sorting(arr, size, rn)-1])
            return false;
    }
    return true;
}