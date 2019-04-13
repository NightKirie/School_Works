(defun prime (n) 
    ;; Corner cases
    (cond
        ((<= n 1) 
            (progn
                (format t "~d is not a prime~%" n)
                (return-from prime 0)))
        ((<= n 3)
            (progn 
                (format t "~d is a prime~%" n)
                (return-from prime 0)))
        ;; If n is multiple of 2 or 3, it's definitely not prime, reduce later loop time complexity
        ((or (equal (mod n 2) 0) (equal (mod n 3) 0))
            (progn
                (format t "~d is not a prime~%" n)
                (return-from prime 0)))
    )
    ;; Check if n is multiple of 5 above 
    (do ((i 5 (+ 6 i)))
        ((> i (isqrt n)))
        (if (or (equal (mod n i) 0) (equal (mod n (+ i 2)) 0))
            (progn
                (format t "~d is not a prime~%" n)
                (return-from prime 0))) 
    )
    (format t "~d is a prime~%" n)
)

(prime 2) 
(prime 239) 
(prime 999) 
(prime 17)