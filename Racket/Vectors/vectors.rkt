#lang racket

;Something to do to study for CS and Calc
;There are some built in vectors in Racket, but things like cross and dot product are not bulit in
;JP Bulman


;Fix: ad-cb should be ad-bc

(define-struct vector (v1 v2 v3))

;Points are just lists
(define-syntax point
  (syntax-rules()
    [(point e1 e2 e3 ...) (append (list e1) (point e2 e3 ...))]
    [(point e1) (list e1)]))

#;(define-syntax pointdis
  (syntax-rules()
    [(pointdis p1 p2) (sqrt (+ (sqr (- (first p2) (first p1)))))]))

(define-syntax nvector
  (syntax-rules()
    [(vector n1 n2 n3)
     (make-vector n1 n2 n3)]))

(define-syntax v1
  (syntax-rules()
    [(v1 vect)
     (vector-v1 vect)]))

(define-syntax v2
  (syntax-rules()
    [(v2 vect)
     (vector-v2 vect)]))

(define-syntax v3
  (syntax-rules()
    [(v3 vect)
     (vector-v3 vect)]))

(define vect1 (nvector 2 1 3))
(define vect2 (nvector 3 4 5))

(define i (vector 1 0 0))
(define j (vector 0 1 0))
(define k (vector 0 0 1))

;Most functions return a string, so it's not good in the sense that it does not return a type that is reusable
;Might be something to look into fixing, but seems kind of hard

;Vector->String
(define (ijk vect)
  (string-append (number->string (v1 vect)) "i+" (number->string (v2 vect)) "j+" (number->string (v3 vect)) "k"))

;Vecttor->Number
(define (magnitude vect)
  (sqrt (+ (sqr (v1 vect)) (sqr (v2 vect)) (sqr (v3 vect)))))

;Vector->Number
(define (dotproduct u v)
  (+ (* (v1 u) (v1 v)) (* (v2 u) (v2 v)) (* (v3 u) (v3 v))))

;Vector->string
(define (unitvector vect)
  (local [(define mag (magnitude vect))]
    (string-append (ijk vect) "/" (number->string mag))))

;Vector Vector -> Number
(define (anglebetween u v)
  (acos (/ (dotproduct u v)  (* (magnitude u) (magnitude v)))))

;Macro of cross-product
(define-syntax x
  (syntax-rules()
    [(x u v)
     (crossproduct u v)]))
              
; u x v =
;
; |i  j  k |
; |u1 u2 u3| = |u2 u3|     |u1 u3|     |u1 u2|
; |v1 v2 v3|   |v2 v3| i - |v1 v3| j + |v1 v2| k = ((u2*v3)-(v2*u3))i - ((u1*v3)-(v1*u3))j + ((u1*v2)-(v1*u2))k

(define (crossproduct u v)
  (string-append (number->string (- (* (v2 u) (v3 v)) (* (v2 v) (v3 u)))) "i-" (number->string (- (* (v1 u) (v3 v)) (* (v1 v) (v3 u)))) "j+" (number->string (- (* (v1 u) (v2 v)) (* (v1 v) (v2 u)))) "k"))
               
