#lang racket

(define g (lambda() (+ 56 78)))

(g)

;-->

(define y (thunk (+ 23 87)))

(y)