//
// Created by Alex on 18.04.2019.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "grammar.h"
using namespace std;
ifstream f("gramatics.txt");
grammar::grammar() {
    int i = 0, j = 0;
    bool flag = 0;
   // cout << "Am apelat constructorul" << endl;
    for (i = 0; i <= 100; i++)nr_coloane[i] = 0;

    getline(f, terminals); /// iau terminalele in vector de caract
    cout << "Terminalele sunt: " << terminals << endl;
    getline(f, alphabet); /// iau alfabetul posibil in vector de caract
    cout << "Alfabetul este: " << alphabet << endl;
    nr_linii = 0;
    i = 0;
    while (getline(f, temp_line)) {
        for (j = 0; j < temp_line.size(); j++) {
            matrix[i][j] = temp_line[j];
            nr_coloane[i]++;
            if (j == 0)


                cout << matrix[i][j] << "->";

            else cout << matrix[i][j];
            if (j == temp_line.size() - 1)cout << endl;
        }
        /// primul elem din matrice e terminalul din care pleaca
        nr_linii++;
        i++;
    }
}

    /// restul coloanelor matricii sunt locuri pt alfabet, respectiv terminal

int grammar::verificare_cuvant(string w,string terminal)
{
    int comp,i,j;
    i=0;char p1,p2;
    bool flag=0;
    flag=0;
    for(i=0;i<w.size();i++){p1=w[i];for(j=0;j<alphabet.size();j++)
        {p2=alphabet[j];
            if(p1==p2)flag=1;
        }
    if(flag==0){cout<<"Litera "<<p1<<" din cuvant de intrare nu se gaseste in alfabet"<<endl;return 0;}
        else flag=0;
    }
    cout<<"cuvantul este "<<w<<endl;
    //cout<<"terminalul initial este "<<terminal<<endl;
    if(terminal.size()==1&&w.size()==1){ int cmp;
        cmp=w.compare(terminal);
        if(cmp==0)return 1;}
    comp=terminal.compare("L");
    if(w.size()==0 && comp==0)return 1; /// daca terminalul e lambda si cuvantul e null
    else if(comp==0&&w.size()!=0)return 0;
    else if(w.size()==0&&comp!=0)for(i=0; i<nr_linii; i++)
        {int comp2=0;string letter;
            letter=matrix[i][0];
            comp2=terminal.compare(letter);
            if(matrix[i][nr_coloane[i]-1]=='L'
               &&comp2==0)return 1;///!
            if(i==nr_linii-1)return 0;
        }

    string cuv_temp, terminal_next_temp,terminal_temp,res_terminal,res_alph;
    flag=0;
    for(i=0; i<nr_linii; i++) /// parcurg matricea ca sa gasesc liniile si coloanele potrivite
    {
     //   cout<<"Linia "<<i<<endl;
        terminal_temp=matrix[i][0];
        terminal_next_temp=matrix[i][nr_coloane[i]-1];
      //  cout<<"Terminalul urmator este "<<terminal_next_temp<<endl;
        if(terminal_temp==terminal)
        {
            for(j=1; j<nr_coloane[i]-1; j++)
            {
                cuv_temp+=matrix[i][j];
            }
            flag=1;
        }
        if(flag==1)
        {
            string s(w,cuv_temp.size(),w.size()-cuv_temp.size()); /// s= cuvantul initial fara ce se scoate din el (cuv_temp)
            string s2(w,0,cuv_temp.size()); /// s2= verifica daca avem fragmentul de cuvant din terminal in cuvantul initial
        //    cout<<"cuvantul taiat= "<<s2<<endl;
            if(s2==cuv_temp)
            {
                if(verificare_cuvant(s,terminal_next_temp)==1)return 1; /// apelez daca e posibila mutarea
                else cout<<"Nu se poate accepta pe linia "<<i<<endl;
            }
            s.clear();
            s2.clear();
        }
        flag=0;
        cuv_temp.clear();
    }
    return 0;
}




int grammar::verificare_terminale()
{bool accept_or_deny=0;
    for(int i=0;i<nr_linii;i++){
        for(int k=0; k<terminals.size(); k++)                                /// verificare terminal1
        { if(matrix[i][0]=='L');else{
                if(terminals[k]==matrix[i][0])accept_or_deny=1;
                if(accept_or_deny==0&&k==terminals.size()-1)
                {
                    cout<<"Terminalul "<<matrix[i][0]<<" nu a fost gasit!"<<endl;
                    return 0;
                }
            }}accept_or_deny=0;
    }

    accept_or_deny=0;

    for(int i=0;i<nr_linii;i++){
        for(int k=0; k<terminals.size(); k++)
        { if(matrix[i][nr_coloane[i]-1]=='L');else{
                if(terminals[k]==matrix[i][nr_coloane[i]-1])accept_or_deny=1;        /// verificare terminal2
                if(accept_or_deny==0&&k==terminals.size()-1&&nr_coloane[i]-1!=1)
                {
                    cout<<"Terminalul "<<matrix[i][nr_coloane[i]-1]<<" nu a fost gasit!"<<endl;
                    return 0;
                }
            }}accept_or_deny=0;
    }



    accept_or_deny=0;


    for(int i=0;i<nr_linii;i++){for(int j=1;j<nr_coloane[i]-1;j++){
            for(int k=0; k<alphabet.size(); k++)
            {
                if(alphabet[k]==matrix[i][j])accept_or_deny=1;
                if(accept_or_deny==0&&k==alphabet.size()-1)
                {
                    cout<<"Litera "<<matrix[i][j]<<" nu a fost gasita in alfabet!"<<endl;   /// verificare litere in alfabet
                    return 0;
                }
            }accept_or_deny=0;
        }accept_or_deny=0;
    }


    return 1;}




