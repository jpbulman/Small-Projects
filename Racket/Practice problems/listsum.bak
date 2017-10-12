#lang racket
(define (looksum list1 sum)
  (cond [(= 1 (length list1)) empty]
        [(= (+ (first list1) (first (rest list1))) sum) (cons (list (first list1) (first (rest list1))) (looksum (rest list1) sum))]
        [else (looksum (rest list1) sum)]))

(looksum (list 1 2 3 4 5 0 4 1) 5)