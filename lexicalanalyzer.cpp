#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int match(char buffer[])
{
    char keys[32][10] = {"break","case","char","continue","do","double","else","float","for",
                         "if","int","return","switch","void","while"
                        };
    int i, flag = 0;
    for(i = 0; i < 32; ++i)
    {
        if(strcmp(keys[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    char ch, buffer[15],b[30], logical_op[] = "><",math_op[]="+-*/=",numer[]=".0123456789",other[]=",;\(){}[]'':";
    ifstream fin("input.txt");
    int mark[1000]= {0};
    int i,j=0,kc=0,ic=0,lc=0,mc=0,nc=0,oc=0,aaa=0;
    vector < string > k;
    vector<char>identifier;
    vector<char>logic;
    vector<char>math;
    vector<string>numeric;
    vector<char>others;
    if(!fin.is_open())
    {
        printf("error while opening the file\n");
        exit(0);
    }

    while(!fin.eof())
    {
        ch = fin.get();
        for(i = 0; i < 12; ++i)
        {
            if(ch == other[i])
            {
                int aa=ch;
                if(mark[aa]!=1)
                {
                    others.push_back(ch);
                    mark[aa]=1;
                    ++oc;
                }
            }
        }

        for(i = 0; i < 5; ++i)
        {
            if(ch == math_op[i])
            {
                int aa=ch;
                if(mark[aa]!=1)
                {
                    math.push_back(ch);
                    mark[aa]=1;
                    ++mc;
                }
            }
        }
        for(i = 0; i < 2; ++i)
        {
            if(ch == logical_op[i])
            {
                int aa=ch;
                if(mark[aa]!=1)
                {
                    logic.push_back(ch);
                    mark[aa]=1;
                    ++lc;
                }
            }
        }
        if(ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9' || ch=='.' ||ch == ' ' || ch == '\n' || ch == ';')
        {
            if(ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9' || ch=='.')b[aaa++]=ch;
            if((ch == ' ' || ch == '\n' || ch == ';') && (aaa != 0))
            {
                b[aaa] = '\0';
                aaa = 0;
                char arr[30];
                strcpy(arr,b);
                numeric.push_back(arr);
                ++nc;
            }
        }
        if(isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;
            if(match(buffer) == 1)
            {
                k.push_back(buffer);
                ++kc;
            }
            else
            {
                if(buffer[0]>=97 && buffer[0]<=122)
                {
                    if(mark[buffer[0]-'a']!=1)
                    {
                        identifier.push_back(buffer[0]);
                        ++ic;
                        mark[buffer[0]-'a']=1;
                    }
                }
            }
        }
    }

    fin.close();
    printf("keywords: ");
    for(int f=0; f<kc; ++f)
    {
        if(f==kc-1)
        {
            cout<<k[f]<<"\n";
        }
        else
        {
            cout<<k[f]<<", ";
        }
    }
    printf("Identifiers: ");
    for(int f=0; f<ic; ++f)
    {
        if(f==ic-1)
        {
            cout<<identifier[f]<<"\n";
        }
        else
        {
            cout<<identifier[f]<<", ";
        }
    }
    printf("Math Operators: ");
    for(int f=0; f<mc; ++f)
    {
        if(f==mc-1)
        {
            cout<<math[f]<<"\n";
        }
        else
        {
            cout<<math[f]<<", ";
        }
    }
    printf("Logical Operators: ");
    for(int f=0; f<lc; ++f)
    {
        if(f==lc-1)
        {
            cout<<logic[f]<<"\n";
        }
        else
        {
            cout<<logic[f]<<", ";
        }
    }
    printf("Numerical Values: ");
    for(int f=0; f<nc; ++f)
    {
        if(f==nc-1)
        {
            cout<<numeric[f]<<"\n";
        }
        else
        {
            cout<<numeric[f]<<", ";
        }
    }
    printf("Others: ");
    for(int f=0; f<oc; ++f)
    {
        if(f==oc-1)
        {
            cout<<others[f]<<"\n";
        }
        else
        {
            cout<<others[f]<<" ";
        }
    }
    return 0;
}
