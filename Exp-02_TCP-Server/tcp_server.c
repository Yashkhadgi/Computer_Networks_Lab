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
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *response = "Hello from TCP Server!";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections (backlog = 3)
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("TCP Server listening on port %d...\n", PORT);

    // Accept client connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Read client message
    ssize_t bytes_read = read(new_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        printf("Client says: %s\n", buffer);
    }

    // Send server response
    send(new_socket, response, strlen(response), 0);
    printf("Response sent to client.\n");

    // Close sockets
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
   - Transmission Control Protocol (TCP): A reliable, connection-oriented,
     byte-stream Transport Layer protocol. It guarantees in-order, error-free
     delivery using sequence numbers, positive acknowledgments (ACK), checksums,
     and sliding window flow control.
   - Three-Way Handshake Connection Establishment:
       Client ---[ SYN (Seq = x) ]--------------------------> Server
       Client <---[ SYN (Seq = y), ACK (Ack = x + 1) ]-------- Server
       Client ---[ ACK (Ack = y + 1) ]------------------------> Server
   - Linux POSIX Socket Lifecycle (Server):
     * socket(): Allocates file descriptor for network communication
       (AF_INET, SOCK_STREAM, 0).
     * bind(): Associates socket with local address (INADDR_ANY) and port (8080).
     * listen(): Places socket into passive listening state with backlog queue.
     * accept(): Blocks until client connects; returns a new connected socket
       file descriptor (new_socket) for data transfer.
     * read() / send(): Reads request from client and transmits reply.
     * close(): Gracefully closes sockets, triggering TCP 4-way FIN/ACK teardown.

3. EXPLANATION / WORKING:
   - Step 1: socket(AF_INET, SOCK_STREAM, 0) allocates server socket descriptor.
   - Step 2: setsockopt() configures SO_REUSEADDR to prevent "Address already in use" errors.
   - Step 3: Populate struct sockaddr_in with AF_INET, htons(8080), and INADDR_ANY.
   - Step 4: bind() attaches the socket descriptor to local interface and port 8080.
   - Step 5: listen(server_fd, 3) enables incoming client queue.
   - Step 6: accept() extracts the first connection request and returns new_socket.
   - Step 7: read() receives client string ("Hello from TCP Client!") into buffer.
   - Step 8: send() returns greeting ("Hello from TCP Server!") back to client.
   - Step 9: close() closes connected socket and master listening socket.

4. CONCLUSION:
   Successfully implemented and verified a POSIX TCP Server on Linux/Ubuntu.
   Demonstrated socket creation, binding, passive listening, client handshake
   acceptance, and reliable message exchange.

5. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   Step 1: Open Terminal (Terminal 1) and navigate to experiment folder:
           cd Exp-02_TCP-Server

   Step 2: Compile the server code using gcc:
           gcc tcp_server.c -o tcp_server

   Step 3: Run the server (Must be started BEFORE running client):
           ./tcp_server

   Expected Output in Terminal 1:
           TCP Server listening on port 8080...
           Client says: Hello from TCP Client!
           Response sent to client.
   -----------------------------------------------------------------------------
================================================================================
*/
