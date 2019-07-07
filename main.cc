#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "textprocess.h" 
#include "echo.h"
#include "allcaps.h"
#include "dropfirst.h"
#include "count.h"
#include "doublewords.h"


int main () {
    
    cin.exceptions(ios::failbit|ios::eofbit);
    string s;
    
    try {
        while(1) {
            getline(cin,s);
            istringstream iss{s};
            iss.exceptions(ios::failbit);
            string fname;
            iss >> fname;
            istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());
        
            in->exceptions(ios::failbit|ios::eofbit);
            
            TextProcessor *tp = new Echo;
            string dec;
            try {
                while (true) {
                    if(!(iss >> dec)){
                        throw std::iostream::failure("end");
                    }
                    if (dec == "dropfirst") {
                        int z = 0;
                        string a;
                        iss >> a;
                        try{
                          z = stoi(a);
                        }catch(std::invalid_argument){
                            throw std::ios::failure("end");
                        }
                        
                        //stoi dene
                        //iss >> z;
                        
                        TextProcessor *d = tp;
                        tp = new Dropfirst{d,z};
                        
                    }
                    else if (dec == "doublewords") {
                        TextProcessor *d = tp;
                        tp = new Doublewords{d};
                    }
                    else if (dec == "allcaps") {
                        TextProcessor *d = tp;
                        tp = new Allcaps{d};
                        
                    }
                    else if (dec == "count") {
                        char c;
                        iss >> c;
                        TextProcessor *d = tp;
                        tp = new Count{d,c};
                    }
                }
            }
            catch (ios::failure) {}
            
            tp->setSource(in);
            
            string word;
            
            try {
                int lineNum = 1;
                while (true) {
                    try{
                        word = tp->getWord();
                        cout << lineNum++ << ' ' << word << endl;
                    }catch(int x){}
                    
                }
            }
            catch (ios::failure) {}
            
            if (in != &cin) delete in;
            delete tp;
        }
    }
    catch (ios::failure) {}
}
