;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-reader.ss" "lang")((modname diff-facts) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Slowest
(define (factorial n)
  (if (>= 0 n)
      1
      (* n (factorial (- n 1)))))

;Fastest
(define (! n)
  (foldl * 1 (build-list n add1)))

;Middle speed
(define (t! n0)
  (local
    [(define (tailf n acc)
       (cond [(= n 1) acc]
             [else
              (tailf (- n 1) (* acc n))]))]
    (tailf n0 1)))