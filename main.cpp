#include <iostream>
#include <fstream> // nuskaitymas
#include <conio.h> // khbit geth
#include <string> // string
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <array>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

class Dekas
{
private:

    string choice; // meniu pasirinkimas
    int n;
    char pasirinkimas; // darbo pabaigos pasrinktis
    int kiekis = 0;
    bool stop = false,
         Kartojam = true,
         tiesa,
         melas;
         int efektyvymas=0;
         int counteris =0;
  int count = 0;
  int *A;





public:



    void Menu()
    {
        cout << "Pasirinkite programa:                       " << endl;
        cout << "1. Pideti nauja elementa i eile             " << endl;
        cout << "2. Pasalinti elemnta is eiles               " << endl;
        cout << "3. Perziureti pirma arba paskutini elementa " << endl;
        cout << "4. Patikrinti ar eile tuscia                " << endl;
        cout << "5. Patikrinti ar eile pilna + praplesti     " << endl;
        cout << "6. Nustatyti eiles dydi                     " << endl;
        cout << "7. isvesti i ekrana/faila                   " << endl;
        cout << "8. apsuskti                                 " << endl;
        cout << "9. Iseiti                                   " << endl;


        cin >> choice;
        system("cls");
    }
    string pasirinkti()
    {
        return choice;
    }
    void nuskaitymas()
    {
        cout << "pasirinkite ar norite iveskit duomenis ekranu ar is failo " << endl;
        cout << "1- is failo, 0- is ekrano/consoles";
        cin >> tiesa;
        if( tiesa==0)
        {
            cout << " iveskite elementu kieki " << endl;

            cin >> n;

A = (int*) malloc(1*sizeof(int));
A = (int*) realloc(A, n*sizeof(int));
            cout << " iveskite elementus " << endl;
            for(int i=0; i<n; i++)
            {
                cin >>  A[i];


            }

        }
        else
        {
            ifstream fd("duom.txt");
            fd >> n;
           A = (int*) malloc(1*sizeof(int));
A = (int*) realloc(A, n*sizeof(int));

            for(int i=0; i<n; i++)
            {
                fd >> A[i];
            }
            fd.close();


        }
        counteris=n;
    }

