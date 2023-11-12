
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //beautification
    vector<string>h;
    string s,k;

    string word1, fname1 = "source_file.txt"; //source code file name
    ifstream MyReadFile1("source_file.txt");
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

    ofstream MyWriteFile("beautified_file.txt"); //after beautification code will be written in this file
    MyWriteFile<<k;
    MyWriteFile.close();
    //beautification end

    /*########################################################*/



    //tokenization
    string myText,h1, fname = "beautified_file.txt"; //source file
    ifstream MyReadFile("beautified_file.txt");
    ifstream file;
    file.open(fname.c_str());

    vector<string>keyword;
    vector<string>key;
    vector<string>identifier;
    vector<string>id;
    vector<string>constants;
    vector<string>cons;
    vector<string>punctuation;
    vector<string>punc;
    vector<string>oper;
    vector<string>oper1;
    vector<string>word;

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

        else if ((word[i][0] == '_') || (word[i][0] >= 'a' && word[i][0] <= 'z') || (word[i][0] >= 'A' && word[i][0] <= 'Z'))
        {
            identifier.push_back(word[i]);
        }



        //Operator
        string s2[14] = {"+","-","*","/","%","=","<",">","==","&&","||","!=",">=","<="};
        for(int j=0; j<9; j++)
        {
            if(word[i]==s2[j])
            {
                oper.push_back(word[i]);
            }
            else
            {
                continue;
            }
        }

        // Punctuation
        string ch[20] = {",",";",":",".","!","(",")","{","}","[","]"};

        for(int j=0; j<20; j++)
        {
            if(word[i]==ch[j])
            {
                punctuation.push_back(word[i]);
            }
            else
            {
                continue;
            }
        }

    }

    //printing keywords
    cout<<"These are the Keywords : "<<endl;
    for(int i=0;i<keyword.size();i++)
    {
        int l =0;
        for(int j =0; j<key.size();j++)
        {
            if(keyword[i]==key[j])
            {
                l++;
            }
            if(keyword[i]=="else"&&keyword[i+1]=="if")
            {
                string a = keyword[i]+" "+keyword[i+1];
                key.push_back(a);
                i++;
            }
        }
        if(l==0)
        {
            key.push_back(keyword[i]);
        }
    }
    for(int j =0; j<key.size();j++)
    {

        cout<<key[j]<<","<<" ";
    }
    cout<<endl<<endl;


    //printing operators
    cout<<"These are the Operator :"<<endl;
    for(int i=0;i<oper.size();i++)
    {
        int l =0;
        for(int j =0; j<oper1.size();j++)
        {
            if(oper[i]==oper1[j])
            {
                l++;
            }
        }
        if(l==0)
        {
            oper1.push_back(oper[i]);
        }
    }
    for(int j =0; j<oper1.size();j++)
    {

        cout<<oper1[j]<<","<<" ";
    }
    cout<<endl<<endl;

    //printing punctuations
    cout<<"These are the Punctuation: "<<endl;
    for(int i=0; i<punctuation.size();i++)
    {
        int l =0;
        for(int j =0; j<punc.size();j++)
        {
            if(punctuation[i]==punc[j])
            {
                l++;
            }
        }
        if(l==0)
        {
            punc.push_back(punctuation[i]);
        }
    }
    for(int j =0; j<punc.size();j++)
    {

        cout<<punc[j]<<" ";
    }
    cout<<endl<<endl;


    //printing identifiers
    cout<<"Identifiers:"<<endl;
    for(int i=0; i<identifier.size();i++)
    {
        int l =0;
        for(int j =0; j<id.size();j++)
        {
            if(identifier[i]==id[j])
            {
                l++;
            }
        }
        if(l==0)
        {
            id.push_back(identifier[i]);
        }
    }
    for(int j =0; j<id.size();j++)
    {

        cout<<id[j]<<","<<" ";
    }
    cout<<endl<<endl;

    //printing constants
    cout<<"Constants:"<<endl;
    for(int i=0; i<constants.size();i++)
    {
        int l =0;
        for(int j =0; j<cons.size();j++)
        {
            if(constants[i]==cons[j])
            {
                l++;
            }
        }
        if(l==0)
        {
            cons.push_back(constants[i]);
        }
    }
    for(int j =0; j<cons.size();j++)
    {

        cout<<cons[j]<<","<<" ";
    }


    file.close();
    cout<<endl;
}
