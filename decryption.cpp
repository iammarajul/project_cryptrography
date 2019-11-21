#include<bits/stdc++.h>
using namespace std;

string caesar_decryption(string pass,string word);
string abcdy(string pass,string toEncrypt);
string Transposition_decryption(string pass,string word);


int main()
{


    system("COLOR FC");
    printf("                   $$$ Decryption System $$$\n");
    printf("                   ==========================\n\n");

    printf("                File Decryption[text file]  [press 1]\n");
    printf("                Text Decryption             [press 2]\n");
    printf("                    About                   [press 3]\n");
    char c1=getchar();

    if(c1=='2')
    {
        std::string word,password,input;
        system("cls");
        system("COLOR A0");
        printf("                   $$$ TEXT Encryption System $$$\n");
        printf("                   ===============================\n\n");

        printf("please input your text you want to encrypt:\n");
        printf("------------------------------------------\n");
        getchar();


        ///take input

        getline(cin,input);

        printf("\nPassword:\n");
        printf("-----------\n");

        cin>>password;

        for(int i=0; i<input.size(); i+=3)
        {
            if(input[i]=='b')
            {
                word.push_back(input[i+2]-'0');
                //cout<<input[i+2]<<" ";
            }
            else if( input[i]=='a')
            {
                int m=((input[i+1]-'0')*10)+((input[i+2]-'0')*1);
                word.push_back(m);
                //cout<<m<<" ";
            }
            else
            {
                int m=((input[i]-'0')*100)+((input[i+1]-'0')*10)+((input[i+2]-'0')*1);
                word.push_back(m);
                //cout<<m<<" ";
            }
        }
        string a,b,ci;
        a=abcdy(password,word);

        b=caesar_decryption(password,a);

        ci=Transposition_decryption(password,b);

        ///output
        system("cls");
        printf("                   $$$ OUTPUT TEXT $$$\n");
        printf("                   ===================\n\n");

        cout<<ci<<endl;

        printf("\n\n");
        printf("=====================================\n\n");

    }


}



string abcdy(string pass,string toEncrypt)
{
    char key[pass.size()];
    for(int i=0; i<pass.size(); i++) key[i]=pass[i]; //Any chars will work, in an array of any size

    string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] =toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

    return output;
}






string caesar_decryption(string pass,string word)
{
    string r;
    int sum=0;
    for(int i=0; i<pass.size(); i++) sum+=(int)pass[i];
    sum=sum%4;
    if (sum==0) sum++;

    for(int i=0; i<word.size(); i++)
    {
        char m=word[i]-sum;
        r.push_back(m);
    }
    return r;
}


string Transposition_decryption(string pass,string word)
{
    string des;
    int colam=word.size()/pass.size();
    int row=pass.size();
    if((word.size() % pass.size())!=0) colam++;

    ///declaire a suitable 2D array
    char arr[colam][row];


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
    //for(int i=0; i<pass.size(); i++) cout<<pos[i]<<" ";
    int in=0;
    cout<<endl;
    for(int i=0; i<pass.size(); i++)
    {
        int m=pos[i];
        for(int j=0; j<colam; j++)
        {
            arr[j][m]=word[in];
            in++;
        }

    }


    for(int i=0; i<colam; i++)
    {
        for(int j=0; j<row; j++)
        {
            if(arr[i][j]!='`')
                des.push_back(arr[i][j]);
        }
        //cout<<endl;
    }

    return des;
}


