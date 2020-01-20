;; original recursion
(defun fib1(n)
    (cond
        ((equal n 0) 0)
        ((equal n 1) 1)
        (T (+ (fib1 (- n 1)) (fib1 (- n 2)))))
)
;; tail recursion
(defun fib2(n &optional (a 0) (b 1))
    (cond
        ((equal n 0) a)
        ((equal n 1) b)
        (T (fib2 (- n 1) b (+ a b))))
)

(trace fib1)
(format t "====Tracing fib1====~%")
(fib1 3)
(trace fib2)
(format t "====Tracing fib2====~%")
(fib2 3)