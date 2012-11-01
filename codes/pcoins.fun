data Pair = MKPair a b;
sumList l = case l of
        [] -> 0;
        x:xs -> x + (sumList xs);

map f l = case l of
  [] -> [];
  x:xs -> (f x) : (map f xs);

zip xs ys = case xs of
 [] -> [];
 p:ps ->  (MKPair p (head ys)): (zip ps (tail ys));

append xs ys = case xs of
  [] -> ys;
  p : ps -> p : (append ps ys);

dropWhile p xs = case xs of
  [] -> [];
  y : ys -> if (p y) then (dropWhile p ys) else (xs);

head xs = case xs of
        [] -> 0;
        a : b -> a;

tail xs = case xs of
        []-> [];
        a : b -> b;

concat = foldr append [];

foldr f z xs = case xs of
  [] -> z;
  p : ps -> f p (foldr f z ps);

mynub xs = case xs of
  [] -> [];
  p:ps ->  p : (mynub (removeDuplicates p ps));

removeDuplicates d xs = case xs of
  [] -> [];
  p : ps -> if (p == d) then (removeDuplicates d ps) else (p : (removeDuplicates d ps));

del xs y = case xs of
  [] -> [];
  p: ps -> if (y == p) then (ps) else (p : (del ps y));

pay_num pri val coins count = if (val ==0) then 1 else (paynum pri val coins count);

pay_num2 pri val coins = if (val ==0) then 1 else (paynum2 pri val coins);

paynum2 pri val coins = case coins of
  [] -> 0;
  p : ps -> let bar_coins = (dropWhile (maior val) coins) in
        sumList (map (aux2 pri val bar_coins) (mynub bar_coins));

paynum pri val coins count = case coins of
  [] -> 0;
  p : ps -> let bar_coins = (dropWhile (maior val) coins) in
        sumList (map (aux pri val bar_coins count) (mynub bar_coins));

maior a b = b>a;

aux2 pri val coins1 c 
       = pay_num2 (pri-1) (val-c) (del (dropWhile (maior c) coins1) c);

aux pri val coins1 count c =
   if (count == 0) then (pay_num2 (pri-1) (val-c) (del (dropWhile (maior c) coins1) c))
   else (pay_num  (pri-1) (val-c) (del (dropWhile (maior c) coins1) c) (count-1));

vals = 250 : 100 : 25 : 10 : 5 : 1 : [];

quants = 5 : 8 : 8 : 9 : 12 : 60 : [];

coinsz = (zip vals quants) ;

coins = concat (map separa coinsz);

separa tupla = 
   case tupla of MKPair a b -> fromupto a 1 b;

fromupto a x y = if (x==y) then (a:[]) else (a : (fromupto a (x+1) y));

main = pay_num 1000000 1473 coins 1000
