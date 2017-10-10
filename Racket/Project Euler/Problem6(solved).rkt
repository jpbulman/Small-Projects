#lang racket

;The sum of the squares of the first ten natural numbers is,
;
;12 + 22 + ... + 102 = 385
;The square of the sum of the first ten natural numbers is,
;
;(1 + 2 + ... + 10)2 = 552 = 3025
;Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
;
;Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

(define oneten (build-list 10 add1))
(define oneonehundred (build-list 100 add1))

;Sum of squares
;listof num -> num
(define (sumofsquares lon)
  (foldr + 0 (map sqr lon)))

;Square of sum
;listof num -> num
(define (squareofsum lon)
  (sqr (foldr + 0 lon)))

(- (squareofsum oneonehundred) (sumofsquares oneonehundred))