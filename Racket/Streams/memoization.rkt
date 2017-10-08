#lang racket

(define fibonacci
  (letrec([memo null] ;;list of pars (argument . result)
          [fib (lambda(x)
                 (let ([ans (assoc x memo)])
                   (if ans
                       (cdr ans)
                       (let ([new-ans (if (or (= x 1) (= x 2))
                                          1
                                          (+ (fib (- x 1))
                                          (fib (- x 2))))])
                         (begin
                           (set! memo (cons (cons x new-ans) memo))
                           new-ans)))))])
    fib))