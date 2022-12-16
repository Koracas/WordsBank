#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Qoute.cpp"

using namespace std;

class QouteBank
{
private:
    vector<Qoute> dictionary;
    bool debug;

    void debugPrint(string printMe)
    {
        if (debug)
        {
            cout << printMe;
        }
    }

public:
    QouteBank()
    {
        debugPrint("Generating QouteBank\n");
        dictionary = vector<Qoute>();
        debug = false;
    }

    void indexSource(string fileName)
    {
        debugPrint("Parsing Source: " + fileName + "\n");

        fstream newfile;
        newfile.open(fileName, ios::in); // open a file to perform read operation using file object
        if (newfile.is_open())
        { // checking whether the file is open
            string curentString;
            while (getline(newfile, curentString))
            { // read data from file object and put it into string.
                debugPrint("Processing Line:" + curentString + "\n");

                Qoute newQoute = Qoute(curentString);

                dictionary.push_back(newQoute);
            }
            newfile.close(); // close the file object.
        }
    }

    int getNumberOfQoutes()
    {
        return dictionary.size();
    }

    Qoute getQouteAtIndex(int iQoute)
    {
        return dictionary[iQoute];
    }
};