# Experiment 1: Basic Hardware Components & Networking Commands

## Hardware Components
* **NIC (Network Interface Card):** Hardware component enabling device connectivity to a network.
* **Switch:** Layer 2 device connecting devices within a LAN using MAC addresses.
* **Router:** Layer 3 device connecting multiple distinct networks using IP addresses.
* **UTP Cable (CAT6):** Media containing 4 twisted pairs of copper wire to reduce crosstalk.

## Essential CLI Commands
* `ping <host>`: Tests end-to-end IP reachability and round-trip time.
* `tracert <host>` / `traceroute <host>`: Displays route hops to a remote destination.
* `ipconfig` / `ifconfig`: Displays local interface IP, subnet mask, and default gateway.
* `netstat -an`: Lists all active socket connections and listening ports.
* `nslookup <domain>`: Queries DNS servers for IP address mapping.
* `arp -a`: Displays local ARP cache mapping IP addresses to MAC addresses.























































<!--
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To study and identify fundamental computer networking hardware components
   (NIC, Switch, Router, UTP CAT6 Cable) and demonstrate network diagnosis and
   configuration using essential Linux CLI commands (`ping`, `traceroute`, `ip`,
   `netstat`/`ss`, `nslookup`, `arp`).

2. THEORY:
   - Physical Layer (Layer 1):
     * NIC (Network Interface Card): Interfaces host to transmission media; holds
       a permanent 48-bit MAC address.
     * UTP CAT6 Cable: 4 twisted copper pairs to eliminate electromagnetic
       interference (EMI) and crosstalk; supports Gigabit Ethernet.
   - Data Link Layer (Layer 2):
     * Switch: Inspects incoming Ethernet frame headers, builds dynamic MAC address
       tables, and forwards frames to the designated destination port (unicast).
   - Network Layer (Layer 3):
     * Router: Interconnects logically distinct IP subnets; determines optimal
       forwarding paths across networks.
   - Diagnostic Protocols & CLI Tools:
     * ping: Uses ICMP Echo Request (Type 8) and Echo Reply (Type 0) to verify
       IP connectivity, RTT, and packet loss.
     * traceroute: Exploits IP Time-To-Live (TTL), incrementing TTL from 1 to map
       each intermediate gateway router hop.
     * ip / ifconfig: Displays IPv4/IPv6 addresses, subnet masks, and network interfaces.
     * ss / netstat: Queries kernel socket tables for active TCP/UDP sockets and ports.
     * arp / ip neigh: Displays ARP cache mapping 32-bit IPv4 addresses to 48-bit MAC addresses.
     * nslookup: Queries DNS servers over UDP/TCP port 53 to resolve domain names.

3. EXPLANATION / PROCEDURE:
   - Step 1: Inspect hardware in lab: identify NIC, RJ45 patch cables, switches, routers.
   - Step 2: Run loopback test: ping -c 4 127.0.0.1 to confirm local TCP/IP stack integrity.
   - Step 3: Check host IP configuration: ip a (or ifconfig) to note IP, subnet mask, interface.
   - Step 4: Verify external internet reachability: ping -c 4 8.8.8.8.
   - Step 5: Trace routing path: traceroute google.com to view hop-by-hop latency.
   - Step 6: Inspect active listening sockets: ss -tulnp to display open TCP/UDP ports.
   - Step 7: Inspect address resolution cache: arp -a (or ip neigh) to view IP-to-MAC resolutions.

4. CONCLUSION:
   Successfully identified core networking hardware components and demonstrated
   network diagnostic and configuration commands on Linux. Evaluated round-trip
   time, route hops, socket states, and local ARP/DNS resolution tables.

5. UBUNTU / LINUX EXECUTION COMMANDS:
   -----------------------------------------------------------------------------
   * Inspect local IP & interfaces:
     ip a   (OR: ifconfig)
   * Test network reachability (4 packets):
     ping -c 4 8.8.8.8
   * Trace route hops to destination:
     traceroute google.com   (Install if needed: sudo apt install traceroute)
   * Display active listening sockets & TCP ports:
     ss -tulnp   (OR: netstat -tulnp)
   * DNS resolution query:
     nslookup google.com
   * Inspect ARP cache table:
     arp -a   (OR: ip neigh)
   -----------------------------------------------------------------------------
================================================================================
-->
