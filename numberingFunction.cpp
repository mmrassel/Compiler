#include<bits/stdc++.h>
using namespace std;
int main()
{
    //beautification
    vector<string>h;
    string s,k;

    string word1, fname1 = "program.cpp"; //source code file name
    ifstream MyReadFile1(fname1);
    ifstream file1;
    file1.open(fname1.c_str());

    while(file1>>word1)
    {
        h.push_back(word1);
    }

    for(int i =0; i<h.size();i++)
    {
        s+=h[i]+" ";
    }

    for(int i =0; i<s.size();i++)
    {
        if(((s[i]=='<'&&s[i+1]=='<')||(s[i]=='>'&&s[i+1]=='>'))||(s[i]=='='&&s[i+1]=='=')||
           (s[i]=='&'&&s[i+1]=='&')||(s[i]=='|'&&s[i+1]=='|')||(s[i]=='!'&&s[i+1]=='=')||
           (s[i]=='<'&&s[i+1]=='=')||(s[i]=='<'&&s[i+1]=='='))
        {
            k=k+" "+s[i]+s[i+1]+" ";
            i++;
        }
        else if(s[i]=='#'||s[i]=='<'||s[i]=='>'||s[i]=='('||s[i]==')'||s[i]==','||s[i]==';'||
        s[i]==':'||s[i]=='?'||s[i]=='!'||s[i]=='='||s[i]=='-'||s[i]=='+'||s[i]=='*'||s[i]=='/'||
        s[i]=='%'||s[i]=='"'||s[i]=='{'||s[i]=='}'||s[i]=='['||s[i]==']' ||s[i]=='%')
        {
            k=k+" "+s[i]+" ";
        }
        else
            k+=s[i];
    }

    ofstream MyWriteFile("beautified_file2.txt"); //after beautification code will be written in this file
    MyWriteFile<<k;
    MyWriteFile.close();
    //beautification end

    /*########################################################*/

    //identifying user define function
    string myText,h1, fname = "beautified_file2.txt"; //source file
    ifstream MyReadFile("beautified_file2.txt");
    ifstream file;
    file.open(fname.c_str());

    vector<string>keyword;
    vector<string>key;
    vector<string>identifier;
    vector<string>constants;
    vector<string>word;
    vector<string>fun;

    while(file>>h1)
    {
        word.push_back(h1);
    }

    for(int i=0;i<word.size();i++)
    {
        // Keyword
        if(word[i] == "int" || word[i] == "iostream" || word[i] == "string" || word[i] == "char" ||
           word[i] == "float" || word[i] == "double" || word[i] == "bool" || word[i] == "using" ||
           word[i]=="namespace" || word[i] == "long" || word[i] == "bits" || word[i]=="stdc" ||
           word[i]=="std" || word[i]=="void" || word[i] == "continue" || word[i] == "break" ||
           word[i]=="cout" || word[i]=="cin" || word[i]=="else" || word[i]=="if" || word[i]=="return" ||
           word[i] == "include" || word[i]=="MOD" || word[i] =="define" || word[i] == "vector" || word[i] == "endl" )
        {
            keyword.push_back(word[i]);
        }

        //constant
        else if((word[i][0] >= '0' && word[i][0] <= '9'))
        {
            constants.push_back(word[i]);
        }

        else if(word[i]=="\"")
        {
            string a;
            while(word[i+1]!="\"")
            {
                a+=word[i+1]+" ";
                i++;
            }
            i++;
            constants.push_back(a);
        }

        //identifiers
        else if ((word[i][0] == '_') || (word[i][0] >= 'a' && word[i][0] <= 'z') || (word[i][0] >= 'A' && word[i][0] <= 'Z'))
        {
            if((word[i-1] == "int" || word[i-1] == "string" || word[i-1] == "char" ||
                word[i-1] == "float" || word[i-1] == "double" || word[i-1] == "bool")&&(word[i+1] == "(")&&(word[i]!="main"))
            {
                fun.push_back(word[i]); //user define functions identifing
            }
            identifier.push_back(word[i]);
        }

    }

    //printing user define function
    cout<<"User define Funtions are:"<<endl;
    for(int j =0; j<fun.size();j++)
    {
        cout<<"Funtion "<<j+1<<":  "<<fun[j]<<endl;
    }
    cout<<"Total number of the user define Funtions: "<<fun.size()<<endl;

    file.close();
    cout<<endl;
}
