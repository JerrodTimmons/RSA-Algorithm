#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<bitset>

/* hi im jerrod timmons and you're watching jack*ss.*/


using namespace std;

/********** PROTOTYPE FUNCTIONS ******************/

int prime(long int);
long int finde(long int, long int, long int, long int *, long int *);
long int findD(long int, long int);
void createValues(long int, long int, long int, long int *, long int, char *);
void encrypt(long int *, long int *, long int, char *);
/************ END PROTOTYPE FUNCTIONS ************/



/********** MAIN FUNCTION ***********************/

main()
{
 long int primeNumber, flag, p, q, i, phi, msg[100], n;
 char message[100];

 cout<<"Please enter a prime number: "<<endl;
 cin>>primeNumber;
 flag = prime(primeNumber);
 if (flag == 0)
   {
   cout<<"You failed to enter a valid value"<<endl;
   cout<<"Exitting..."<<endl;
   exit(1);
  }
 else
  p = primeNumber;

 cout<<"Please enter your second prime number: "<<endl;
 cin>>primeNumber;
 flag = prime(primeNumber);
 if (flag == 0)
   {
   cout<<"You failed to enter a valid value"<<endl;
   cout<<"Exitting..."<<endl;
   exit(1);
  }
 else
  q = primeNumber;

 cout<<"Please enter your plain text: "<<endl;
 fflush(stdin);
 cin>>message;

 for (i = 0; message[i] != NULL; i++)
    {
     msg[i] = message[i];
    }
 n = p * q;
 phi = (p-1) * (q-1);
 cout<<"Your key is: "<<phi<<endl;

 createValues(phi, p, q, msg, n, message);

 cout<<endl<<"This is the end of the program."<<endl;

}

/********** END MAIN FUNCTION *******************/

/********** ENCRYPTION FUNCTION *****************/

void encrypt(long int *message, long int *e, long int mod, char **messageChar)
{
  long int length, k, plainText, cipherText, key = e[0], temp[100], en[100];
  int i, j;
 cout<<"This is the value of E: "<<key<<endl;
 length = strlen(*messageChar);
 cout<<"This is the size of your text: "<<length<<endl;
 cout<<"This is mod value: "<<mod<<endl;
 i = 0;

 while (i != length)
      {
       plainText = message[i];
       cout<<"This is the plain text before the for loop: "<<plainText<<endl;
       k = 1;

           cout<<plainText<<"^"<<key<<"= ";
	   k = pow(plainText,key);
           cout<<endl<<"This is k before you mod: "<<k<<endl;
           k = k % mod;
       en[i] = k;
       i++;
       }
       en[i] = -1;

 cout<<"\nThe encrypted message is: "<<endl;
 for (i = 0; en[i] != -1; i++)
    {
     printf("%d", en[i]);
    }
   cout<<endl;

}

/********** END ENCRYPTION FUNCTION *************/


/********** CREATE VALUES FUNCTION ********************/

void createValues(long int phiFunction, long int pFunction, long int qFunction, long int *M, long int mod, char *messageChar)
{
 long int e[100], d[100];

 finde(phiFunction, pFunction, qFunction, d, e);

 encrypt(M, e, mod, &messageChar);
}

/********** END CREATE VALUES FUNCTION ****************/

/*********** PRIME FUNCTION *********************/

int prime(long int value)
{
 int i, test;

 test = sqrt(value);

 for (i = 2; i <= test; i++)
    {
     if (value % i == 0)
      return 0;
    }

 return 1;

}

/********* END PRIME FUNCTION ******************/

/******** find e function **********************/

long int finde(long int functionPhi, long int p, long int q, long int *d, long int *e)
{
 int i, k;
 long flag;

 k = 0;

 for (i = 2; i < functionPhi; i++)
    {

     if ( functionPhi % i == 0)
       continue;
     flag = prime(i);

    if( (flag == 1) && (i != p) && (i != q) )
     {
      e[k] = i;

      flag = findD(e[k], functionPhi);

      if (flag > 0)
        {
	 d[k] = flag;
         k++;
        }
     }

 if (k == 99)
{
 break;
}
   }
}

/********* end find e function *****************/

/******** FIND D FUNCTION **********************/

long int findD(long int e, long int phi)
{
 long int tester = 1;

 while (1 == 1)
      {
       tester = tester + phi;

	if (tester % e == 0)
       {
        cout<<"Your d is: "<<tester/e<<endl;
        return tester/e;
       }
      }

}

/******** END FIND D FUNCTION ******************/
