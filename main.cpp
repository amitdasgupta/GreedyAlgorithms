#include <iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void printVector(vector<int> v)
{
    for_each(v.begin(),v.end(),[](int i)
             {
                 cout<<i<<" ";

             }
             );
    cout<<endl;
}
int main()
{
    vector<int> v{4, 1, 3, 5, 2, 3, 1, 7,5};
    printVector(v);
    auto it=find_if(v.begin(),v.end(),[](int i)
                    {
                        return i>4;
                    }
                    );
    sort(v.begin(),v.end(),[](const &a,const &b)->bool
         {
             return a>b;
         }
         );
    printVector(v);
    int count_5=count_if(v.begin(),v.end(),[](int a)
                         {

                             return a>=5;
                         }
                         );
     cout<<count_5<<endl;
     it=unique(v.begin(),v.end(),[](int a,int b)
     {
         return a==b;
     }
     );
     printVector(v);
     v.resize(distance(v.begin(),it));
     printVector(v);
     int arr[]={1,2,3,4,5,6,7,8,9,10};
     int f=accumulate(arr,arr+10,1,[](int i,int j)
                      {
                          return i*j;
                      }
                      );
      cout<<f;
}
