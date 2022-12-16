#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Qoute
{
private:
    vector<string> qouteTokenized;
    int qouteLength;
    bool debug;

    void debugPrint(string printMe)
    {
        if (debug)
        {
            cout << printMe;
        }
    }

public:
    void init()
    {
        qouteTokenized = vector<string>();
        qouteLength = 0;
        debug = false;
    }
    Qoute(string qoute)
    {
        init();
        stringstream check1(qoute);
        string token;

        while (getline(check1, token, ' '))
        {
            qouteTokenized.push_back(token);
        }

        for (int i = 0; i < qouteTokenized.size() && debug; i++)
        {
            debugPrint("\t" + to_string(i) + "::" + qouteTokenized[i] + "\n");
        }

        qouteLength = qouteTokenized.size();
    }
    string print()
    {
        string result;
        for (string word : qouteTokenized)
        {
            result += word + " ";
        }
        return result;
    }
    int length()
    {
        return qouteLength;
    }
};