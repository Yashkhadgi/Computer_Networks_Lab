# Experiment 12: Case Study of SIT Computer Networking Laboratory Architecture

## Network Architecture Overview
* **Topology:** Star Topology.
* **Core Hardware:** 24/48-port Layer 2 Managed Switches, Central Gateway Router, UTM Firewall.
* **Media:** CAT6 Unshielded Twisted Pair (UTP) terminating into RJ45 keystone patch panels.
* **IP Scheme:** Dynamic private IPv4 subnets managed by central DHCP servers.























































<!--
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To conduct an architectural case study of the SIT Computer Networking Laboratory
   by inspecting its physical star topology, structured cabling, access switching,
   IP subnetting, default routing, and perimeter network security framework.

2. THEORY:
   - Cisco Three-Layer Hierarchical Network Model:
     * Core Layer: High-speed backbone switching traffic between campus blocks.
     * Distribution Layer: Boundary routers and UTM firewalls enforcing ACLs,
       inter-VLAN routing, and QoS.
     * Access Layer: Layer 2 managed switches providing desktop connectivity.
   - Physical & Logical Topology: Physical Star topology with CAT6 structured
     cabling terminating at patch panels in server racks.
   - IP Addressing & Services:
     * Private IPv4 address allocation (RFC 1918) leased via centralized DHCP.
     * Network Address Translation (NAT/PAT) at firewall for public internet egress.
     * VLAN segmentation isolating lab workstations from faculty/admin subnets.

3. STEPS FOR PERFORMANCE (ON WINDOWS):
   Step 1: Open Command Prompt.
   Step 2: Inspect workstation network parameters:
           ipconfig /all
   Step 3: Identify Default Gateway IP address.
   Step 4: Test LAN connectivity to Default Gateway router:
           ping -n 4 <Default_Gateway_IP>
   Step 5: View configured DNS resolver servers.
   Step 6: Inspect physical lab layout:
           Identify CAT6 drop cables, dual faceplates, rack-mounted Layer 2
           managed switches, and perimeter UTM firewall.

4. EXPLANATION / AUDIT PROCEDURE:
   - Step 1: Inspect workstation NICs, CAT6 drop cables, and dual-faceplate RJ45 sockets.
   - Step 2: Examine server rack: 24/48-port Layer 2 managed switches, 110-patch panels.
   - Step 3: Verify gateway router and UTM Firewall (Sophos/Fortinet) enforcing
     content filtering, captive portal, and bandwidth quotas.
   - Step 4: Verify default gateway and DHCP lease details from workstation terminal.

5. CONCLUSION:
   Successfully conducted an architectural case study of the SIT Computer Networking
   Laboratory. Evaluated star topology implementation, structured cabling, access
   layer switches, DHCP/NAT operations, and perimeter UTM firewall security.

6. WINDOWS AUDIT COMMANDS: COMMANDS:
   -----------------------------------------------------------------------------
   * Display default gateway routing table:
     ip route show
   * Verify configured DNS resolver:
     cat /etc/resolv.conf
   * Ping default gateway router:
     ping -c 3 $(ip route | grep default | awk '{print $3}')
   * Check DHCP lease information:
     cat /var/lib/dhcp/dhclient.leases   (OR: ip route)
   -----------------------------------------------------------------------------
================================================================================
-->
