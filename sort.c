#include <stdio.h>
#include <stdlib.h>
//-------------------------Insertion Sort-------------------------//
void SelectionSort(int a[], int n){
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++){
        min = i;
        for (j = i + 1; j < n; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
//-------------------------Bubble Sort-------------------------//
void BubbleSort(int a[], int n){
    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
//-------------------------Merge Sort-------------------------//
void Merge(int a[], int l, int m, int r){
    int i, j, k, n1 = m - l + 1, n2 = r - m, *L, *R;
    L = (int *)malloc(n1 * sizeof(int));
    R = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++){
        L[i] = a[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = a[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void MergeSort(int a[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}
//-------------------------Quick Sort-------------------------//
void partition(int a[], int l, int r, int *i, int *j){
    int pivot = a[r], temp;
    *i = l - 1;
    *j = r;
    while (1){
        do{
            (*i)++;
        } while (a[*i] < pivot);
        do{
            (*j)--;
        } while (a[*j] > pivot && *j > l);
        if (*i >= *j){
            break;
        }
        temp = a[*i];
        a[*i] = a[*j];
        a[*j] = temp;
    }
    temp = a[*i];
    a[*i] = a[r];
    a[r] = temp;
}
void QuickSort(int a[], int l, int r){
    int i, j;
    if (l < r){
        partition(a, l, r, &i, &j);
        QuickSort(a, l, j);
        QuickSort(a, i + 1, r);
    }
}
//-------------------------Insertion Sort-------------------------//
void InsertionSort(int a[], int n){
    int i, j, temp;
    for (i = 1; i < n; i++){
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
//-------------------------Heap Sort-------------------------//
void Heapify(int a[], int n, int i){
    int largest = i, l = 2 * i + 1, r = 2 * i + 2, temp;
    if (l < n && a[l] > a[largest]){
        largest = l;
    }
    if (r < n && a[r] > a[largest]){
        largest = r;
    }
    if (largest != i){
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        Heapify(a, n, largest);
    }
}
void HeapSort(int a[], int n){
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--){
        Heapify(a, n, i);
    }
    for (i = n - 1; i >= 0; i--){
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        Heapify(a, i, 0);
    }
}
int main(){
    int n, a[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    //SelectionSort(a, n);
    //BubbleSort(a, n);
    //MergeSort(a, 0, n - 1);
    //QuickSort(a, 0, n - 1);
    //InsertionSort(a, n);
    HeapSort(a, n);
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}