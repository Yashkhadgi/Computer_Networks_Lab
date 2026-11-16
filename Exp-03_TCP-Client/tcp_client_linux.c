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

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        close(sock);
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        close(sock);
        return -1;
    }

    send(sock, msg, strlen(msg), 0);
    printf("Message sent to server.\n");

    ssize_t bytes_read = read(sock, buffer, BUFFER_SIZE - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        printf("Server response: %s\n", buffer);
    }

    close(sock);
    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connection-oriented TCP Client using POSIX Socket API in C on
   Linux/Ubuntu and demonstrate active connection establishment to a TCP Server.

2. THEORY:
   - TCP Client Architecture:
     The client initiates communication by performing an active connect() to
     the server IP and port, triggering the TCP 3-way handshake.
   - POSIX Socket API (Client):
     * socket(AF_INET, SOCK_STREAM, 0): Allocates client socket descriptor.
     * inet_pton(): Converts text IP ("127.0.0.1") to 32-bit network binary format.
     * connect(): Connects socket to remote server sockaddr_in.
     * send() & read(): Transmits client payload and reads server reply.
     * close(): Sends FIN segment, initiating connection teardown.

3. EXPLANATION / WORKING:
   - Step 1: socket() creates client socket descriptor.
   - Step 2: Configure serv_addr with AF_INET, htons(8080), and inet_pton("127.0.0.1").
   - Step 3: connect() initiates 3-way handshake with TCP Server running on port 8080.
   - Step 4: send() transmits payload "Hello from TCP Client!".
   - Step 5: read() receives server reply ("Hello from TCP Server!") into buffer.
   - Step 6: close() terminates client socket session.

4. CONCLUSION:
   Successfully implemented and verified the POSIX TCP Client on Linux/Ubuntu.
   Demonstrated active connection establishment, reliable bidirectional communication,
   and clean connection closure.

5. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Step 1: Open a NEW Terminal window (Terminal 2):
           cd Exp-03_TCP-Client

   Step 2: Compile client code using gcc:
           gcc tcp_client_linux.c -o tcp_client

   Step 3: Run the client (Make sure TCP Server is running in Terminal 1):
           ./tcp_client

   Expected Output in Terminal 2:
           Message sent to server.
           Server response: Hello from TCP Server!
   -----------------------------------------------------------------------------
================================================================================
*/
