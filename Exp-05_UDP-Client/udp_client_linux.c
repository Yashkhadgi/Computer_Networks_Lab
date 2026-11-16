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

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(sockfd, msg, strlen(msg), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Datagram sent to server.\n");

    ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&servaddr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Server response: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connectionless UDP Client using POSIX Socket API in C on
   Linux/Ubuntu and demonstrate datagram transmission and response reception.

2. THEORY:
   - UDP Client Characteristics:
     * Operates without virtual circuit negotiation (no 3-way handshake).
     * Linux kernel dynamically binds an ephemeral port on transmission.
     * Each datagram is an independent transmission unit.
     * Minimal transmission overhead, suitable for low-latency applications.
   - POSIX Socket API:
     * socket(AF_INET, SOCK_DGRAM, 0): Allocates datagram socket.
     * sendto(): Sends datagram directly to destination sockaddr_in.
     * recvfrom(): Waits for server reply datagram.
     * close(): Releases socket descriptor.

3. STEPS FOR PERFORMANCE (ON UBUNTU / LINUX):
   Step 1: Verify UDP Server is running in Terminal 1 on port 8081.
   Step 2: Open Terminal 2 using `Ctrl + Shift + T`.
   Step 3: Navigate to directory:
           cd Exp-05_UDP-Client
   Step 4: Compile UDP Client code:
           gcc udp_client_linux.c -o udp_client
   Step 5: Run client executable:
           ./udp_client
   Step 6: Observe transmission and reply:
           Terminal 2 prints:
           "Datagram sent to server."
           "Server response: Hello from UDP Server!"

4. EXPLANATION / WORKING:
   - Step 1: socket() creates client UDP socket descriptor.
   - Step 2: Configure servaddr with AF_INET, htons(8081), and inet_addr("127.0.0.1").
   - Step 3: sendto() sends "Hello from UDP Client!" to 127.0.0.1:8081.
   - Step 4: recvfrom() receives server response datagram into buffer.
   - Step 5: Null-terminate and print server reply.
   - Step 6: close() frees socket descriptor.

5. CONCLUSION:
   Successfully implemented and verified the POSIX UDP Client on Linux/Ubuntu.
   Validated lightweight datagram transmission and response reception without
   connection setup latency.

6. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Step 1: Open a NEW Terminal window (Terminal 2):
           cd Exp-05_UDP-Client

   Step 2: Compile client code using gcc:
           gcc udp_client_linux.c -o udp_client

   Step 3: Run the client (Make sure UDP Server is running in Terminal 1):
           ./udp_client

   Expected Output in Terminal 2:
           Datagram sent to server.
           Server response: Hello from UDP Server!
   -----------------------------------------------------------------------------
================================================================================
*/
