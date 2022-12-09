#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <list>

using namespace std;

class QouteBank{
    private:
        list<vector<string>> dictionary;

    public:
        QouteBank(){
            cout << "Generating QouteBank"<<endl;
        }
        void indexSource( string fileName ){
            
        }
};

int main()
{
    std::cout << "Hello Parsing my students data (words.xml)....." << endl;
    fstream newfile;
    newfile.open("words.xml",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string curentString;
        while(getline(newfile, curentString)){ //read data from file object and put it into string.

            cout << curentString << "\n"; //print the data of the string

            // Vector of string to save tokens
                vector <string> tokens;
            
                // stringstream class check1
                stringstream check1(curentString);
                
                string intermediate;
                
                // Tokenizing w.r.t. space ' '
                while(getline(check1, intermediate, ' '))
                {
                    tokens.push_back(intermediate);
                }
                
                // Printing the token vector
                for(int i = 0; i < tokens.size(); i++)
                    cout << tokens[i] << '\n';
                
        }
        newfile.close(); //close the file object.
    }
}
