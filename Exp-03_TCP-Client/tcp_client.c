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

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET sock = INVALID_SOCKET;
    struct sockaddr_in serv_addr;
    char *msg = "Hello from TCP Client!";
    char buffer[BUFFER_SIZE] = {0};

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        WSACleanup();
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed.\n");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    send(sock, msg, (int)strlen(msg), 0);
    printf("Message sent to server.\n");

    recv(sock, buffer, BUFFER_SIZE - 1, 0);
    printf("Server response: %s\n", buffer);

    closesocket(sock);
    WSACleanup();

    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connection-oriented TCP Client using BSD/Winsock2 API in C
   on Windows and demonstrate active connection establishment to a TCP Server.

2. THEORY:
   - Client-Server Architecture:
     The client initiates communication by performing an active connect() to
     the server's well-known IP and port, triggering the TCP 3-way handshake.
   - Winsock API Lifecycle (Client):
     * WSAStartup(): Initializes Winsock DLL environment.
     * socket(): Allocates socket descriptor for streaming communication.
     * inet_addr(): Converts dotted-decimal string ("127.0.0.1") to 32-bit network binary.
     * connect(): Connects socket to remote server sockaddr_in.
     * send() & recv(): Transmits client request and receives server response.
     * closesocket() & WSACleanup(): Sends FIN segment and unloads Winsock.

3. EXPLANATION / WORKING:
   - Step 1: Initialize Winsock library via WSAStartup(MAKEWORD(2,2), &wsa).
   - Step 2: socket(AF_INET, SOCK_STREAM, 0) allocates client socket descriptor.
   - Step 3: Populate serv_addr with AF_INET, htons(8080), and inet_addr("127.0.0.1").
   - Step 4: connect() establishes active 3-way handshake with TCP Server on port 8080.
   - Step 5: send() transmits payload "Hello from TCP Client!".
   - Step 6: recv() reads response ("Hello from TCP Server!") into buffer.
   - Step 7: closesocket(sock) and WSACleanup() terminate connection cleanly.

4. CONCLUSION:
   Successfully implemented and tested the TCP Client program on Windows.
   Verified connection establishment to 127.0.0.1:8080, reliable bidirectional
   communication, and clean Winsock teardown.

5. WINDOWS EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Method A: Using GCC / MinGW (Command Prompt 2 / PowerShell 2):
     cd Exp-03_TCP-Client
     gcc tcp_client.c -o tcp_client.exe -lws2_32
     .\tcp_client.exe
     (Make sure TCP Server is already running in Terminal 1)

   Method B: Using Dev-C++ / Code::Blocks:
     1. Open tcp_client.c in IDE.
     2. Ensure ws2_32 linker flag is enabled.
     3. Press F9 / F11 (Compile & Run).
   -----------------------------------------------------------------------------
================================================================================
*/
