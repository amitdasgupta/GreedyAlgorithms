#include <iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/***************job scheduling problem
struct Job
{
    int start_time;
    int end_time;
};
int main()
{
    vector<Job> vector_;
    Job *array_;
    int n;
    cin>>n;
    array_=new Job[n];
    for(int i=0;i<n;i++)
        cin>>array_[i].start_time>>array_[i].end_time;
    sort(array_,array_+n,[](const Job &a,const Job &b)
         {
             return a.end_time<b.end_time;
         }
         );
    vector_.push_back(array_[0]);
    int last_time=array_[0].end_time;
    for(int i=1;i<n;i++)
    {
        if(array_[i].start_time>=last_time)
        {
            last_time=array_[i].end_time;
            vector_.push_back(array_[i]);
        }
    }
    cout<<"jobs selected are:"<<endl;
    for(auto it=vector_.begin();it!=vector_.end();it++)
        cout<<(*it).start_time<<" "<<(*it).end_time<<endl;
    delete[] array_;
}
*///////
/*****************fractional knapsack problem
struct Item
{
    int weight;
    int values;
};
int main()
{
    int n;
    cin>>n;
    Item *array_=new Item[n];
    for(int i=0;i<n;i++)
        cin>>array_[i].weight>>array_[i].values;
    sort(array_,array_+n,[](const Item &a,const Item &b)
         {
             return (a.values/a.weight)>(b.values/b.weight);
         }
         );
    for(int i=0;i<n;i++)
        cout<<array_[i].weight<<" "<<array_[i].values<<endl;
    int max_weight,max_profit=0;
    cout<<"enter the maximum weight"<<endl;
    cin>>max_weight;
    int i=0;
    while(i<n)
    {
        if(array_[i].weight<=max_weight)
        {
            max_profit+=array_[i].values;
            max_weight-=array_[i].weight;
            i++;
        }
        else
        {
            max_profit+=((array_[i].values)/(array_[i].weight))*max_weight;
            break;
        }
    }
    cout<<max_profit;
    delete[] array_;
}
*///////////////
/************finding number of railway platforms*/////////
struct Train{
int time;
int type;/*********1 for arrival and -1 for departure*///////////
};
void printTrain(Train* &array_,int n)
{
    for(int i=0;i<2*n;i++)
        cout<<array_[i].time<<" "<<array_[i].type<<endl;
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    Train* array_=new Train[2*n];
    cout<<"Arrival time"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>array_[i].time;
        array_[i].type=1;
    }
    cout<<"Departure time"<<endl;
    for(int i=n;i<2*n;i++)
    {
        cin>>array_[i].time;
        array_[i].type=-1;
    }
    sort(array_,array_+2*n,[](const Train &a,const Train &b)
         {
        if(a.time==b.time)
           return a.type<b.type;
        else
           return a.time<b.time;
         }
         );
    cout<<endl;
    printTrain(array_,n);
    int res=0,maxRes=0;
    for(int i=0;i<2*n;i++)
    {
        res+=array_[i].type;
        if(res>maxRes)
            maxRes=res;
    }
    cout<<maxRes;
    delete[] array_;
}
