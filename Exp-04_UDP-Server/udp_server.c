/*
 * Name: Yash Khadgi
 * PRN: 24070521137
 * Batch: B2
 */

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
    char *response = "Hello from UDP Server!";
    struct sockaddr_in servaddr, cliaddr;
    int len = sizeof(cliaddr);

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
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == SOCKET_ERROR) {
        printf("Bind failed.\n");
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("UDP Server running on port %d...\n", PORT);
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&cliaddr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Client says: %s\n", buffer);
    }

    sendto(sockfd, response, (int)strlen(response), 0, (struct sockaddr *)&cliaddr, len);
    printf("Response sent to client.\n");

    closesocket(sockfd);
    WSACleanup();

    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connectionless UDP Server using BSD/Winsock2 API in C on
   Windows and demonstrate datagram reception and transmission.

2. THEORY:
   - User Datagram Protocol (UDP): Lightweight, connectionless, unreliable
     Transport Layer protocol with minimal 8-byte header (Src Port, Dst Port,
     Length, Checksum) and no connection handshake overhead.
   - Winsock UDP Server Workflow:
     * WSAStartup(): Initializes Winsock subsystem.
     * socket(AF_INET, SOCK_DGRAM, 0): Creates datagram socket descriptor.
     * bind(): Binds socket to local port 8081 and INADDR_ANY.
     * Does NOT call listen() or accept().
     * recvfrom(): Blocks until a datagram arrives; captures client sockaddr_in.
     * sendto(): Sends response datagram directly back to client address.
     * closesocket() & WSACleanup(): Releases socket and DLL resources.

3. EXPLANATION / WORKING:
   - Step 1: Initialize Winsock library via WSAStartup(MAKEWORD(2,2), &wsa).
   - Step 2: socket(AF_INET, SOCK_DGRAM, 0) allocates datagram socket descriptor.
   - Step 3: Configure servaddr with AF_INET, htons(8081), and INADDR_ANY.
   - Step 4: bind() binds socket to port 8081.
   - Step 5: recvfrom() waits for incoming datagram and records client IP/port.
   - Step 6: Null-terminate buffer and print client message.
   - Step 7: sendto() returns datagram ("Hello from UDP Server!") to client.
   - Step 8: closesocket(sockfd) and WSACleanup() free Winsock memory.

4. CONCLUSION:
   Successfully implemented and verified the UDP Server program on Windows.
   Demonstrated connectionless datagram reception and transmission without
   prior connection establishment.

5. WINDOWS EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Method A: Using GCC / MinGW (Command Prompt 1 / PowerShell 1):
     cd Exp-04_UDP-Server
     gcc udp_server.c -o udp_server.exe -lws2_32
     .\udp_server.exe

   Method B: Using Dev-C++ / Code::Blocks:
     1. Open udp_server.c in IDE.
     2. Ensure ws2_32 is linked.
     3. Press F9 / F11 (Compile & Run).
   -----------------------------------------------------------------------------
================================================================================
*/
