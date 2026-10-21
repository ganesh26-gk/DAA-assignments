#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <vector> 
using namespace std; 

struct Record { 
    string id; 
    string name; 
    string timestamp; 
}; 

// Merge function 
void merge(vector<Record> &arr, int left, int mid, int right) { 
    vector<Record> temp; 

    int i = left; 
    int j = mid + 1; 

    while (i <= mid && j <= right) { 
        if (arr[i].timestamp <= arr[j].timestamp) { 
            temp.push_back(arr[i++]); 
        } else { 
            temp.push_back(arr[j++]); 
        } 
    } 

    while (i <= mid) 
        temp.push_back(arr[i++]); 

    while (j <= right) 
        temp.push_back(arr[j++]); 

    for (int k = left; k <= right; k++) 
        arr[k] = temp[k - left]; 
} 

// Merge Sort 
void mergeSort(vector<Record> &arr, int left, int right) { 
    if (left >= right) 
        return; 

    int mid = (left + right) / 2; 
    mergeSort(arr, left, mid); 
    mergeSort(arr, mid + 1, right); 

    merge(arr, left, mid, right); 
} 
int main() { 
    vector<Record> data; 

    ifstream file("test.csv");   // CSV file should be in the same folder 
    string line; 
 getline(file, line); // Skip header 

    while (getline(file, line)) { 
        stringstream ss(line); 
        Record r; 

        getline(ss, r.id, ','); 
        getline(ss, r.name, ','); 
        getline(ss, r.timestamp); 

        data.push_back(r); 
    } 

    file.close(); 

    mergeSort(data, 0, data.size() - 1); 

    cout << "Sorted Data:\n"; 
    for (const auto &r : data) { 
        cout << r.id << " " << r.name << " " << r.timestamp << endl; 
    } 

    return 0; 
}
