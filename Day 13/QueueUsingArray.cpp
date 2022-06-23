#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
};

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

void MyQueue :: push(int x)
{
   arr[rear++] = x;
}

int MyQueue :: pop()
{
   if(rear==front)
   {
       return -1;
   }
   return arr[front++];
}