    void logika()
    {
        if(pasirinkti()=="1")
        {
            cout << " iveskite elementa kuri norite prideti  " << endl;//0(1)
            int a;
            cin >> a;
            cout << "Iterpti i deko pradzia ar pabaiga" <<  endl;//0(1)
            cout << " pradzia, rasykite - 0" << " pabaiga, rasykite - " << n << endl;
            int pos;
            cin >> pos;
            if(pos == n || pos ==0 ) {
            for(int i=n; i>pos; i--) // 0(pos)
            {
                A[i]=A[i-1];
            }
            A[pos]=a;
            n++; //0(1)
            cout<<"Naujas dekas yra \n";
            for(int i=0; i<n; i++)  // 0(pos)
            {
                cout << A[i] << " ";
            }
            }
            else {
                cout << "pozicija nera pirma arba paskutine " << endl;
            }
            kiekis=kiekis+1;  //
            efektyvymas = (n+pos);
            cout << "kodo efektyvumas yra lygus  = "<< "O(" << n+pos << ")" << endl;
        }
        else if (pasirinkti()=="2")
        {
            cout<<"Iveskite elementa kuri norite istrinti : ";
            int del;
            int countt;
            cout << "iveskite kuris elementa norite pasalinti is pradzios ar pabaigos " <<  endl;//0(1)
            cout << " is pradzios rasykite - " << A[0] << " paskutini- rasykite - " << A[n-1] << endl;
            cin>>del;
             if(del == A[n-1] || del ==A[0] ) {
            for(int i=0; i<n; i++)
            {
                if(A[i]==del)
                {
                    for(int j=i; j<(n-1); j++)
                    {
                        A[j]=A[j+1];
                    }
                    countt++;
                    break;
                }
            }
            if(countt==0)
            {
                cout<<"Nerasta elementas ";
            }
            else
            {
                cout<<"Istrintas sekmingai\n";
                cout<<"Naujas dekas yra \n";
                n--;
                for(int i=0; i<n; i++)
                {
                    cout<<A[i]<<" ";
                }
            }
             }
             else { cout << "elementas nera pirma arba paskutinis" << endl;}
            efektyvymas=efektyvymas+(n*(n-1))+n;
             cout << "algoritmo efektyvumas yra lygus  = "<< "O(" << (n*(n-1))+n << ")" << endl;
            kiekis=kiekis+1;
        }
        else if (pasirinkti()=="3")
        {
            cout << " pirmas elementas = " << A[0] << endl;
            cout << " paskutinis elementas = " << A[n-1] << endl;
            cout<<" dekas yra \n";
            for(int i=0; i<n; i++)
            {
                cout << A[i]<< " ";
            }

             efektyvymas=efektyvymas+n;
             cout << "algoritmo efektyvumas yra lygus  = "<< "O(" << n << ")" << endl;
            kiekis=kiekis+1;
        }
        else if (pasirinkti()=="4")
        {

            if(counteris >n)
                cout << " eile tuscia truksta " << counteris-n << " elementu" << endl;

            else
                cout << " eile pilna noredami praplesti meniu pasirinkite 1 punkta " << endl;
            cout<<" dekas yra \n";
            for(int i=0; i<n; i++)
            {
                cout << A[i]<<" ";
            }
              efektyvymas=efektyvymas+n;
             cout << "algoritmo efektyvumas yra lygus  = "<< "O(" << n << ")" << endl;
            kiekis=kiekis+1;
        }
        else if (pasirinkti()=="5")
        {
            if(counteris<=n)
                cout << "eile pilna noredami praplesti meniu pasirinkite 1 punkta" << endl;
            else
                 cout << " eile tuscia truksta " << counteris-n << " elementu" << endl;
            cout<<" dekas yra \n";
            for(int i=0; i<n; i++)
            {
                cout << A[i]<<" ";
            }
              efektyvymas=efektyvymas+n;
             cout << "algoritmo efektyvumas yra lygus  = "<< "O(" << n << ")" << endl;
            kiekis=kiekis+1;
        }
        else if (pasirinkti()=="6")
        {
            cout << "eiles dydis yra lygus = " << n << endl;
            cout<<" dekas yra \n";
            for(int i=0; i<n; i++)
            {
                cout << A[i]<<" ";
            }
            cout << "algoritmo efektyvumas yra lygus  = "<< "O(" << n << ")" << endl;
           efektyvymas=efektyvymas+n;
            kiekis=kiekis+1;
        }
        else if (pasirinkti()=="8")
        {
            cout<<"Naujas dekas yra \n";
            int temp = 0;
            for (int i = 0; i < n/2; ++i)
            {
                temp = A[n - i - 1];
                A[n - i - 1] = A[i];
                A[i] = temp;
            }

            for (int i = 0; i < n; ++i)
            {
                cout << A[i]<<" ";
            }
             efektyvymas=efektyvymas+(n*(n-1))+n;
             cout << "algoritmo efektyvumas yra lygus  = "<< "O(" << (n*(n/2))+n << ")" << endl;
            kiekis=kiekis+1;
        }
        else if (pasirinkti()=="9")
        {
            cout<<"Naujas dekas yra \n";
            for(int i=0; i<n; i++)
            {
                cout << A[i]<<" ";
            }
            cout <<" " << endl;
            cout << " atliktu zingius skaiciu lygus = " << kiekiss() << endl;
             efektyvymas=efektyvymas+n;
             cout << "algoritmo efektyvumas yra lygus  = "<< "0(" <<efektyvymas<<")"<< endl;
            exit(0);
        }


    }

    void isvesti ()
    {
        if(pasirinkti()=="7")
        {
            cout << "pasirinkite ar norite isvesti duomenis i ekrana ar i faila " << endl;
            cout << "1- i faila, 0- i ekrana/console";
            cin >> melas;
            if( melas==0)
            {
                cout << " dekas dabar atrodo taip" << endl;
                for(int i=0; i<n; i++)
                {
                    cout << A[i] << " ";
                }

            }
            else
            {
                ofstream fr("rez.txt");
                fr << "dekas atrodo taip" << endl;
                for(int i=0; i<n; i++)
                {
                    fr << A[i] << " ";
                }

            }
            kiekis=kiekis+1;
        }
    }





    void again()
    {
        cout << " " << endl;
        cout << "t - grizti" << endl;
        cout << "n - baigti darba " << endl;
        cin >> pasirinkimas;
        if (pasirinkimas == 't')
        {
            Kartojam = true;
        }
        if (pasirinkimas == 'n')
        {
            Kartojam = false;
        }
        system("cls");
    }


    bool IsNaujo()
    {
        return Kartojam;
    }
    int kiekiss()
    {
        return kiekis ;
    }
      int kieki()
    {
        return efektyvymas ;
    }


};

int main()
{
    //  string kazkas;
    Dekas dekas;
    dekas.nuskaitymas();
    while (dekas.IsNaujo())
    {
        dekas.Menu();
        dekas.pasirinkti();
        dekas.logika();
        dekas.isvesti();
        dekas.again();

    }
    cout << "atliktu zingsiu skaicius = " << dekas.kiekiss() << endl;
     cout << "algoritmo efektyvumas yra lygus  = "<< dekas.kieki() << endl;
}
