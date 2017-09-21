;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname skipper) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Skips the even positions in a list
; Takes out every other entry
(define (skip1 list)
  (local
    [(define (skip1 lox acc)
       (cond [(empty? lox) empty]
             [else
              (if (odd? acc)
                  (cons (first lox) (skip1 (rest lox) (+ acc 1)))
                  (skip1 (rest lox) (+ acc 1)))]))] (skip1 list 1)))


; Tmeplate
#;
(define (skip1 list)
  (local
    [(define (skip1 lox acc)
       (cond [(empty? lox) (...acc)]
             [else
              (... acc (first lox)
                   (skip1 (rest lox) (...acc)))]))] (skip1 list ...)))

;More abstract, skip the nth term
;Skips every nth term in a list
(define (n-skipper list n)
  (local
    [(define (skip1 lox acc)
       (cond [(empty? lox) empty]
             [else
              (if (integer? (/ acc n))
                  (skip1 (rest lox) (+ acc 1))
                  (cons (first lox) (skip1 (rest lox) (+ acc 1))))]))] (skip1 list 1)))
