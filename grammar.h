//
// Created by Alex on 18.04.2019.
//

#ifndef LFATWO_GRAMMAR_H
#define LFATWO_GRAMMAR_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
class grammar
{
    string terminals,alphabet,temp_line;
    char matrix[100][100];
    int nr_linii=0;
    int nr_coloane[100];
    int poz=0;
    char litera_crt;
public:
    string w;
    string terminal;
    grammar();
    int verificare_cuvant(string w,string terminal);
    int verificare_terminale();
};



#endif //LFATWO_GRAMMAR_H
