lca(A, B) :- 
    A =:= B -> nb_getval(output, L), nb_setval(output, [A | L]);  % If A = B 
    parent(A, B) -> nb_getval(output, L), nb_setval(output, [A | L]); % If A is B's parent
    parent(A, B) -> nb_getval(output, L), nb_setval(output, [B | L]); % If B is A's parent
    (parent(X, A), lca(X, B));  % If not, recursively find X's parent with Y
    (parent(Y, B), lca(A, Y)).  % If not, recursively find Y's parent with X

% Create binary tree with N-1 relations, recursively N-1 times
create_tree(NodeNum) :-
    N is NodeNum - 1,
    N >= 0 -> (read(A),
               read(B),
               assert(parent(A, B)), 
               create_tree(N))
            ; !.

% Find A & B's lowest common ancestor, with input A & B for N times
has_lca(QueryNum) :-
    N is QueryNum - 1,
    N >= 0 -> (read(A), 
               read(B),
               lca(A, B),
               has_lca(N))
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
    read(NodeNum),
    create_tree(NodeNum-1),
    read(QueryNum),
    has_lca(QueryNum),
    print_ans(QueryNum).

:- initialization(main). 