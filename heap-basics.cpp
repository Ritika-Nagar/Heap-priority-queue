#include <iostream>
using namespace std;

class heap {
    public:

    int arr[1000];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }


    void print(){
        
        for(int i=1; i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void insert(int val){
        
        size= size + 1;
        int indx=size;
        arr[indx]=val;

        while(indx>1){
            int parent =indx/2;
            if(arr[parent]<arr[indx]){
                swap(arr[parent], arr[indx]);
                indx=parent;
            }else{
                return;
            }

        }
    }

    void deleteFromHeap(){
        if(size==0){
            cout<<"np item to delete "<<endl;
        }

        arr[1]=arr[size];
        size--;// we have deleted that particular element 
        int i=1;

        while(i<size){
            int leftIndx= 2*i;
            int rightIndx=2*i+1;

            if(leftIndx<size && arr[leftIndx]>arr[i]){
                swap(arr[i],arr[leftIndx]);
                i=leftIndx;
            }else if(rightIndx<size && arr[rightIndx]>arr[i]){
                swap(arr[i],arr[rightIndx]);
                i=rightIndx;
            }else {
                return;
            }
        }
    }


    
    
};



void heapify(int arr[], int i ,int n){
    //cout<<"ander";
        int largest=i;// matlab largest element ynha par pada h 
        int leftIndx= 2*i;
        int rightIndx=2*i+1;

        if(leftIndx <= n && arr[largest]<arr[leftIndx]){
            largest=leftIndx;
        }
        if(rightIndx<= n && arr[largest]< arr[rightIndx]){
            largest=rightIndx;
        }

        if(largest!=i){
            swap(arr[largest],arr[i]);
             heapify(arr,largest,n);
        }

       

    }


void heapSort(int arr[], int n){
    int size=n;

    while(size>1){
        swap(arr[1], arr[size]);
        size--;

        heapify(arr,1,n);

    }
}
int main(){
    heap h;
    h.insert(67);
    h.insert(17);
    h.insert(07);
    h.insert(45);
    h.insert(6);
    h.deleteFromHeap();
    h.insert(7);
    h.insert(67);
    h.deleteFromHeap();
    // h.print();

    int arr[6]={-1, 54, 53, 55, 52, 50};

    //heap creation 
    for(int i=5/2; i>0; i--){
        //cout<<"///";
        heapify(arr,i,5);
    }

    //call heapsort
    heapSort(arr,5);
    for(int i=1;i<=5;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}
