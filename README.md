# Reinforcement-Learning-Based-Prefetching-Using-Access-Frequency-Weighting
Modern high-performance CPUs face a familiar bottleneck: memory latency. Traditional hardware prefetchers struggle with irregular memory patterns, often wasting bandwidth and polluting the cache. Our project introduces a smarter solution—Pythia-AF, an optimized version of the RL-based Pythia prefetcher, augmented with Access Frequency Weighting (AFW) to improve prefetch accuracy, efficiency, and adaptability.

What We Built
We reimagined the Pythia hardware prefetcher by integrating access frequency signals directly into its reinforcement learning reward function. Instead of treating all memory accesses equally, our prefetcher prioritizes high-frequency memory patterns, enabling smarter, faster learning and more efficient resource use.
