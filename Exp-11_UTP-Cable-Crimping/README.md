# Experiment 11: Study and Demonstration of UTP Cable Crimping using RJ45 Connector

## Objectives
* Study physical transmission media (CAT6 UTP) and perform modular RJ45 cable termination.

## Wiring Standards

### T568B Color Order
1. White-Orange
2. Orange
3. White-Green
4. Blue
5. White-Blue
6. Green
7. White-Brown
8. Brown

## Cable Types
* **Straight-Through Cable:** Uses identical pinouts (T568B to T568B) on both ends. Connects different devices (e.g., PC to Switch).
* **Crossover Cable:** Uses T568A on one end and T568B on the other. Connects similar devices (e.g., PC to PC).























































<!--
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To study physical transmission media (CAT6 Unshielded Twisted Pair) and
   demonstrate cable crimping using RJ45 connectors according to TIA/EIA-568A
   and TIA/EIA-568B wiring standards for Straight-Through and Crossover cables.

2. THEORY:
   - Category 6 (CAT6) UTP Cable:
     * 4 pairs (8 conductors) of 24 AWG copper wire enclosed in PVC jacket.
     * Internal spline isolates pairs, reducing Near-End Crosstalk (NEXT).
     * Supports bandwidth up to 250 MHz and speeds up to 10 Gbps.
   - RJ45 Connector: 8-Position, 8-Contact (8P8C) modular plug with gold-plated
     contact pins that pierce conductor insulation during crimping.
   - Wiring Standards (Pinouts 1 to 8):
     * T568A: White-Green, Green, White-Orange, Blue, White-Blue, Orange, White-Brown, Brown.
     * T568B: White-Orange, Orange, White-Green, Blue, White-Blue, Green, White-Brown, Brown.
   - Cable Types:
     * Straight-Through (T568B <-> T568B): Connects unlike devices (PC to Switch).
     * Crossover (T568A <-> T568B): Connects like devices (PC to PC, Switch to Switch).

3. EXPLANATION / PROCEDURE:
   - Step 1: Strip ~2 cm of outer PVC jacket using cable stripper without nicking wires.
   - Step 2: Untwist wire pairs, cut center spline, and straighten each conductor.
   - Step 3: Align conductors strictly in T568B order (White-Orange, Orange, White-Green,
     Blue, White-Blue, Green, White-Brown, Brown).
   - Step 4: Trim conductors evenly leaving ~1.2 cm exposed.
   - Step 5: Insert wires fully into RJ45 connector until pins touch copper teeth.
   - Step 6: Insert into crimping tool and press firmly to lock pins and strain relief.
   - Step 7: Test cable continuity using LAN Cable Tester (verify LEDs 1-8 light in sequence).

4. CONCLUSION:
   Successfully fabricated and tested CAT6 Ethernet cables using RJ45 connectors.
   Verified T568B pinout continuity and demonstrated Straight-Through and Crossover
   cable configurations.

5. VERIFICATION & LINUX NETWORK STATUS COMMANDS:
   -----------------------------------------------------------------------------
   * Check physical Ethernet link state:
     ip link show
   * Detailed NIC interface and link carrier inspection:
     ethtool eth0   (OR: ethtool <your_interface_name>)
   * Test cable continuity with hardware LAN Tester:
     Insert RJ45 plugs into TX and RX ports; verify LEDs 1 through 8 light in sequence.
   -----------------------------------------------------------------------------
================================================================================
-->
