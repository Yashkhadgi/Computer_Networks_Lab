/*
 * Name: Yash Khadgi
 * PRN: 24070521137
 * Batch: B2
 */

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

    // Create datagram socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Fill server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind socket with server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("UDP Server running on port %d...\n", PORT);

    // Receive incoming datagram from client
    ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&cliaddr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Client says: %s\n", buffer);
    }

    // Send response back to the client's captured address
    sendto(sockfd, response, strlen(response), 0, (const struct sockaddr *)&cliaddr, len);
    printf("Response sent to client.\n");

    // Close socket
    close(sockfd);
    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connectionless, iterative UDP Server using POSIX Socket API
   in C on Linux/Ubuntu and demonstrate datagram reception and transmission without
   connection setup.

2. THEORY:
   - User Datagram Protocol (UDP): A lightweight, connectionless, unreliable
     Transport Layer protocol. It operates without connection handshakes, sequence
     numbers, or acknowledgments, providing low-latency best-effort delivery.
   - UDP Header Format (Fixed 8 Bytes):
     * Source Port (16 bits)
     * Destination Port (16 bits)
     * Length (16 bits - header + data)
     * Checksum (16 bits - error detection)
   - Connectionless Socket Semantics:
     * Uses SOCK_DGRAM instead of SOCK_STREAM.
     * Does NOT call listen() or accept().
     * Calls bind() to associate socket with well-known local port (8081).
     * Uses recvfrom() to receive independent datagrams; automatically captures
       the sender's IP address and port into struct sockaddr_in (cliaddr).
     * Uses sendto() to send datagram replies directly back to the client.

3. EXPLANATION / WORKING:
   - Step 1: socket(AF_INET, SOCK_DGRAM, 0) allocates datagram socket.
   - Step 2: Configure servaddr with AF_INET, INADDR_ANY, and htons(8081).
   - Step 3: bind() binds socket to port 8081.
   - Step 4: recvfrom() blocks until an incoming UDP datagram arrives from client;
     stores sender address details in cliaddr.
   - Step 5: Null-terminate buffer and print client payload.
   - Step 6: sendto() returns datagram ("Hello from UDP Server!") to cliaddr.
   - Step 7: close() releases socket descriptor.

4. CONCLUSION:
   Successfully implemented and tested a POSIX UDP Server on Linux/Ubuntu.
   Demonstrated connectionless datagram reception and transmission using
   recvfrom() and sendto() over port 8081.

5. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Step 1: Open Terminal (Terminal 1):
           cd Exp-04_UDP-Server

   Step 2: Compile server code using gcc:
           gcc udp_server.c -o udp_server

   Step 3: Run the server (Must be started BEFORE client):
           ./udp_server

   Expected Output in Terminal 1:
           UDP Server running on port 8081...
           Client says: Hello from UDP Client!
           Response sent to client.
   -----------------------------------------------------------------------------
================================================================================
*/
