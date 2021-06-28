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

void printList(int list[10]){
  for (int i = 0; i < 10 ; i++)
    cout<<list[i]<<" ";
  cout<<endl;
}

int main(){
    int list[10] = {9, 500, 1, 8, 4, 100, 99, 61, 40, 2};
    printList(list);
    exchangeSort(list);
    printList(list);

}
