#lang racket

;Skips every 3rd element in the lit

;List->List

(define (3rdskip list pos)
  (cond [(empty? list) empty]
        [(integer? (/ pos 3)) (3rdskip (rest list) (+ pos 1))]
        [else (cons (first list) (3rdskip (rest list) (+ 1 pos)))]))