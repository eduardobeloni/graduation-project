int *mem = 0, y = 777;

void *testingCAS(void *info)
{
 int new = 999, res;
 int old = (int)info;
 pthread_t me = pthread_self();

 res = cmpxchg(mem, old, new);
 if(res == old) printf("thread %u: CAS sucess!\n", me);
 else printf("thread %u: CAS failed...\n", me);

 return 0;
}

int main(int argc, char **argv)
{
 pthread_t th[2];

 mem = &y;

 pthread_create(&th[0], 0, &testingCAS, (void *)555);
 pthread_create(&th[1], 0, &testingCAS, (void *)777);

 pthread_join(th[0], 0);
 pthread_join(th[1], 0);

 return 0;
}	
