HeapPtr par_allocToSpace(int size, HeapPtr oldloc, int me)
{
 HeapPtr newloc, res;
 if((labtop[me] + size) >= (currlab[me] + LAB_SIZE))
  currlab[me] = labtop[me] = allocLAB(LAB_SIZE);

 res = cmpxchg(&forwarding[indof(oldloc)], 0, labtop[me]);
 if(res) return 0;

 newloc = labtop[me];
 labtop[me] += size;		

 return newloc;
}
