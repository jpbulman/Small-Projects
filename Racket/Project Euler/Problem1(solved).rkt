#lang racket

;If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
;
;Find the sum of all the multiples of 3 or 5 below 1000.


;Signature: (listof Natural) -> Natural
;Purpose: To sum a list
;(check-expect (sum (list 1 2 3)) 6)
(define (sum list)
  (foldl + 0 list))

;Signature: Natural Natural Natural -> (listof Natural)
;Takes a natural and a maximum and finds all of the multiples of the both naturals under the max
;(check-expect (multiples 1 1 10) (list 1 2 3 4 5 6 7 8 9 10))
;(check-expect (multiples 10 10 10) (list 10))
(define (multiples n1 n2 max)
  (filter (lambda(x) (or (integer? (/ x n1)) (integer? (/ x n2)))) (build-list max add1)))

(sum (multiples 3 5 999))