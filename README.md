#include<bits/stdc++.h>

using namespace std;

string Transposition_encryption(string pass,string word);
string caesar_encryption(string pass,string word);

string abc(string pass,string toEncrypt);

int main()
{
    std::string word,password;
    getline(cin,word);
    cin>>password;
    string a=Transposition_encryption(password,word);
    string b=caesar_encryption(password,a);

    string c=abc(password,word);
    for(int i=0; i<c.size(); i++)
    {
        if(c[i]<=9) printf("ba%d",c[i]);
        else if(c[i]<=99) printf("a%d",c[i]);
        else printf("%d",c[i]);
    }

}

string Transposition_encryption(string pass,string word)
{

    int colam=word.size()/pass.size();
    int row=pass.size();
    if((word.size() % pass.size())!=0) colam++;

    ///declaire a suitable 2D array
    char arr[colam][row];
    char b[row*colam];
    ///inisilize array with '_'
    for(int i=0; i<colam; i++)
    {
        for(int j=0; j<row; j++)
        {
            arr[i][j]='`';
        }
    }

    ///set value in 2D array
    int in=0;
    for(int i=0; i<colam; i++)
    {
        for(int j=0; j<row; j++)
        {
            if(in>=word.size())
                break;
            arr[i][j]=word[in];
            in++;

        }
        if(in>=word.size())
            break;
    }

    ///print 2D array
    /* for(int i=0; i<colam; i++)
     {
         for(int j=0; j<row; j++)
         {
             cout<<arr[i][j]<<" ";
         }
         cout<<endl;
     }*/

    ///make  password lowercase
    for(int i=0; i<pass.size(); i++)
    {
        if(pass[i]>='A' && pass[i]<='Z')
            pass[i]+=32;
    }

    ///make password sorted
    char sor[row];
    for(int i=0; i<pass.size(); i++) sor[i]=pass[i];

    sort(sor,sor+row);

    //for(int i=0; i<pass.size(); i++) cout<<sor[i];


    ///find position of word in password
    bool mark[row]= {0};
    int pos[row]= {0};

    for(int i=0; i<row; i++)
    {
        char x=sor[i];
        for(int j=0; j<row; j++)
        {
            if(pass[j]==x && mark[j]==0)
            {
                pos[j]=i;
                mark[j]=1;
                break;
            }
        }
    }
    //for(int i=0; i<pass.size(); i++) cout<<pos[i];
    in=0;
    //cout<<endl;
    for(int i=0; i<pass.size(); i++)
    {
        int m=pos[i];
        for(int j=0; j<colam; j++)
        {
            b[in]=arr[j][m];
            in++;
        }

    }

    ///return value to the main function
    string c;
    for(int i=0; i<(row*colam); i++) c.push_back(b[i]);

    return c;

}


string caesar_encryption(string pass,string word)
{
    string r;
    int sum=0;
    for(int i=0; i<pass.size(); i++) sum+=(int)pass[i];
    sum=sum%4;
    if (sum==0) sum++;

    for(int i=0; i<word.size(); i++)
    {
        char m=word[i]+sum;
        r.push_back(m);
    }
    return r;
}


string abc(string pass,string toEncrypt)
{
    char key[pass.size()];
    for(int i=0; i<pass.size(); i++) key[i]=pass[i]; //Any chars will work, in an array of any size

    string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] =toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

    return output;
}
