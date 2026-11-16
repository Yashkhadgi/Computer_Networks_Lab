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
    char *msg = "Hello from UDP Client!";
    struct sockaddr_in servaddr;
    socklen_t len = sizeof(servaddr);

    // Create datagram socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Fill server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Send datagram to server
    sendto(sockfd, msg, strlen(msg), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Datagram sent to server.\n");

    // Receive server reply
    ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&servaddr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Server response: %s\n", buffer);
    }

    // Close socket
    close(sockfd);
    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connectionless UDP Client using POSIX Socket API in C on
   Linux/Ubuntu and demonstrate datagram transmission and response reception to/from
   a UDP Server.

2. THEORY:
   - UDP Client Characteristics:
     * Operates without establishing a virtual circuit (no 3-way handshake).
     * Explicit call to bind() is omitted; Linux kernel dynamically binds an
       ephemeral port upon first transmission.
     * Each datagram is an isolated packet containing source and destination
       address headers.
     * High throughput and zero handshake overhead; widely used for DNS lookups,
       NTP synchronization, and streaming media.
   - POSIX Socket Functions:
     * socket(AF_INET, SOCK_DGRAM, 0): Allocates UDP socket descriptor.
     * sendto(): Sends datagram directly to destination server sockaddr_in.
     * recvfrom(): Blocks until server response datagram arrives.
     * close(): Closes the socket descriptor.

3. EXPLANATION / WORKING:
   - Step 1: socket() creates client UDP socket descriptor.
   - Step 2: Configure servaddr with AF_INET, htons(8081), and inet_addr("127.0.0.1").
   - Step 3: sendto() transmits "Hello from UDP Client!" to 127.0.0.1:8081.
   - Step 4: recvfrom() waits for server acknowledgment datagram.
   - Step 5: Null-terminate response and print to stdout.
   - Step 6: close() closes the socket.

4. CONCLUSION:
   Successfully implemented and verified a POSIX UDP Client on Linux/Ubuntu.
   Demonstrated connectionless datagram transmission and reply reception using
   sendto() and recvfrom() with minimal latency.

5. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Step 1: Open a SECOND Terminal window (Terminal 2):
           cd Exp-05_UDP-Client

   Step 2: Compile client code using gcc:
           gcc udp_client.c -o udp_client

   Step 3: Run the client (Make sure UDP Server is running in Terminal 1):
           ./udp_client

   Expected Output in Terminal 2:
           Datagram sent to server.
           Server response: Hello from UDP Server!
   -----------------------------------------------------------------------------
================================================================================
*/
