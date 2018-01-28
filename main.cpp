#include <iostream>
#include<queue>
using namespace std;
class point
{
    int x;
    int y;
public:
    point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    int getX() const{
    return x;
    }
    int getY() const{
    return y;
    }
};
class MyComparartor
{
public:
    int operator() (const point &p1,const point &p2)
{
    return p1.getX()<p2.getX();
}
};
void showpq(priority_queue<point,vector<point>,MyComparartor> pq)
{
    while(!pq.empty())
    {
        point p=pq.top();
        cout<<p.getX()<<" "<<p.getY()<<",";
        pq.pop();
    }
    cout<<endl;
}
int main()
{
    priority_queue<point,vector<point>,MyComparartor> pq;
    pq.push(point(10,6));
    pq.push(point(30,3));
    pq.push(point(20,10));
    pq.push(point(5,2));
    pq.push(point(1,1));
    showpq(pq);
    cout<<pq.size()<<endl;
    cout<<pq.top().getX()<<" "<<pq.top().getY()<<endl;
    pq.pop();
    showpq(pq);
    return 0;
}
