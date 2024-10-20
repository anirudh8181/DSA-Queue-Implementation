#include<bits/stdc++.h>
using namespace std;

class Queue
{
  public:

  int *arr;
  int cursize;
  int maxSize;
  int start;
  int end;
 

  Queue()
  {
    arr=new int[10];
    start=-1;
    end=-1;
    cursize=0;
     //no elements in the queue initially

  }

  // Constructor with custom size

   Queue(int maxSize)
  {
      this->maxSize = maxSize;  // Set custom maximum size
      arr = new int[maxSize];   // Dynamically allocate array with maxSize
      start = -1;
      end = -1;
      cursize = 0;
    }


  
 //push operation
 int push(int x)
 {  //if queue full.... edge case
    if(cursize==maxSize) 
    {
         cout<<"Queue is full"<<endl;
         exit(1);
    }
 //if queue is empty ....edgecase
    if(end==-1)
    {
        start=0;
        end=0;
    }
    else
    {
       end=(end+1)%maxSize; //cirular queue technique 
    }

    arr[end]=x;
    cout<<"The element pushed is "<<x<<endl;
    cursize++;
    
 } 


//pop operation
int  pop()
{
 if(start==-1)
 {
    cout<<"Queue is empty"<<endl;
    exit(1);
 }
 int popped=arr[start];
 if(cursize==1)  // Queue will become empty after this pop
 {
   start=-1;
   end=-1;
 }
 else
 {
    start=(start+1)%maxSize;

 }
 cursize--;
 return popped;
}
 
//top operation
int top()
{
    if(start==-1)
    {
        cout<<"Queue is empty"<<endl;
        exit(1);
    }
    return arr[start];
} 

//size of Queue
int size()
{
    return cursize;
}

};

int main()
{

 Queue q(6);
  q.push(4);                 // Push 4 into the queue
  q.push(14);                // Push 14 into the queue
  q.push(24);                // Push 24 into the queue
  q.push(34);                // Push 34 into the queue
  
  // Display the top element and size before any deletion
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion "<< q.size() << endl;

  // Pop the front element and display it
  cout << "The first element to be deleted " << q.pop() << endl;

  // Display the top element and size after deletion
  cout << "The peek of the queue after deleting an element "<< q.top() << endl;
  cout << "The size of the queue after deleting an element "<< q.size() << endl;

  return 0;

}



