//By David Zárate López
//This program includes different sorting methods, such as:
//Last modification: 28/06/2021

#include <iostream>
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

void printList(int list[10]){
  for (int i = 0; i < 10 ; i++)
    cout<<list[i]<<" ";
  cout<<endl;
}

int main(){
    int list[10] = {9, 500, 1, 8, 4, 100, 99, 61, 40, 2};
    int list2[10] = {9, 500, 1, 8, 4, 100, 99, 61, 40, 2};
    int list3[10] = {9, 500, 1, 8, 4, 100, 99, 61, 40, 2};
    cout<<"Exchange Sort:"<<endl;
    printList(list);
    exchangeSort(list);
    printList(list);
    cout<<"Bubble Sort:"<<endl;
    printList(list2);
    bubbleSort(list2);
    printList(list2);
    cout<<"Selection Sort:"<<endl;
    printList(list3);
    selectionSort(list3);
    printList(list3);

}
