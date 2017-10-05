#lang racket
(require 2htdp/image)


(define-syntax my-if
  (syntax-rules (then else)
    [(my-if e1 then e2 else e3)
     (if e1 e2 e3)]))

(define-syntax comment-out
  (syntax-rules ()
    [(comment-out ignore instead) instead]))

(define-syntax Rect
  (syntax-rules (- _)
    [(Rect w h s c )
     (rectangle w h s c)]))

(define-syntax Moo
  (syntax-rules()
    [(Moo)
    (print "Moo!")]))

(define-syntax Bork
  (syntax-rules()
    [(Bork s)
     (string-append "Bork Bork " s)]))

(define-syntax cubeface
  (syntax-rules()
    [(cubeface n)
     (above 
    (beside (square (/ n 3) "outline" "black") (square (/ n 3) "outline" "black") (square (/ n 3) "outline" "black"))
     (beside (square (/ n 3) "outline" "black") (square (/ n 3) "outline" "black") (square (/ n 3) "outline" "black"))
     (beside (square (/ n 3) "outline" "black") (square (/ n 3) "outline" "black") (square (/ n 3) "outline" "black")))]))

(define-syntax +
  (syntax-rules()
     [(+ n1 n2)
      (* n1 n2)]))

(define-syntax define
  (syntax-rules()
     [(+ n1 n2)
      (* n1 n2)]))
  




