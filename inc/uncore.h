#ifndef UNCORE_H
#define UNCORE_H

#include <cstdint>
#include "champsim.h"
#include "cache.h"
#include "dram_controller.h"
//#include "drc_controller.h"

//#define DRC_MSHR_SIZE 48

// uncore
class UNCORE {
  public:

    // LLC
    CACHE LLC{"LLC", LLC_SET, LLC_WAY, LLC_SET*LLC_WAY, LLC_WQ_SIZE, LLC_RQ_SIZE, LLC_PQ_SIZE, LLC_MSHR_SIZE};

    // DRAM
    MEMORY_CONTROLLER DRAM{"DRAM"}; 

    // cycle
    uint64_t cycle;

    UNCORE(); 
};

extern UNCORE uncore;

#endif
