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

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *msg = "Hello from TCP Client!";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        close(sock);
        return -1;
    }

    // Connect to TCP Server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        close(sock);
        return -1;
    }

    // Send greeting message to server
    send(sock, msg, strlen(msg), 0);
    printf("Message sent to server.\n");

    // Read response from server
    ssize_t bytes_read = read(sock, buffer, BUFFER_SIZE - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        printf("Server response: %s\n", buffer);
    }

    // Close socket
    close(sock);
    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connection-oriented TCP Client using POSIX Socket API in C on
   Linux/Ubuntu and demonstrate active connection establishment and message
   exchange with a TCP Server.

2. THEORY:
   - TCP Client Architecture:
     The client is the active initiator in the client-server model. It does not
     bind to a fixed port; the Linux kernel dynamically assigns an ephemeral
     port during connect().
   - Active Handshake Initiation:
     Calling connect() triggers transmission of a TCP SYN segment to the server
     IP (127.0.0.1) and port (8080), initiating the 3-way handshake.
   - POSIX Socket API Functions (Client):
     * socket(AF_INET, SOCK_STREAM, 0): Creates TCP stream socket endpoint.
     * inet_pton(): Converts presentation format IP ("127.0.0.1") to network
       binary format.
     * connect(): Performs active connection setup to server's sockaddr_in.
     * send(): Transmits payload bytes across established TCP stream.
     * read(): Synchronously reads server reply from the socket buffer.
     * close(): Sends FIN segment, initiating connection teardown.

3. EXPLANATION / WORKING:
   - Step 1: socket() creates client socket descriptor.
   - Step 2: Configure serv_addr struct with AF_INET and htons(8080).
   - Step 3: inet_pton() converts "127.0.0.1" into 32-bit network binary address.
   - Step 4: connect() initiates 3-way handshake with TCP Server running on port 8080.
   - Step 5: Upon successful handshake, send() transmits "Hello from TCP Client!".
   - Step 6: read() receives server response into buffer and outputs to terminal.
   - Step 7: close() terminates client socket session.

4. CONCLUSION:
   Successfully implemented and tested a POSIX TCP Client on Linux/Ubuntu.
   Verified connection establishment to 127.0.0.1:8080, reliable bidirectional
   communication, and clean socket closure.

5. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Step 1: Open a SECOND Terminal window (Terminal 2):
           cd Exp-03_TCP-Client

   Step 2: Compile client code using gcc:
           gcc tcp_client.c -o tcp_client

   Step 3: Run the client (Make sure Server is already running in Terminal 1):
           ./tcp_client

   Expected Output in Terminal 2:
           Message sent to server.
           Server response: Hello from TCP Server!
   -----------------------------------------------------------------------------
================================================================================
*/
