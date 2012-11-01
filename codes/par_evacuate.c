HeapPtr par_evacuate(HeapPtr heapcell, deque *deq, int me) {
 switch(heapcell[0])
 {
  case SIMPLE_OBJECT:
   SimpleObject *sobj = (SimpleObject *)par_allocToSpace(vmsizeof(SimpleObject), heapcell, me);
   if(!sobj) return (HeapPtr)get_forward(heapcell);
   *sobj = *((SimpleObject *)heapcell);
   return sobj;

  case POINTER_OBJECT:
   PointerObject pobj = (PointerObject *)par_allocToSpace(objsize(heapcell), heapcell, me);
   if(!pobj) return (HeapPtr)get_forward(heapcell);
   *pobj = *((PointerObject *)heapcell);

   pobj->pointers = pobj + vmsizeof(PointerObject);
   for(int i = 0; i < pobj->sizePoint; i++)
   {
    pobj->pointers[i] = ((PointerObject *)heapcell)->pointers[i];
    deque_push_bottom(deq, &pobj->pointers[i]);
   }
   return pobj;
 }
}
