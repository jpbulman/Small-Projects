#lang racket

#;(define ones (lambda () (cons 1 ...)))
;... needs to be a stream

(define ones (lambda () (cons 1 ones)))
;Recursive call at the end
;Returns a pair: element and then procedure
;Not a direct function, but needs to be called because it is a thunk

(car (ones))

(car ((cdr (ones))))

;---------------------------------------------------------------

(define (f x) (cons x (lambda() (f (+ x 1)))))

(define nats (lambda() (f 1)))

(car ((cdr (f 4))))
;5

