# Experiment 7: Packet Analysis of TCP & UDP Protocols

## Objectives
* Capture, inspect, and compare Transport Layer protocols (TCP and UDP) using Wireshark.

## Protocol Comparison

| Feature | TCP (Transmission Control Protocol) | UDP (User Datagram Protocol) |
| :--- | :--- | :--- |
| **Connection Type** | Connection-Oriented (3-Way Handshake) | Connectionless |
| **Header Size** | 20 to 60 Bytes (Variable) | 8 Bytes (Fixed) |
| **Reliability** | Guaranteed delivery via ACKs & Retransmissions | Best-effort delivery |
| **Header Fields** | Src/Dst Port, Seq No, Ack No, Window, Flags | Src/Dst Port, Length, Checksum |

## Wireshark Filters
* `tcp` : Displays TCP segment traffic showing 3-way handshake (`SYN`, `SYN-ACK`, `ACK`).
* `udp` : Displays UDP datagram traffic showing lightweight single-packet DNS/media requests.























































<!--
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To capture, inspect, and comparatively analyze Transmission Control Protocol
   (TCP) and User Datagram Protocol (UDP) packets at the Transport Layer using
   Wireshark Packet Analyzer on Linux/Ubuntu.

2. THEORY:
   - Transport Layer Role: Provides logical process-to-process communication
     using 16-bit port numbers (0 to 65535).
   - TCP Characteristics & Header:
     * Header size: 20 to 60 bytes (variable length via Options).
     * Control Flags: SYN, ACK, FIN, RST, PSH, URG.
     * 3-Way Handshake:
       1. Client -> Server: [SYN], Seq = x
       2. Server -> Client: [SYN, ACK], Seq = y, Ack = x + 1
       3. Client -> Server: [ACK], Seq = x + 1, Ack = y + 1
     * Guaranteed reliable delivery through sequence numbers, cumulative ACKs,
       and sliding window flow control.
   - UDP Characteristics & Header:
     * Fixed 8-byte header: Source Port, Destination Port, Length, Checksum.
     * Connectionless, lightweight, best-effort delivery without handshakes or ACKs.

3. EXPLANATION / PROCEDURE:
   - Step 1: Start Wireshark packet capture on active Linux network interface.
   - Step 2: Generate TCP traffic using curl -I http://google.com or running Exp-02/03.
   - Step 3: Apply filter: tcp.flags.syn == 1 || tcp.port == 8080.
   - Step 4: Inspect 3-way handshake segments, sequence/acknowledgment numbers,
     window size, and connection teardown (FIN/ACK).
   - Step 5: Generate UDP traffic using dig google.com or Exp-04/05.
   - Step 6: Filter udp.port == 53 || udp.port == 8081 and inspect the 8-byte header.

4. CONCLUSION:
   Successfully inspected and compared Transport Layer protocols using Wireshark.
   Validated TCP connection establishment, sequence numbering, and reliable delivery
   mechanisms against UDP connectionless, lightweight datagram transmission.

5. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   * Launch Wireshark packet capture:
     sudo wireshark &
   * Filter TCP 3-Way Handshake & data:
     tcp.flags.syn == 1 || tcp.port == 8080
   * Filter UDP datagram traffic:
     udp.port == 53 || udp.port == 8081
   * Generate sample TCP traffic:
     curl -I http://google.com
   * Generate sample UDP traffic:
     dig google.com
   -----------------------------------------------------------------------------
================================================================================
-->
