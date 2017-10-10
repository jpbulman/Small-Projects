;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname list) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
;List template

(define (fn-for-list list)
  (cond [(empty? list) (...)]
        [else
         (...(first list)
             (fn-for-list (rest list)))]))