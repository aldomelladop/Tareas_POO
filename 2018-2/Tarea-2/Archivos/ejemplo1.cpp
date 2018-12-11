//#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

void print_usage(){

    cout << endl << "Conway Number Generator";
    cout << endl << "Arguments: initializer followed by nth term to be printed" << endl;
}

string say(string s){

    // Returns string said phonetically
    // e.g. '111' becomes '31'

    unsigned int sz = s.size();

    if (sz == 1){
        s.insert(0, "1");
    }
    else{
        s.insert(0, to_string(sz));
        s.erase(2, sz-1);
    }
    return s;
}

string get_next(string x)
{

    // Returns next term in Conway sequence

    unsigned prev_point = 0;
    vector<string> grp;
    string tmp;
    tmp.resize(x.size());

    // Organize sequence in group of identical consecutive characters

    for (unsigned int i = 0; i < x.size(); ++i)
    {

    if (i != x.size() - 1){

        if (x.at(i) != x.at(i + 1)){
            tmp.assign(x, prev_point, i+1 - prev_point);
            grp.push_back(tmp);
            prev_point = i + 1;
            tmp.clear();
        }
    }
    else if (i != 0){

        if (x.at(i) != x.at(i - 1)){
            tmp = x.at(i);
            grp.push_back(tmp);
            tmp.clear();
        }
        else
        {
            tmp.assign(x, prev_point, i+1 - prev_point);
            grp.push_back(tmp);
            tmp.clear();
        }
    }
    // Phonetically say each group

    // Could use a lambda: transform(begin(grp), end(grp), begin(said_grp)[=](string s){return say(s);});
    // if I create a new vector<string> said_grp to copy in
    // That didn't help the runtime error

    for (auto& i : grp)
        i = say(i);

    // Join each vector<string> entry into a single string

    string next_seq;
    next_seq = accumulate(begin(grp), end(grp), string(""));
    return next_seq;
    }
}

string conway(string init, int n){

    // Print out nth Conway term
    // starting sequence at init

    for (int i = 1; i <= n; ++i)
        init = get_next(init);
    return init;
}

int main(int argc, const char* argv[]){

    if (argc < 3){
        print_usage();
        return 0;
    }
    cout << endl << "Conway number: " << conway(argv[1], stoi(argv[2])) << endl;
    return 0;
}