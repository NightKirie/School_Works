(defvar *file1List* '())    
(defvar *file2List* '())   
(defun diff (file1Path file2Path)
    ;; Store each line in file1.txt to a list
    (with-open-file (stream file1Path)
        (do ((line (read-line stream nil) (read-line stream nil)))
            ((null line))
            (if (null *file1List*)
                (setq *file1List* (list line))
                (push line (cdr (last *file1List*)))
            )
        )
    )
    
    ;; Store each line in file2.txt to a list
    (with-open-file (stream file2Path)
        (do ((line (read-line stream nil) (read-line stream nil)))
            ((null line))
            (if (null *file2List*)
                (setq *file2List* (list line))
                (push line (cdr (last *file2List*)))
            )
        )
    )
    
    ;; Calculate shorest supersequence
    (shortestSuperSeq)
)
(defun shortestSuperSeq()
    (let 
        ((m (list-length *file1List*))  
        (n (list-length *file2List*)) 
        (dp)
        (index)
        (i)
        (j)
        (output '()))
    
    ;; dp[i][j] contains length of shortest supersequence for file1List[0..i-1] and file2List[0..j-1]
    (setq dp (make-array (list (+ m 1) (+ n 1))))
    
    ;; Fill table in bottom up manner 
    (dotimes (i (+ m 1))
        (dotimes (j (+ n 1))
            ;; Below steps follow recurrence relation 
            (cond 
                ((equal i 0) 
                    (setf (aref dp i j) j))
                ((equal j 0) 
                    (setf (aref dp i j) i))
                ((equal (nth (- i 1) *file1List*) (nth (- j 1) *file2List*)) 
                    (setf (aref dp i j) (+ 1 (aref dp (- i 1) (- j 1)))))
                (t 
                    (setf (aref dp i j) (+ 1 (min (aref dp (- i 1)  j) (aref dp i (- j 1))))))
            )
        )
    )
    
    ;; index = dp[m][n] stores the length of the shortest supersequence of file1List and file2List
    (setq index (aref dp m n))
    (setq i m)
    (setq j n)
    
    ;; Start from the bottom right corner and one by one, push characters in the output  
    (loop while (and (> i 0) (> j 0))
        do
        ;; If current code line in file1List and file2List are same, then current code line is part of shortest supersequence
        (cond 
            ((equal (nth (- i 1) *file1List*) (nth (- j 1) *file2List*))
                (progn 
                    (push (concatenate 'string " "(nth (- i 1) *file1List*)) output)
                    (decf i)
                    (decf j)
                    (decf index)))
            ;; If current code line in file1List and file2List are different
            ((< (aref dp (- i 1) j) (aref dp i (- j 1)))
                (progn 
                    (push (concatenate 'string "-" (nth (- i 1) *file1List*)) output)
                    (decf i)
                    (decf index)))    
            (t    
                (progn 
                    (push (concatenate 'string "+" (nth (- j 1) *file2List*)) output)
                    (decf j)
                    (decf index)))
        )
    ) 
    ;; If file2List reaches its end, put remaining code line of file1List in the output
    (loop while (> i 0)
        do
        (push (concatenate 'string "-" (nth (- i 1) *file1List*)) output)
        (decf i)
        (decf index)
    )
    ;; If file1List reaches its end, put remaining code line of file2List in the output
    (loop while (> j 0)
        do
        (push (concatenate 'string "+" (nth (- j 1) *file2List*)) output)
        (decf j)
        (decf index)
    )

    ;; Print out the shortest supersequence code
    (loop for line in output
        do (format t "~a~%" line)
    )
    ) 
)
(diff "file1.txt" "file2.txt")
