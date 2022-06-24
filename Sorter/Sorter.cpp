#include <iostream>
#include <algorithm>
using namespace std;

template  <typename T>
class Sorter
{
private:
    static void swap(T* xp, T* yp)
    {
        T temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
public:
    static void BubbleSort(T data[], int lenD)
    {
        T tmp = 0;
        for (int i = 0; i < lenD; i++) {
            for (int j = (lenD - 1); j >= (i + 1); j--) {
                if (data[j] < data[j - 1]) {
                    tmp = data[j];
                    data[j] = data[j - 1];
                    data[j - 1] = tmp;
                }
            }
        }
        cout << "BubbleSort" << "\n";
    }
    static void SelectionSort(T arr[], int n)
    {
        cout << "SelectionSort" << "\n";
        int i, j, min_idx;

        for (i = 0; i < n - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                {
                    min_idx = j;
                    swap(&arr[min_idx], &arr[i]);
                }
        }
    }
    static void InsertionSort(T data[], int lenD)
    {
        cout << "InsertionSort" << "\n";
        T key = 0;
        int i = 0;
        for (int j = 1; j < lenD; j++) {
            key = data[j];
            i = j - 1;
            while (i >= 0 && data[i] > key) {
                data[i + 1] = data[i];
                i = i - 1;
                data[i + 1] = key;
            }
        }
    }
    static void QuickSort(T* data, int const len)
    {
        cout << "QuickSort" << "\n";
        int const lenD = len;
        int pivot = 0;
        int ind = lenD / 2;
        int i, j = 0, k = 0;
        if (lenD > 1) {
            int* L = new int[lenD];
            int* R = new int[lenD];
            pivot = data[ind];
            for (i = 0;i < lenD;i++) {
                if (i != ind) {
                    if (data[i] < pivot) {
                        L[j] = data[i];
                        j++;
                    }
                    else {
                        R[k] = data[i];
                        k++;
                    }
                }
            }
            QuickSort(L, j);
            QuickSort(R, k);
            for (int cnt = 0;cnt < lenD;cnt++) {
                if (cnt < j) {
                    data[cnt] = L[cnt];;
                }
                else if (cnt == j) {
                    data[cnt] = pivot;
                }
                else {
                    data[cnt] = R[cnt - (j + 1)];
                }
            }
        }
    }
};

int main()
{
    Sorter();
    Sorter<int>::BubbleSort;
    Sorter<int>::InsertionSort;
    Sorter<int>::QuickSort;
    Sorter<int>::SelectionSort;
}