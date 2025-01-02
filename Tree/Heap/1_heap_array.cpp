#include<iostream>
using namespace std;
void print_heap(int* arr, int size, int pos ,string pre){
    if(pos>=size) return;
    print_heap(arr,size,2*pos+1,pre+"\t");
    cout<<pre<<arr[pos]<<endl;
    print_heap(arr,size,2*pos+2,pre+"\t");
}
void build_max_heap(int* arr, int size, int parent){
    if(parent<0) return; //stop after parent is root
    int left=parent*2+1, right=parent*2+2;
    if(arr[parent]<arr[left] && (arr[left]>arr[right]||right>=size) && left<size){
        swap(arr[parent],arr[left]);
        build_max_heap(arr,size,left);//check if left subtree is still corrected after swapping
    }else if(arr[parent]<arr[right] && right<size){
        swap(arr[parent],arr[right]);
        build_max_heap(arr,size,right);//check if right subtree is still corrected after swapping
    }
    build_max_heap(arr,size,parent-1);//go to next subtree
}
void heapify(int* arr, int size, int parent){
    int left=parent*2+1, right=parent*2+2;
    if(arr[parent]<arr[left] && (arr[left]>arr[right]||right>=size) && left<size){
        swap(arr[parent],arr[left]);
        heapify(arr,size,left);//check if left subtree is still corrected after swapping
    }else if(arr[parent]<arr[right] && right<size){
        swap(arr[parent],arr[right]);
        heapify(arr,size,right);//check if right subtree is still corrected after swapping
    }
}
void remove(int* arr, int* size, int pos){
    swap(arr[pos],arr[*size-1]);
    *size=*size-1;
    heapify(arr,*size, pos);
}
void insert(int* arr, int* size, int val){
    *size=*size+1;
    arr[*size-1]=val;
    build_max_heap(arr,*size, (*size-1)/2);
}
int main(){
    int arr[8]={1,4,2,7,5,6,3,8}, size=8;//unsorted
    print_heap(arr,size,0,"");
    build_max_heap(arr,size,(size-1)/2);
    remove(arr,&size,2);
    print_heap(arr,size,0,"");
    insert(arr,&size, 15);
    print_heap(arr,size,0,"");
    return 0;
}