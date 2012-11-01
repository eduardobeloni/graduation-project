/* ... */
mark((HeapPtr)threadpool);
mark((HeapPtr)taskpool);
mark((HeapPtr)awayRemote);
newtop = compact();
update_pointers(newtop);

threadpool = (Thread *)get_forward(threadpool);
taskpool = (Remote *)get_forward(taskpool);
awayRemote = (Remote *)get_forward(awayRemote);
/* ... */
