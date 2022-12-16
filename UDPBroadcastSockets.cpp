#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket() and bind() */
#include <arpa/inet.h>  /* for sockaddr_in */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <string>
#include <iostream>

using namespace std;

// mac listen to port: nc -kluvw 0 192.168.1.44 50000

class UDPBroadcastSockets
{
private:
    int sock;                         /* Socket */
    struct sockaddr_in broadcastAddr; /* Broadcast address */
    char *broadcastIP;                /* IP broadcast address */
    unsigned short broadcastPort;     /* Server port */
    char *sendString;                 /* String to broadcast */
    int broadcastPermission;          /* Socket opt to set permission to broadcast */

public:
    UDPBroadcastSockets(string broadcastIP_str, unsigned short broadcastPort)
    {
        broadcastIP = new char[broadcastIP_str.length() + 1];
        strcpy(broadcastIP, broadcastIP_str.c_str());

        // Create socket for sending/receiving datagrams
        if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
            cout << "socket() failed";

        // Set socket to allow broadcast
        broadcastPermission = 1;
        if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (void *)&broadcastPermission,
                       sizeof(broadcastPermission)) < 0)
            cout << "setsockopt() failed";

        // Construct local address structure
        memset(&broadcastAddr, 0, sizeof(broadcastAddr));       // Zero out structure
        broadcastAddr.sin_family = AF_INET;                     // Internet address family
        broadcastAddr.sin_addr.s_addr = inet_addr(broadcastIP); // Broadcast IP address
        broadcastAddr.sin_port = htons(broadcastPort);          // Broadcast port
    }

    ssize_t broadcastMessage(string mesg_str)
    {
        sendString = new char[mesg_str.length() + 1];
        strcpy(sendString, mesg_str.c_str());

        unsigned int sendStringLen = strlen(sendString); // Find length of sendString

        ssize_t result = sendto(sock, sendString, sendStringLen, 0, (struct sockaddr *)&broadcastAddr, sizeof(broadcastAddr));

        if (result != sendStringLen)
            cout << "sendto() sent a different number of bytes than expected";

        return result;
    }
};
