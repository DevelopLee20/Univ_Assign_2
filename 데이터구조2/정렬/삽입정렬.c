#include <stdio.h>

void insertion_sort(int list[], int n){
    int j, key;

    for(int i=1; i<n; i++){
        key = list[i];
        
        for(j=i-1; j>=0 && list[j]>key; j--){
            list[j+1] = list[j];
        }
        list[j+1] = key;
    }
}