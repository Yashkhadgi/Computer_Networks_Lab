#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8081
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    char *response = "Hello from UDP Server!";
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len = sizeof(cliaddr);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("UDP Server running on port %d...\n", PORT);

    ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&cliaddr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Client says: %s\n", buffer);
    }

    sendto(sockfd, response, strlen(response), 0, (const struct sockaddr *)&cliaddr, len);
    printf("Response sent to client.\n");

    close(sockfd);
    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connectionless UDP Server using POSIX Socket API in C on
   Linux/Ubuntu and demonstrate datagram reception and transmission.

2. THEORY:
   - User Datagram Protocol (UDP): Lightweight, connectionless, unreliable
     Transport Layer protocol with minimal 8-byte header and zero handshake overhead.
   - POSIX UDP Server Semantics:
     * socket(AF_INET, SOCK_DGRAM, 0): Creates datagram socket descriptor.
     * bind(): Associates socket with local port 8081 and INADDR_ANY.
     * Does NOT call listen() or accept().
     * recvfrom(): Blocks until datagram arrives; captures client IP and port.
     * sendto(): Sends response datagram directly back to client address.
     * close(): Releases socket descriptor.

3. STEPS FOR PERFORMANCE (ON UBUNTU / LINUX):
   Step 1: Open Terminal 1 using `Ctrl + Alt + T`.
   Step 2: Navigate to directory:
           cd Exp-04_UDP-Server
   Step 3: Compile the UDP Server C program:
           gcc udp_server_linux.c -o udp_server
   Step 4: Start UDP Server:
           ./udp_server
   Step 5: Observe status:
           Prints "UDP Server running on port 8081..." and waits on recvfrom().
   Step 6: Keep Terminal 1 open and run UDP Client in Terminal 2.
   Step 7: Once datagram arrives, Terminal 1 displays:
           "Client says: Hello from UDP Client!"
           "Response sent to client."
           Server exits cleanly.

4. EXPLANATION / WORKING:
   - Step 1: socket() allocates datagram socket descriptor.
   - Step 2: Configure servaddr with AF_INET, htons(8081), and INADDR_ANY.
   - Step 3: bind() binds socket to port 8081.
   - Step 4: recvfrom() waits for incoming datagram and records client IP/port.
   - Step 5: Null-terminate buffer and print client message.
   - Step 6: sendto() returns datagram ("Hello from UDP Server!") to client.
   - Step 7: close() releases socket descriptor.

5. CONCLUSION:
   Successfully implemented and verified the POSIX UDP Server on Linux/Ubuntu.
   Demonstrated connectionless datagram reception and transmission using
   recvfrom() and sendto() over port 8081.

6. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Step 1: Open Terminal (Terminal 1):
           cd Exp-04_UDP-Server

   Step 2: Compile server code using gcc:
           gcc udp_server_linux.c -o udp_server

   Step 3: Run the server (Must be started BEFORE client):
           ./udp_server

   Expected Output in Terminal 1:
           UDP Server running on port 8081...
           Client says: Hello from UDP Client!
           Response sent to client.
   -----------------------------------------------------------------------------
================================================================================
*/
