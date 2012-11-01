parfib n = if(n <= 1) then 1
   else let fib2 = par (parfib (n-2));
            fib1 = par (parfib (n-1))
        in (sync fib2) + (sync fib1);

main = parfib 20
