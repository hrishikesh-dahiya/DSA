#include <iostream>
#include <vector>

using namespace std;

void minHeapify(int a[], int heap_size, int i)
{
    int least;
    int l = 2*i;
    int r = 2*i+1;

    if(l<heap_size && a[l] < a[i]){
        least = l;
    } else {
        least = i;
    }
    if(r<heap_size && a[r] < a[least]){
        least = r;
    }
    if(least != i){
        swap(a[i], a[least]);
        minHeapify(a, heap_size, least);
    }
}

int minHeap(int a[], int n)
{
    for(int i=n/2;i>0;i--){
        minHeapify(a, n, i);
    }
}

int main()
{
    int k, n;

    cin >> k >> n;

    int a[k+1][n+1];

    vector<pair<int,int>> heap;

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=1;i<=k;i++){
        heap.push_back(make_pair(a[i][1],i));
    }

    minHeap(heap, k);

    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            cout << heap[1] << " ";

            swap(heap[1], make_pair(a[j][i],j));
            minHeapify(heap, k, 1);
        }
    }

    cout << endl;

    return 0;
}
