;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname mutualrecursion) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
;Mutual Recursion

(define (fn-for-x x)
  (...(x-component1 x)
      (x-component2 x)
      (...)
      (x-componentn x)
      (fn-for-lox (x-children x))))

(define (fn-for-lox lox)
  (cond [(empty? lox) (...)]
        [else
         (... (fn-for-x (first lox))
              (fn-for-lox (rest lox)))]))