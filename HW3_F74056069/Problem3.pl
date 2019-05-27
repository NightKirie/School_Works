% Check if A to B has a route, the node that visited is initialized as empty
connected(A, B) :- 
    walk(A, B, []) -> nb_getval(output, L), nb_setval(output, ["Yes" | L])
                    ; nb_getval(output, L), nb_setval(output, ["No" | L]).

walk(A,B,V) :-      
    edge(A,X) ,        % If A is connected to X, 
    not(member(X,V)) , % And hasn't visited X
    (B =:= X ; walk(X,B,[A|V])).   % X is B, or X has a route to B, then add A to the visited list

% Create graph with N edges, recursively N times
create_graph(NodeNum) :-
    N is NodeNum - 1,
    N >= 0 -> (read(A),
               read(B),
               assert(edge(A, B)), 
               assert(edge(B, A)),  % Need to add both A to B and B to A as edge
               create_graph(N))
            ; !.

% Find if A & B has a route, with input A & B for N times
has_connect(QueryNum) :-
    N is QueryNum - 1,
    N >= 0 -> (read(A), 
               read(B),
               connected(A, B),
               has_connect(N))
            ; !.

% Print out the answer in the global list
print_ans(QueryNum) :-
    N is QueryNum - 1,
    N >= 0 -> (nb_getval(output, List),
               nth0(N, List, Ans),
               writeln(Ans),
               print_ans(N))
            ; !.

main :-
    nb_setval(output, []),  % Global list for store ans
    read(_),  % Input of node number is useless ???
    read(EdgeNum),
    create_graph(EdgeNum),
    read(QueryNum),
    has_connect(QueryNum),
    print_ans(QueryNum).

:- initialization(main). 