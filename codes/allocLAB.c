HeapPtr allocLAB(int size) {
 HeapPtr newloc;
 pthread_mutex_lock(&guard_LAB);
 newloc = LAB_tstop;
 LAB_tstop += size;
 pthread_mutex_unlock(&guard_LAB);
 return newloc;
}
