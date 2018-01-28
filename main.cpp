#include <iostream>
#include<queue>
#include<string>
using namespace std;
class HeapNode
{
public:
    char data;
    unsigned freq;
    HeapNode* left;
    HeapNode* right;
    HeapNode(char ch,int f)
    {
        data=ch;
        freq=f;
        left=NULL;
        right=NULL;
    }
};
class MyComparartor
{
public:
    int operator() ( HeapNode  *p1, HeapNode  *p2)
{
    return p1->freq>p2->freq;
}
};
void showpq(priority_queue<HeapNode*,vector<HeapNode*>,MyComparartor> pq)
{
    while(!pq.empty()){
        HeapNode *p=pq.top();
        cout<<p->data<<" "<<p->freq<<",";
        pq.pop();
    }
    cout<<endl;
}
void printProcessedCodes(HeapNode* h,string &s)
{

        if(!h->left&&!h->right)
        {
            cout<<h->data<<" : "<<s<<endl;
            return;
        }
    else
        {

            if(h->left)
            {
                s.push_back('0');
                printProcessedCodes(h->left,s);
                s.pop_back();
            }
            if(h->right)
            {
                s.push_back('1');
                printProcessedCodes(h->right,s);
                s.pop_back();
            }
            return;

        }


}
void inOrderTraversal(HeapNode* root)
{
    if(root)
    {

        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
    else
        return;
}
int main()
{
    priority_queue<HeapNode*,vector<HeapNode*>,MyComparartor> pq;
    int n,fr;
    char ch;
    cin>>n;
    int i=0;
    while(i<n)
    {
        cin>>ch>>fr;
        pq.push(new HeapNode(ch,fr));
        i++;
    }
    HeapNode *h3;
    while(!pq.empty())
    {
        HeapNode *h1=pq.top();
        pq.pop();
        HeapNode *h2=pq.top();
        pq.pop();
        h3=new HeapNode('@',h1->freq+h2->freq);
        if(h1->freq<h2->freq)
            {
                h3->left=h1;
                h3->right=h2;
            }
            else
            {
                h3->left=h2;
                h3->right=h1;
            }
        if(pq.empty())
            break;
        else
        pq.push(h3);
    }
    string s;
    printProcessedCodes(h3,s);
    return 0;
}
