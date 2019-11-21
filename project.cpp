#include <bits/stdc++.h>

using namespace std;

char word[100000];
char password[11];

int main()
{
    cout<<"           ******encryption/Decryption System*******"<<endl;

    cout<<"                       marajul"<<endl;
    cout<<"   1.encryption (press 1)"<<endl;
    cout<<"   2.Decryption  (press 2)"<<endl;

    char first=getchar();
    if(first=='1')
    {
        cout<<"***Enter your text you want to encrypt:"<<endl;
        getchar();
        gets(word);
        //puts(word);
        cout<<"***Enter your password (please remember this):"<<endl;
        gets(password);

        int ln_pass=strlen(password);
        int ln_word=strlen(word);
        int size=ln_word/ln_pass;
        if(ln_word%ln_pass) size++;
        int in=0;

        ///Encryption
        char arr[size][ln_pass];
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<ln_pass; j++)
            {
                arr[i][j]='_';
            }
        }

        ///set

        for(int i=0; i<size; i++)
        {
            for(int j=0; j<ln_pass; j++)
            {
                //if(word[in]==' ') word[in]='$';
                arr[i][j]=word[in];
                in++;
                if(in>=ln_word)
                    break;
            }
            if(in>=ln_word)
                break;
        }

        ///print

        /*for(int i=0; i<size; i++)
        {
            for(int j=0; j<ln_pass; j++)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }*/

        ///make  password lowercase
        for(int i=0; i<ln_pass; i++)
        {
            if(password[i]>='A' && password[i]<='Z')
                password[i]+=32;
        }

        ///find position in password
        in=0;
        int pos[ln_pass];
        for(int i=0; i<ln_pass; i++)
        {
            int count=0;
            for(int j=0; j<ln_pass; j++)
            {
                if(password[i]>=password[j])
                    count++;
            }
            pos[in]=count;
            in++;
        }


        //for(int i=0; i<ln_pass; i++) cout<<pos[i]<<" ";


        ///Transposition_cipher

        char final[ln_word];
        in=0;

        for(int i=0; i<ln_pass; i++)
        {
            int m=pos[i];
            m--;
            for(int j=0; j<size; j++)
            {
                final[in]=arr[j][m];
                in++;
            }

        }
        char f2[10000];
        int sum=0;
        for(int i=0; i<ln_pass; i++) sum+=(int)password[i];
        sum=sum%4;
        if (sum==0) sum++;
        for(int i=0; i<ln_word; i++)
            f2[i]=final[i]+sum;

        ///print
        cout<<endl;
        cout<<"*****Encrypt Text*****"<<endl;
        for(int i=0; i<ln_word; i++) cout<<final[i];

        cout<<endl;
        for(int i=0; i<(size*ln_pass); i++) cout<<f2[i];


    }

    ///Decryption
    else if(first=='2')
    {

        gets(word);
        gets(password);

        int ln_pass=strlen(password);
        int ln_word=strlen(word);
        int size=ln_word/ln_pass;
        if(ln_word%ln_pass) size++;


    }

}





