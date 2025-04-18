# Reinforcement-Learning-Based-Prefetching-Using-Access-Frequency-Weighting
## Table of Contents
1. [What is Reinforcement Learning Based Prefetching Using Access Frequency Weighting?](#what-is-reinforcement-learning-based-prefetching-using-access-frequency-weighting)
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

## What is Reinforcement Learning Based Prefetching Using Access Frequency Weighting?
This project introduces Pythia-AF, an enhanced version of the RL-based Pythia prefetcher. It applies Access Frequency Weighting (AFW) to guide prefetch decisions using the recurrence of memory access patterns. By modifying the reward function to prioritize frequent accesses, the prefetcher becomes more accurate, timely, and efficient—reducing cache pollution and memory bandwidth waste.


## About the Framework
The project builds on the Pythia hardware prefetcher, a reinforcement learning-based system that dynamically learns how to issue prefetches based on observed memory behavior. Our contributions include:
1) Adding a lightweight counter vector to track offset frequency
2) Modifying the SARSA reward function to factor in frequency weighting
3) Achieving improved IPC, reduced LLC misses, and smarter prefetch depth decisions
4) Total added overhead? Just +0.04 KB per core.

## Prerequisites
Make sure the following packages and tools are installed:
1) Ubuntu 24.04 (or compatible Linux environment)
2) Oracle VirtualBox (for VM testing)
3) G++ 6.3.0
4) CMake 3.20.2
5) Perl 5.24.1 (make sure PERL5LIB is properly configured)
6) Python 3.x with:
   1. pandas
   2. matplotlib

## Installation
0. Install necessary prerequisites
```bash
sudo apt install perl
```

1. Clone the GitHub repo
```bash
git clone https://github.com/CMU-SAFARI/Pythia.git
```

2. Clone the bloomfilter library inside Pythia home directory
```bash
cd Pythia
git clone https://github.com/mavam/libbf.git libbf
```

3. Build bloomfilter library. This should create the static libbf.a library inside build directory
```bash
cd libbf
mkdir build && cd build
cmake ../
make clean && make
```

4. Build Pythia for single/multi core using build script. This should create the executable inside bin directory.
```bash
cd $PYTHIA_HOME
# ./build_champsim.sh <l1_pref> <l2_pref> <llc_pref> <ncores>
./build_champsim.sh multi multi no 1
```

Please use build_champsim_highcore.sh to build ChampSim for more than four cores.

5.Set appropriate environment variables as follows:
```bash
source setvars.sh
```
## Preparing Traces
1. Use the download_traces.pl perl script to download all traces, except Ligra and PARSEC.
```bash
mkdir $PYTHIA_HOME/traces/
cd $PYTHIA_HOME/scripts/
perl download_traces.pl --csv artifact_traces.csv --dir ../traces/
```
Note: The script should download 138 traces. Please check the final log for any incomplete downloads.

2. Once the trace download completes, please verify the checksum as follows. Please make sure all traces pass the checksum test.
```bash
cd $PYTHIA_HOME/traces
md5sum -c ../scripts/artifact_traces.md5
```
3. Download the Ligra and PARSEC traces from these repositories:
[Ligra](https://doi.org/10.5281/zenodo.14267977)
[PARSEC 2.1](https://doi.org/10.5281/zenodo.14268118)

4. If the traces are downloaded in some other path, please change the full path in `experiments/MICRO21_1C.tlist` and `bash experiments/MICRO21_4C.tlist` accordingly.

## Experimental Workflow
Our experimental process is divided into two main stages: (1) running the experiments and (2) aggregating statistics from the results
## Launching Experiments
1. To create necessary experiment commands in bulk, we will use `scripts/create_jobfile.pl`
2. `create_jobfile.pl` requires three necessary arguments:
   - `exe` : the full path of the executable to run  
   - `tlist` : contains trace definitions  
   - `exp` : contains knobs of the experiments to run
3. Create experiments as follows. Please make sure the paths used in tlist and exp files are appropriate.
   ``` bash
   cd $PYTHIA_HOME/experiments/
   perl ../scripts/create_jobfile.pl --exe $PYTHIA_HOME/bin/perceptron-multi-multi-no-ship-1core --tlist MICRO21_1C.tlist --exp MICRO21_1C.exp --local 1 > jobfile.sh
   ```
4. Go to a run directory (or create one) inside experiements to launch runs in the following way:
   ``` bash
   cd experiments_1C
   source ../jobfile.sh
   ```
5. If your system uses Slurm to manage multiple jobs on a compute cluster, be sure to pass `--local 0` to `create_jobfile.pl`.

## Rolling-up Statistics
1. To aggregate statistics in bulk, use the `scripts/rollup.pl` script.
2. This script requires the following three arguments:
   - `tlist`: defines the traces
   - `exp`: specifies experiment configurations
   - `mfile`: lists the statistic names and the method used for reduction
3. Rollup statistics as follows. Make sure the file paths provided in the `tlist` and `exp` files are correct.
   ``` bash
   cd experiements_1C/
   perl ../../scripts/rollup.pl --tlist ../MICRO21_1C.tlist --exp ../MICRO21_1C.exp --mfile ../rollup_1C_base_config.mfile > rollup.csv
   ```
4. Open the `rollup.csv` file in your preferred data analysis tool (such as Python Pandas, Excel, or Numbers) to explore and interpret the results.

