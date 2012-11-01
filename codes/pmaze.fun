data Maze = DeadEnd | Corridor a | Exit | Door;

data BBool = FFalse | TTrue;

map f l = case l of
        [] -> [];
        x:xs -> f x : map f xs;

genList x y = if (x==0) then [] else (y : (genList (x-1) y));

createMaze n maze = if (n==0) then DeadEnd 
                 else (case maze of
                            Door -> Corridor (map (createMaze (n-1)) (genList n Door) ));

ffoldr func v l = case l of
	[] -> v;
        x:xs -> func x (ffoldr func v xs);

aand a b = case a of
	TTrue -> b;
	FFalse -> FFalse;

search m = case m of
	DeadEnd -> 0;
        Exit    -> 0;
	Corridor l -> let x = sfib 18 in
                      ffoldr soma 1 (map search l);

soma x y = x + y;

sfib n = if (n<=1) then 1 else (sfib (n-1) + sfib (n-2));

createAndSearch n m = search (createMaze n m);

main = ffoldr soma 1 (map (createAndSearch 7) (genList 80 Door))
