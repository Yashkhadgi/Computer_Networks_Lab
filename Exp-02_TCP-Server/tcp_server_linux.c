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
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *response = "Hello from TCP Server!";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("TCP Server listening on port %d...\n", PORT);

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_read = read(new_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        printf("Client says: %s\n", buffer);
    }

    send(new_socket, response, strlen(response), 0);
    printf("Response sent to client.\n");

    close(new_socket);
    close(server_fd);

    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement a connection-oriented iterative TCP Server using POSIX Socket
   API in C on Linux/Ubuntu and demonstrate reliable bidirectional communication
   with a client.

2. THEORY:
   - Transmission Control Protocol (TCP): Reliable, connection-oriented,
     byte-stream Transport Layer protocol ensuring ordered, error-free delivery
     via 3-way handshake (SYN -> SYN-ACK -> ACK) and sequence/ACK numbers.
   - Linux POSIX Socket Lifecycle (Server):
     * socket(): Allocates file descriptor (AF_INET, SOCK_STREAM, 0).
     * bind(): Binds socket to local IP (INADDR_ANY) and port 8080.
     * listen(): Places socket into passive listening state with backlog queue.
     * accept(): Blocks until client connects; returns new connected socket descriptor.
     * read() / send(): Exchanging stream data with client.
     * close(): Triggers TCP 4-way FIN/ACK connection teardown.

3. STEPS FOR PERFORMANCE (ON UBUNTU / LINUX):
   Step 1: Open Terminal (Terminal 1) using `Ctrl + Alt + T`.
   Step 2: Navigate to directory:
           cd Exp-02_TCP-Server
   Step 3: Check GCC compiler availability:
           gcc --version
           (If needed: sudo apt install build-essential)
   Step 4: Compile the TCP Server C program:
           gcc tcp_server_linux.c -o tcp_server
   Step 5: Start the server executable:
           ./tcp_server
   Step 6: Observe terminal output:
           Prints "TCP Server listening on port 8080..." and pauses.
           The server enters accept() blocking state, waiting for client.
   Step 7: Keep Terminal 1 running and switch to Terminal 2 to run the TCP Client.
   Step 8: Once client connects, Terminal 1 displays:
           "Client says: Hello from TCP Client!"
           "Response sent to client."
           Server terminates cleanly.

4. EXPLANATION / WORKING:
   - Step 1: socket(AF_INET, SOCK_STREAM, 0) allocates server socket descriptor.
   - Step 2: setsockopt() configures SO_REUSEADDR.
   - Step 3: Populate struct sockaddr_in with AF_INET, htons(8080), and INADDR_ANY.
   - Step 4: bind() attaches socket to port 8080; listen(server_fd, 3) enables listening.
   - Step 5: accept() waits and accepts incoming client connection (new_socket).
   - Step 6: read() reads client message ("Hello from TCP Client!") into buffer.
   - Step 7: send() returns greeting ("Hello from TCP Server!") to client.
   - Step 8: close() terminates new_socket and server_fd.

5. CONCLUSION:
   Successfully implemented and verified the POSIX TCP Server on Linux/Ubuntu.
   Demonstrated socket creation, binding, listening, client handshake acceptance,
   and reliable full-duplex message exchange.

6. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Step 1: Open Terminal (Terminal 1) and navigate to experiment folder:
           cd Exp-02_TCP-Server

   Step 2: Compile the server code using gcc:
           gcc tcp_server_linux.c -o tcp_server

   Step 3: Run the server (Must be started BEFORE client):
           ./tcp_server

   Expected Output in Terminal 1:
           TCP Server listening on port 8080...
           Client says: Hello from TCP Client!
           Response sent to client.
   -----------------------------------------------------------------------------
================================================================================
*/
