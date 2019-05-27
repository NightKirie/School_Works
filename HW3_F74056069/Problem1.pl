% Default set 2 & 3 as a prime
is_prime(2) :- !.
is_prime(3) :- !.
% If N > 3, and first check if has 2 or 3 as a factor(for better performance), then using loop to check factor greater equal than 5
is_prime(N) :- 
    integer(N), 
    N > 3, 
    N mod 2 =\= 0,
    N mod 3 =\= 0,
    \+ has_factor(N, 5). 

% If N <= L * L, check if L is N's factor
has_factor(N, L) :- 
    L * L =< N, 
    factor_loop(N, L).

% If L or L+2 is N's factor, return true, otherwise keep searching
factor_loop(N, L) :- 
    N mod L =:= 0;
    N mod (L+2) =:= 0;
    has_factor(N, L+6).

% Default set the minimun of goldbach number 4's output is [2, 2]
goldbach(4,[2,2]).
% If N is even number, > 4, recursively find the goldbach pair, starting one of the number is 3 (minimun prime number greater than 2)
goldbach(N,L) :-
    N mod 2 =:= 0,
    N > 4,
    goldbach(N,L,3).
% If P + Q = N, Q is a prime, Q > P, then [P, Q] is an answer pair, if P < Q then redo goldbach(N, L, P)
goldbach(N,[P,Q],P) :-
    Q is N - P,
    is_prime(Q), 
    format("~s ~d ~d ~n", ["output:", P, Q]),
    P >= Q.
% Get the next prime, then do goldbach again, if P1 > N / 2, then stop the recursion
goldbach(N,L,P) :-
    P < N,
    next_prime(P,P1),
    P1 =< N / 2 -> goldbach(N,L,P1)
                ;!.

% Check if P+2 is prime
next_prime(P,P1) :- 
    P1 is P + 2, 
    is_prime(P1), !.
% If P+2 is not prime, redo this with recursively check P+2+2, until find a number is prime
next_prime(P,P1) :- 
    P2 is P + 2, 
    next_prime(P2,P1).

main :- 
    write('Input: '), 
    read(N),  
    goldbach(N, _),
    halt.
    
:- initialization(main). 