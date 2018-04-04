#include <iostream>
#include <algorithm>

using namespace std;

void print_array(int a[], int length_a){

    cout<<"[";
    for(int i=0;i<length_a;i++){
        cout<<a[i]<<", ";
    }
    cout<<"]\n\n";
}

int main(){

    int a[] = {5, 5, 6, 3, 8, 3, 1, 10, 2, 4, 2};

    int length_a = sizeof(a)/sizeof(a[0]);

    cout<<"\nThe array before sorting is : \n";
    print_array(a, length_a);


    sort(a, a + length_a);

    cout<<"\nThe array after sorting is : \n";
    print_array(a, length_a);

}
