# Experiment 6: Analysis of Application Layer Packet (DNS) using DNS cmd & Wireshark

## Objectives
* Perform domain name system lookups using CLI utility commands (`nslookup`).
* Capture and analyze DNS queries and responses using Wireshark packet analyzer.

## Key Concepts & Observations
* **DNS Protocol:** Operates at the Application Layer, translating human-readable domain names into IP addresses. Uses **UDP Port 53**.
* **Commands Executed:**
  ```powershell
  nslookup google.com
  nslookup -type=ns bing.com
  ```

### Wireshark Header Analysis:

Query Header: Identifies transaction ID, flags (Standard query 0x0000), and domain query name.

Response Header: Contains Answer RRs (Resource Records), TTL (Time to Live), and authoritative server details.























































<!--
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To analyze Application Layer Domain Name System (DNS) protocol transactions
   by performing forward and authoritative name lookups using CLI utility
   commands (`nslookup`) and capturing/inspecting DNS packets using Wireshark.

2. THEORY:
   - DNS Protocol: A distributed, hierarchical database system operating at the
     Application Layer. Translates human-readable Fully Qualified Domain Names
     (FQDN) into numerical IP addresses.
   - Port & Transport: Uses UDP port 53 for standard lookups (fast, low overhead);
     uses TCP port 53 for responses exceeding 512 bytes or zone transfers.
   - Resource Record (RR) Types:
     * A: Hostname to 32-bit IPv4 address.
     * AAAA: Hostname to 128-bit IPv6 address.
     * NS: Authoritative Name Server for the domain.
     * CNAME: Canonical Name (alias to true domain name).
     * MX: Mail Exchange server priority and address.
   - DNS Packet Structure (12-byte header):
     * Transaction ID (16 bits): Correlates query with response.
     * Flags (16 bits): QR (0=Query, 1=Response), Opcode, AA (Authoritative Answer),
       RD (Recursion Desired), RA (Recursion Available), RCODE.
     * Question, Answer, Authority, and Additional RR count fields.

3. STEPS FOR PERFORMANCE (ON UBUNTU / LINUX):
   Step 1: Open Terminal (`Ctrl + Alt + T`) and launch Wireshark:
           sudo wireshark &
           (If missing: sudo apt install wireshark)
   Step 2: In Wireshark, double-click active interface (e.g. eth0, wlan0) to start capture.
   Step 3: In filter toolbar, type: `dns || udp.port == 53` and press Enter.
   Step 4: Return to Terminal and run DNS query:
           nslookup google.com
   Step 5: Run authoritative name server query:
           nslookup -type=ns google.com
   Step 6: In Wireshark, click red Stop button.
   Step 7: Inspect DNS Query packet: note Transaction ID, Flags (0x0100), QNAME.
   Step 8: Inspect DNS Response packet: verify same Transaction ID, Flags (0x8180),
           and resolved IP address list in Answer section.

4. EXPLANATION / PROCEDURE:
   - Step 1: Run nslookup google.com in Ubuntu terminal to query default DNS resolver.
   - Step 2: Run nslookup -type=ns google.com to query authoritative name servers.
   - Step 3: Launch Wireshark (sudo wireshark) and select active interface (e.g. eth0, wlan0).
   - Step 4: Apply display filter: dns || udp.port == 53.
   - Step 5: Execute query in terminal and observe captured frames in Wireshark.
   - Step 6: Inspect Query header (QR=0, RD=1, QNAME, QTYPE=A) and Response header
     (QR=1, RA=1, TTL, Answer RRs with resolved IP).

5. CONCLUSION:
   Successfully performed domain name resolution using nslookup and analyzed DNS
   application layer packets using Wireshark on Linux. Verified the 12-byte header
   format, transaction ID matching, recursion flags, and resource record structure.

6. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   * Run forward DNS lookup:
     nslookup google.com
   * Run authoritative name server lookup:
     nslookup -type=ns google.com
   * Launch Wireshark on Ubuntu:
     sudo wireshark &
   * Wireshark Display Filter:
     dns || udp.port == 53
   -----------------------------------------------------------------------------
================================================================================
-->
