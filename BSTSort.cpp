#include<iostream>
#include<cstdlib>
#include"BST.cpp"
using namespace std;

//helper function for swapping values
void swap (int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

//creates a random permutation of an array
void randomPermutation(int *arr, int n){
    int j, i;
    for (j=n-1; j>0; j--){
        i = rand() % n; //chose another index without restrictions so all permutations are equally likely to occur
        swap(arr[j], arr[i]);}
}

//main BST sort algorithm
void BSTSort(int *arr, int n){
    //initialize tree
    BST<int> tree;

    //create a permutation of the array
    randomPermutation(arr, n);

    cout<<"Permutation of the input: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //insert the values of the permutation into the tree
    for(int i=0; i<n; i++){
        tree.insert(arr[i]);
    }

    //printing sorted array
    cout<<"Sorted output: ";
    tree.printInorder();
}

//requesting user to input data & calling BSTSort
int main(){
    int inputSize = 0;
    int data;
    int *inputArray;

    cout<<"Enter the number of integers to be sorted: "<<endl;
    cin>>inputSize;
    inputArray = new int[inputSize];

    for(int i=0; i<inputSize; i++){
        cout<<"Enter an integer: "<<endl;
        cin>>data;
        inputArray[i] = data;
    }

    BSTSort(inputArray, inputSize);

    delete [] inputArray;
}

