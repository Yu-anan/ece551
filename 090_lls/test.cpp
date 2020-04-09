#include "ll.h"
#include <cstdio>
#include <cstdlib>
#include<iostream>
using namespace std;
int main(void) {
  LinkedList<int> l;
  l.addFront(1);
  l.addFront(2);
  l.addBack(3);
  l.addBack(4);
  
  //2 1 3 4
  assert(l[0]==2);
  assert(l[1]==1);
  assert(l[2]==3);
  bool a = l.remove(3);
  //2 1 4
  assert(a==true);
  assert(l[2]==4);
  assert(l.find(4) == 2);
  assert(l.find(5) == -1);
   for(int i = 0; i < 3; i ++) {
    cout << l[i] << endl;
    //assert(l1[i] == l[i]);                                                    
  }
  LinkedList<int> l1(l);
   

     assert(l1[0] == 2);
  assert(l1[1] == 1);
  assert(l1[2] == 4);
  l.addBack(5);
  //2 1 4 5
  l1 = l;
  for(int i = 0; i < 4; i ++) {
    cout << l1[i] << endl;
    //assert(l1[i] == l[i]);
  }
  cout << "woo" << endl;



  
  return EXIT_SUCCESS;
}
