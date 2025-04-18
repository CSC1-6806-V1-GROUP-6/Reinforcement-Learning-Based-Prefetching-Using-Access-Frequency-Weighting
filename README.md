# Reinforcement-Learning-Based-Prefetching-Using-Access-Frequency-Weighting
## Table of Contents
1. [What is Reinforcement Learning-Based Prefetching Using Access Frequency Weighting?](#what-is-reinforcement-learning-based-prefetching-using-access-frequency-weighting?)
2. [About the Framework](#about-the-framework)
3. [Prerequisites](#prerequisites)
4. [Installation](#installation)
5. [Preparing Traces](#preparing-traces)
   - [More Traces](#more-traces)
6. [Experimental Workflow](#experimental-workflow)
   - [Launching Experiments](#launching-experiments)
   - [Rolling up Statistics](#rolling-up-statistics)
7. [HDL Implementation](#hdl-implementation)
8. [Code Walkthrough](#code-walkthrough)
9. [Citation](#citation)
10. [License](#license)
11. [Contact](#contact)
12. [Acknowledgements](#acknowledgements)

What is Reinforcement Learning-Based Prefetching Using Access Frequency Weighting?
This project introduces Pythia-AF, an enhanced version of the RL-based Pythia prefetcher. It applies Access Frequency Weighting (AFW) to guide prefetch decisions using the recurrence of memory access patterns. By modifying the reward function to prioritize frequent accesses, the prefetcher becomes more accurate, timely, and efficient—reducing cache pollution and memory bandwidth waste.


About the Framework
The project builds on the Pythia hardware prefetcher, a reinforcement learning-based system that dynamically learns how to issue prefetches based on observed memory behavior. Our contributions include:
1) Adding a lightweight counter vector to track offset frequency
2) Modifying the SARSA reward function to factor in frequency weighting
3) Achieving improved IPC, reduced LLC misses, and smarter prefetch depth decisions
4) Total added overhead? Just +0.04 KB per core.

Prerequisites
Make sure the following packages and tools are installed:
1) Ubuntu 24.04 (or compatible Linux environment)
2) Oracle VirtualBox (for VM testing)
3) G++ 6.3.0
4) CMake 3.20.2
5) Perl 5.24.1 (make sure PERL5LIB is properly configured)
6) Python 3.x with:
   1. pandas
   2. matplotlib

Installation
Clone the modified Pythia framework:
