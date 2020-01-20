(defun rev (list)
    (cond
        ((null list) '())
        (T (append (rev (cdr list)) (list (car list)))))
)
(defun palindrome (list)
    (let ((revList (rev list)))
        (if (equal list revList)
            (format t "~a is palindrome~%" list)
            (format t "~a is not palindrome~%" list))
    )    
)

(palindrome '(a b c ) )
(palindrome '(m a d a m))
(palindrome '(cat dog))
(palindrome '())
(palindrome '(cat dog bird bird dog cat))