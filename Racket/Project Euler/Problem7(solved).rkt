;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname |Problem7(solved)|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;#lang racket

;By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
;
;What is the 10 001st prime number?

;Prime?
;Num->Boolean
(define (prime? num)
  (local [(define lot (build-list (- num 2) (lambda(x) (+ x 2)))) ;Excludes 0,1, and the number itself
          (define (prime n list)
            (cond [(empty? list) true]
                  [(integer? (/ n (first list))) false]
                  [else (prime n (rest list))]))]
    (prime num lot)))

(define (makeprimelist length0)
  (local [(define (primelist where looklength done)
            (cond [(= (length done) looklength) done]
                  [(prime? where) (primelist (+ 1 where) looklength (cons where done))]
                  [else (primelist (+ 1 where) looklength done)]))] (primelist 2 length0 empty)))

(first (makeprimelist 10001))
