#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <chrono>
#include <thread>
#include "QouteBank.cpp"
#include "UDPBroadcastSockets.cpp"

using namespace std;

const bool GLOBAL_DEBUG = false;
const std::string broadcastIP_str = "192.168.1.44";
const unsigned short broadcastPort = 50000;

int main()
{
    QouteBank qoutes = QouteBank();
    qoutes.indexSource("words.xml");

    int numberOfQoutes = qoutes.getNumberOfQoutes() -1;
    int counter = 0;

    UDPBroadcastSockets udpBroadcaster = UDPBroadcastSockets(broadcastIP_str, broadcastPort);

    while (1)
    {
        Qoute curQoute = qoutes.getQouteAtIndex(counter);
        udpBroadcaster.broadcastMessage(curQoute.print()+"\n");
        int qouteLength = curQoute.length();
        int waitTimeMS = qouteLength * 1000;
        std::this_thread::sleep_for(std::chrono::milliseconds(waitTimeMS));
        counter >= numberOfQoutes ? counter = 0 : counter++;
    }
 }