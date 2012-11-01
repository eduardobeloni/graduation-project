/* ... */ 
threadpool = (Thread *)evacuateThread(threadpool);
taskpool = (Remote *)evacuate((HeapPtr)taskpool);
awayRemote = (Remote *)evacuate((HeapPtr)awayRemote);

ptr = toSpace;                             
while (ptr < tsTop)
 ptr = scavenge(ptr);
heaptop = tsTop;
