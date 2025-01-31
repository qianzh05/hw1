#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;
int main(int argc, char* argv[])
{
    ULListStr* mylist = new ULListStr();
    // mylist->push_back("aa");
    // mylist->push_back("bb");
    // mylist->push_back("owef");
    // cout << mylist->get(0) << endl;
    // mylist->pop_front();
    // cout << mylist->get(1) << endl;

    for(int i = 0; i < 60; i++){
        mylist->push_front(to_string(i));
    }
    for (int i = 0; i < 10; i++){
        mylist->pop_back();
    }       
    for (int i = 0; i < 50; i++){
        cout << mylist->get(i) << endl;
    }
    //cout << mylist->back() << endl;
}   
