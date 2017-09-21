;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname |Problem1(solved)|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;Signature: (listof Natural) -> Natural
;Purpose: To sum a list
(check-expect (sum (list 1 2 3)) 6)
(define (sum list)
  (foldl + 0 list))

;Signature: Natural Natural Natural -> (listof Natural)
;Takes a natural and a maximum and finds all of the multiples of the both naturals under the max
(check-expect (multiples 1 1 10) (list 1 2 3 4 5 6 7 8 9 10))
(check-expect (multiples 10 10 10) (list 10))
(define (multiples n1 n2 max)
  (filter (lambda(x) (or (integer? (/ x n1)) (integer? (/ x n2)))) (build-list max add1)))

(sum (append (multiples 3 5 999)))
                              
              