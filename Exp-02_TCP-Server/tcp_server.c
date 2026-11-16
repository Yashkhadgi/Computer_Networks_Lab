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
    SOCKET server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *response = "Hello from TCP Server!";

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        WSACleanup();
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR) {
        printf("Bind failed.\n");
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    listen(server_fd, 3);
    printf("TCP Server listening on port %d...\n", PORT);

    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    if (new_socket == INVALID_SOCKET) {
        printf("Accept failed.\n");
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    recv(new_socket, buffer, BUFFER_SIZE - 1, 0);
    printf("Client says: %s\n", buffer);

    send(new_socket, response, (int)strlen(response), 0);
    printf("Response sent to client.\n");

    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connection-oriented iterative TCP Server using BSD/Winsock2
   API in C on Windows and demonstrate reliable communication with a client.

2. THEORY:
   - Transmission Control Protocol (TCP): Reliable, connection-oriented,
     byte-stream Transport Layer protocol ensuring ordered, error-free delivery
     via 3-way handshake (SYN -> SYN-ACK -> ACK) and sequence/ACK numbers.
   - Windows Winsock Architecture:
     * WSAStartup(): Initializes the Windows Sockets DLL (ws2_32.dll).
     * socket(): Allocates a SOCKET descriptor (AF_INET, SOCK_STREAM, 0).
     * bind(): Associates server socket with local IP (INADDR_ANY) and port 8080.
     * listen(): Places socket into passive listening state with backlog queue.
     * accept(): Blocks until client connects; returns new connected SOCKET.
     * recv() / send(): Reads client payload and returns server response.
     * closesocket() & WSACleanup(): Closes sockets and terminates Winsock library.

3. STEPS FOR PERFORMANCE (ON WINDOWS):
   Step 1: Open Command Prompt (CMD 1) or Dev-C++ / Code::Blocks.
   Step 2: Navigate to directory:
           cd Exp-02_TCP-Server
   Step 3: Compile TCP Server code using MinGW GCC with Winsock library:
           gcc tcp_server.c -o tcp_server.exe -lws2_32
           (Or in Dev-C++: Project Settings -> Linker -> Add -lws2_32 -> Compile).
   Step 4: Start TCP Server:
           .\tcp_server.exe
   Step 5: Observe status:
           Prints "TCP Server listening on port 8080..." and pauses waiting for client.
   Step 6: Keep CMD 1 open and launch TCP Client in CMD 2.
   Step 7: Once client connects, CMD 1 displays:
           "Client says: Hello from TCP Client!"
           "Response sent to client."
           Server exits cleanly.

4. EXPLANATION / WORKING:
   - Step 1: Initialize Winsock subsystem via WSAStartup(MAKEWORD(2, 2), &wsa).
   - Step 2: Create endpoint via socket(AF_INET, SOCK_STREAM, 0).
   - Step 3: Populate struct sockaddr_in with AF_INET, htons(8080), and INADDR_ANY.
   - Step 4: bind() binds socket to port 8080; listen(server_fd, 3) enables listening.
   - Step 5: accept() waits and accepts incoming client connection (new_socket).
   - Step 6: recv() reads client message ("Hello from TCP Client!") into buffer.
   - Step 7: send() returns greeting ("Hello from TCP Server!") to client.
   - Step 8: closesocket() closes sockets and WSACleanup() releases memory.

5. CONCLUSION:
   Successfully implemented and verified the TCP Server socket program on Windows.
   Validated 3-way handshake connection establishment, reliable bidirectional
   communication, and clean Winsock teardown.

6. WINDOWS EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Method A: Using GCC / MinGW (Command Prompt / PowerShell):
     cd Exp-02_TCP-Server
     gcc tcp_server.c -o tcp_server.exe -lws2_32
     .\tcp_server.exe
     (Note: -lws2_32 links the Windows Socket 2 library)

   Method B: Using Dev-C++ / Code::Blocks / Visual Studio:
     1. Open tcp_server.c in IDE.
     2. Ensure ws2_32 is linked (under Project -> Compiler Settings -> Linker).
     3. Press F9 / F11 (Compile & Run).
   -----------------------------------------------------------------------------
================================================================================
*/
