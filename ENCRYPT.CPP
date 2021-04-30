#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<process.h>
using namespace std;
void encrypt();
void decrypt();
void start();
char fil[20],ch;
int choice,k;
char key[10],en[20];
int en_key;
int  main()
{
   start();
   return 0;
   getch();
}
void start(){
   int x;
   system("cls");
   cout << "\nPlease choose following options:\n";
   cout << "1 = Encrypt the file\n";
   cout << "2 = Decrypt the file\n";
   cin >> x;
   switch(x)
   {
     case 1:    encrypt();
				break;
     case 2: 	decrypt();
	 			break;
     default:
		cout<<"INVALID INPUT!!!!!";
   }
 }

void encrypt()
   { system("cls");
    cout<<"Which file you want to encrypt(file name with its extension)?\n";
    cin>>fil;
   cout<<"enter your encryption key\n";
   cin>>en_key;

   ifstream fin;
   fin.open(fil,ios::binary);
   ofstream f;
   f.open("source.txt",ios::binary);
   while(fin.get(ch)){
     ch=ch+en_key;
     f.put(ch);
	}

   fin.close();
   f.close();
   ofstream m;
   m.open(fil,ios::binary);
   m<<en_key;
   m<<" ";
   ifstream n;
   n.open("source.txt",ios::binary);
    while(n.get(ch))
	{
    m.put(ch);
	 }

   m.close();
   n.close();
   remove("source.txt");
   cout<<"FILE ENCRYPTED SUCCESSFULLY\n";
   cout<<"TO GO TO:\nPREVIOUS PAGE PRESS-1 \nEXIT PRESS-2\n";
   cin>>choice;
   if (choice==1)
      start();
   else
       exit(0);
			}

void decrypt(){
    char str[10];
    system("cls");
    cout << "Enter file name you want to open with their extension.\n";
    cin >> fil;
    cout<<"ENTER THE DECRYPTION KEY\n";
    cin>>en_key;
    ifstream f;
    f.open(fil);
    int i=0;
    while(f)
    {   f.get(ch);
        if(ch==' ')
            {break;}
    	str[i++]=ch;
	}
	f.close();
	k=atoi(str);
    if(en_key==k)
    	{
    int count = 0;
    int size = strlen(str);
    ifstream s;
    s.open(fil,ios::binary);
    s.seekg(size+1,ios::beg);
    ofstream d;
    d.open("source.txt",ios::binary);
    while(s.get(ch)){
        ch=ch-en_key;
        d.put(ch);
	 }

    s.close();
    d.close();
    ofstream y;
   y.open(fil,ios::binary);
   ifstream z;
   z.open("source.txt",ios::binary);
    while(z.get(ch))
	{
    y.put(ch);
	 }

   y.close();
   z.close();
   remove("source.txt");
   cout<<endl<<"FILE DECRYPTED SUCCESSFULLY\n";
   system(fil);
   cout<<"TO GO TO:\nPREVIOUS PAGE PRESS-1 \nEXIT PRESS-2";
   cin>>choice;
   if (choice==1)
      start();
   else
       exit(0);
   			}
   else
   {
   cout<<"ENCRYPTION KEY IS WRONG!!!!!\n";
   system(fil);
   cout<<"TO GO TO:\nPREVIOUS PAGE PRESS-1 \nEXIT PRESS-2";
   cin>>choice;
   if (choice==1)
      start();
   else
       exit(0);
    }
			}

