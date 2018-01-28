#include <iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/***************job scheduling problem*///////
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

}
