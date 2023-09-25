//token categorization
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int count=0;

    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%'||s[i]=='=')
        {
            count++;
            cout<<"Operator"<<count<<": "<<s[i]<<endl;
        }
    }
}