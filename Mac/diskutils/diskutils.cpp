//
//  DiskUtils.cpp
//  DiskUtils
//
//  Created by dikra-prasetya on 3/28/16.
//  Updated by Wong Yan Zhi on 4/22/24.
//  Copyright © 2016 dikra-prasetya. All rights reserved.
//

#include "DiskUtils.hpp"

int getTotalDiskSpace(){
    struct statfs statf;
    
    statfs(".", &statf);
    
    char buf[12];
    snprintf(buf, sizeof(buf), "%llu", (unsigned long long)(statf.f_blocks * statf.f_bsize / 1048576ULL));
    int ret;
    sscanf(buf, "%d", &ret);
    
    return ret;
}

int getAvailableDiskSpace(){
    struct statfs statf;
    
    statfs(".", &statf);
    
    char buf[12];
    snprintf(buf, sizeof(buf), "%llu", (unsigned long long)(statf.f_bavail * statf.f_bsize / 1048576ULL));
    int ret;
    sscanf(buf, "%d", &ret);
    
    return ret;
}

int getBusyDiskSpace(){
    struct statfs statf;
    
    statfs(".", &statf);
    
    char buf[12];
    snprintf(buf, sizeof(buf), "%llu", (unsigned long long)((statf.f_blocks - statf.f_bfree) * statf.f_bsize / 1048576ULL));
    int ret;
    sscanf(buf, "%d", &ret);
    
    return ret;
}
