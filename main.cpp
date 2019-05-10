#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "grammar.h"
using namespace std;

int main() {

grammar test;
    if(test.verificare_terminale()==0);else{
        if(test.verificare_cuvant("abbc","S")==0)cout<<"Cuvantul nu este acceptat";
        else cout<<"Cuvantul este acceptat";}
    return 0;
}

/*
///   Cum voi scrie datele de input:

1. Terminale: S A
2. Litere permise: a b c
Structura gramatica:
3,4,5... Terminal  litera_mica Litera_Mare
         / = lambda

*/