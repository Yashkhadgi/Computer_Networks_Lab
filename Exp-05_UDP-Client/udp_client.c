#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8081
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET sockfd;
    char buffer[BUFFER_SIZE];
    char *msg = "Hello from UDP Client!";
    struct sockaddr_in servaddr;
    int len = sizeof(servaddr);

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        WSACleanup();
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(sockfd, msg, (int)strlen(msg), 0, (struct sockaddr *)&servaddr, len);
    printf("Datagram sent to server.\n");

    int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&servaddr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Server response: %s\n", buffer);
    }

    closesocket(sockfd);
    WSACleanup();

    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connectionless UDP Client using BSD/Winsock2 API in C on
   Windows and demonstrate datagram transmission and reception to/from a server.

2. THEORY:
   - UDP Client Characteristics:
     * Operates without virtual circuit negotiation (no 3-way handshake).
     * No bind() required; OS binds an ephemeral port on transmission.
     * Each datagram is an independent transmission unit.
     * Minimal transmission overhead, suitable for low-latency applications.
   - Winsock Functions:
     * socket(AF_INET, SOCK_DGRAM, 0): Allocates datagram socket.
     * sendto(): Sends datagram directly to destination sockaddr_in.
     * recvfrom(): Waits for server reply datagram.
     * closesocket() & WSACleanup(): Releases socket and unloads DLL.

3. EXPLANATION / WORKING:
   - Step 1: Initialize Winsock via WSAStartup(MAKEWORD(2,2), &wsa).
   - Step 2: socket() creates UDP socket descriptor.
   - Step 3: Configure servaddr with AF_INET, htons(8081), and inet_addr("127.0.0.1").
   - Step 4: sendto() sends "Hello from UDP Client!" to 127.0.0.1:8081.
   - Step 5: recvfrom() receives server response datagram into buffer.
   - Step 6: Null-terminate and print server reply.
   - Step 7: closesocket() and WSACleanup() free socket memory.

4. CONCLUSION:
   Successfully implemented and verified the UDP Client program on Windows.
   Validated lightweight datagram transmission and response reception without
   connection setup latency.

5. WINDOWS EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Method A: Using GCC / MinGW (Command Prompt 2 / PowerShell 2):
     cd Exp-05_UDP-Client
     gcc udp_client.c -o udp_client.exe -lws2_32
     .\udp_client.exe
     (Make sure UDP Server is running in Terminal 1)

   Method B: Using Dev-C++ / Code::Blocks:
     1. Open udp_client.c in IDE.
     2. Ensure ws2_32 is linked.
     3. Press F9 / F11 (Compile & Run).
   -----------------------------------------------------------------------------
================================================================================
*/
