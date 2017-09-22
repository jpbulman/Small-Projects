;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname nskip) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Keep one term, then skip n terms, keep 1, skip n, etc
;(check-expect (skipn (list 1 2 3 4 5 6 7 8 9 10 11 12 13) 3) (list 1 5 9 13))

(define (skipn list n)
  (local
    [(define (skipn lox acc)
       (cond [(empty? lox) empty]
             [else
              (if (integer? acc)
                  (cons (first lox) (skipn (rest lox) (+ (/ 1 (+ 1 n)) acc)))
                  (skipn (rest lox) (+ (/ 1 (+ 1 n)) acc)))]))]
    (skipn list 1)))

(define (skipm list n)
  (local
    [(define (skipm lox acc)
       (cond [(empty? lox) empty]
             [else
              (if (= n acc)
                  (cons (first lox) (skipm (rest lox) 0))
                  (skipm (rest lox) (+ 1 acc)))]))]
    (skipm list n)))

(skipn (list 1 2 3 4 5 6 7 8 9 10 11 12 13) 3)
(skipm (list 1 2 3 4 5 6 7 8 9 10 11 12 13) 3)