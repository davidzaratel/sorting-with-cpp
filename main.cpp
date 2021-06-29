//By David Zárate López
//This program includes different sorting methods, such as:
//Last modification: 28/06/2021

#include <iostream>
#include <vector>
using namespace std;

//Complexity: O(n^2)
void exchangeSort(vector<int> &list, int n){
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
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
void bubbleSort(vector<int> &list, int n){
  bool flag = true;
  //this for will execute n-1 times, being n the size of the array and it will only repeat if there's an exchange of places
  //if there isn't it will mean that the array is already sorted
  for (int i = 0; i < n - 1 && flag; i++) {
    flag = false;
    //this for will execute n-1-i times, being n the size of the array and i the number of repetitions.
    //that will mean that every time that the first for repeats, the comparisons will be less
    for (int j = 0 ; j < n - 1 - i; j++) {
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
void selectionSort(vector<int> &list, int n){
  int min = 0;
  int smallindex = 0;
  int aux = 0;
  for (int i = 0; i < n - 1; i++) {
    smallindex = i;
    for (int j = i + 1; j < n; j++) {
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
void insertionSort(vector<int> &list, int n){
  //the first for will iterate forward, to all of the elements of the array
  for (int i = 1; i < n; i++) {
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
  for (int i = 0; i < list.size() ; i++)
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

    vector<int> list, finallist;
    int n = 0, m = 0, num = 0,index = 0;

    cout<<"Hello! Welcome to this Sorting program"<<endl;
    while(n != 6){
      cout<<endl;
      cout<<"Which option would you like to do?"<<endl;
      cout<<"1)Exchange Sort"<<endl;
      cout<<"2)Bubble Sort"<<endl;
      cout<<"3)Selection Sort"<<endl;
      cout<<"4)Insertion Sort"<<endl;
      cout<<"5)Merge Sort"<<endl;
      cout<<"6)Exit"<<endl;
      cin>>n;
      if (n != 6){
        cout<<"Great! How many numbers would you like to have in your list?"<<endl;
        cin>>m;
        index = m;
        cout<<"Ok! Please enter the numbers:"<<endl;
        while (m > 0) {
          cin>>num;
          list.push_back(num);
          m--;
        }
        if (n == 1){
          exchangeSort(list,index);
          cout<<endl;
          cout<<"This algorithm has a Complexity of: O(n^2)"<<endl;
        }
        if (n == 2){
          bubbleSort(list,index);
          cout<<endl;
          cout<<"This algorithm has a Complexity of: O(n^2) in worst cases and O(n) in best cases"<<endl;
        }
        if (n == 3){
          selectionSort(list,index);
          cout<<endl;
          cout<<"This algorithm has a Complexity of: O(n^2)"<<endl;
        }
        if (n == 4){
          insertionSort(list,index);
          cout<<endl;
          cout<<"This algorithm has a Complexity of: O(n^2)"<<endl;
        }
        if (n == 5){
          mergeSort(list,0,index);
          cout<<endl;
          cout<<"This algorithm has a Complexity of: O(nlog(n))"<<endl;
        }
      }
      if (n == 6)
        cout<<endl<<"Thank you for using this program, have a great day!"<<endl;
      printVector(list);

    }



}
