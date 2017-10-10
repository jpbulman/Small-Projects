;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname backtracking) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
(define-struct X (root children))

(define (backtracking x)
  (local [(define (fn-for-x x)
            (...(fn-for-lox (x-children x))))

          (define (fn-for-lox lox)
            (cond [(empty? lox) false]
                  [else
                   (local [(define tester (first lox))
                           (define (fn-for-x x)
                             (if (not (false? tester))
                                 tester
                                 (fn-for-lox (rest lox))))])]))] (fn-for-x x)))