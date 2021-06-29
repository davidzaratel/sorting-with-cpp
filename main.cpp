//By David Zárate López
//This program includes different sorting methods, such as:
//Last modification: 28/06/2021

#include <iostream>
#include <vector>
using namespace std;

//Complexity: O(n^2)
void exchangeSort(int list[10]){
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      //if the number that's currently comparing itself with the others is bigger than the ones to the right it will switch possitions
      if (list[i] > list[j]) {
        int aux = 0;
        aux = list[i];
        list[i] = list[j];
        list[j] = aux;
      }
    }
  }
}

//Complexity O(n) best case and O(n^2) in worst cases
void bubbleSort(int list[10]){
  bool flag = true;
  //this for will execute n-1 times, being n the size of the array and it will only repeat if there's an exchange of places
  //if there isn't it will mean that the array is already sorted
  for (int i = 0; i < 9 && flag; i++) {
    flag = false;
    //this for will execute n-1-i times, being n the size of the array and i the number of repetitions.
    //that will mean that every time that the first for repeats, the comparisons will be less
    for (int j = 0 ; j < 9 - i; j++) {
      if (list[j+1] < list[j]) {
        int aux;
        aux = list[j+1];
        list[j+1] = list[j];
        list[j] = aux;
        flag = true;
      }
    }
  }
}

//Complexity: O(n)
//This algorithm selects the smallest number and then puts it in the first possition, the values that are arranged don't count in the next iterations
void selectionSort(int list[10]){
  int min = 0;
  int smallindex = 0;
  int aux = 0;
  for (int i = 0; i < 9; i++) {
    smallindex = i;
    for (int j = i+1; j < 10; j++) {
      //if the number in the position j is smaller than the max number, the max number will change
      if (list[j] < list[smallindex])
        smallindex = j;
    }
    //if the number in the position i is the smallest, there won't be any change
    if (i != smallindex) {
      aux = list[i];
      list[i] = list[smallindex];
      list[smallindex] = aux;
    }

  }
}

//Complexity: O(n^2)
// insertionSort compares each value with its predecesors, if they are bigger than the number that is currently comparing, it exchanges it until the predecesors aren't bigger.
void insertionSort(int list[10]){
  //the first for will iterate forward, to all of the elements of the array
  for (int i = 1; i < 10; i++) {
    //the second for will iterate backwards, to compare the element with it's predecesors
    for (int j = i; j > 0; j--) {
      //if the current element is smaller than its predecesor then, they will change places.
      if (list[j-1] > list[j]) {
        int aux;
        aux = list[j-1];
        list[j-1] = list[j];
        list[j] = aux;
      }
    }
  }
}

//Complexity: O(n)
//Prints all the elements of the array
void printArray(int list[10]){
  for (int i = 0; i < 10 ; i++)
    cout<<list[i]<<" ";
  cout<<endl;
}

//Complexity: O(n)
//Prints all the elements of the array
void printVector(vector<int> list){
  for (int i = 0; i < 10 ; i++)
    cout<<list[i]<<" ";
  cout<<endl;
}

//Secondary function of mergeSort, it compares the values of the subarrays to sort them
void merge(vector<int> &list, int start, int mid, int end){
  //temporal array
  int temp[end - start + 1];
  int i = start, j = mid + 1, k = 0;

  // traverse both arrays and in each iteration add smaller of both elements in temp
  while(i <= mid && j <= end) {
    //if the element in position i (left) is smaller than the one in the position j,
		if(list[i] <= list[j]) {
			temp[k] = list[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = list[j];
			k += 1; j += 1;
		}
	}
  // add elements left in the first interval
	while(i <= mid) {
		temp[k] = list[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval
	while(j <= end) {
		temp[k] = list[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for(i = start; i <= end; i += 1) {
		list[i] = temp[i - start];
	}

}

//Primary function of mergeSort, it divides the array in smaller ones
//The start and end variables are the indexes of the smaller arrays, where they begin and finish
void mergeSort(vector<int> &list, int start, int end){
  if(start < end){
    int mid = (start + end)/2;
    mergeSort(list,start,mid);
    mergeSort(list,mid+1,end);
    merge(list,start,mid,end);
  }
}

int main(){
    int list[10] = {9, 500, 1, 8, 4, 100, 99, 61, 40, 2};
    int list2[10] = {9, 500, 1, 8, 4, 100, 99, 61, 40, 2};
    int list3[10] = {9, 500, 1, 8, 4, 100, 99, 61, 40, 2};
    int list4[10] = {9, 500, 1, 8, 4, 100, 99, 61, 40, 2};
    vector<int> list5 = {9, 500, 1, 8, 4, 100, 99, 61, 40, 2};
    cout<<endl;
    cout<<"Exchange Sort:"<<endl;
    cout<<"List Before:"<<endl;
    printArray(list);
    exchangeSort(list);
    cout<<"List After:"<<endl;
    printArray(list);
    cout<<endl;
    cout<<"Bubble Sort:"<<endl;
    cout<<"List Before:"<<endl;
    printArray(list2);
    bubbleSort(list2);
    cout<<"List After:"<<endl;
    printArray(list2);
    cout<<endl;
    cout<<"Selection Sort:"<<endl;
    cout<<"List Before:"<<endl;
    printArray(list3);
    selectionSort(list3);
    cout<<"List After:"<<endl;
    printArray(list3);
    cout<<endl;
    cout<<"Insertion Sort:"<<endl;
    cout<<"List Before:"<<endl;
    printArray(list4);
    insertionSort(list4);
    cout<<"List After:"<<endl;
    printArray(list4);
    cout<<endl;
    cout<<"Merge Sort:"<<endl;
    cout<<"List Before:"<<endl;
    printVector(list5);
    mergeSort(list5,0,10);
    cout<<"List After:"<<endl;
    printVector(list5);
    cout<<endl;


}
