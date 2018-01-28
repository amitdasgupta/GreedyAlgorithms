#include <iostream>
#include<queue>
using namespace std;
void showpq(priority_queue<int,vector<int>,greater<int>> pq)
{
      while(!pq.empty())
      {
          cout<<pq.top()<<" ";
          pq.pop();
      }
      cout<<endl;
}
int main()
{
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);
    showpq(pq);
    cout<<pq.size()<<endl;
    cout<<pq.top()<<endl;
    pq.pop();
    showpq(pq);
    return 0;
}
