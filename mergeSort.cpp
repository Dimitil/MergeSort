#include <iostream>

void merge(int* ar, int first, int mid, int last){
    int n2=last-mid;
    int n1=mid-first+1;

    int left[n1];
    int right[n2];

    for(int i=0; i<n1; i++)
    {
        left[i]=ar[first+i];
    }

    for(int i=0; i<n2; i++){
        right[i]=ar[mid+1+i];
    }

    int leftIter=0, rightIter=0;

    int resIter=first;

    for(;leftIter<n1 && rightIter<n2; resIter++){
        if(left[leftIter]<right[rightIter]){
            ar[resIter]=left[leftIter];
            leftIter++;
        }
        else{
            ar[resIter]=right[rightIter];
            rightIter++;
        }
    }

    while(leftIter<n1){
        ar[resIter]=left[leftIter];
        resIter++;
        leftIter++;
    }

    while(rightIter<n2){
        ar[resIter]=right[rightIter];
        resIter++;
        rightIter++;
    }
}

void mergeSort(int* ar, int first, int last){
    int mid;
    if(first<last)
    {
        mid=(last+first)/2;
        mergeSort(ar, first, mid);
        mergeSort(ar, mid+1, last);
        merge(ar, first, mid, last);
    }
}

int main()
{

    int ar1[]= {5, 2, 15, 634, 12, 740};
    mergeSort(ar1, 0, 5);
    
    for(int i=0; i<6; i++){
       std::cout<<ar1[i]<<'\n';
    }
}
