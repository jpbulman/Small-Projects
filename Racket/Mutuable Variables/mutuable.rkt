;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname mutuable) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
;;Mutuable variables

(define x (+ 3 3))

(+ x 4)

(set! x (* 3 4))

(+ x 4)


(begin (+ 2 3)
       (/ 4 2))

;Throws away every one execpt for the last one
; Produces 2

(deifne c 0)

(begin (set! c (+ c 1))
       c);Will produce 1