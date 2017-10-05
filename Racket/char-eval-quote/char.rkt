#lang racket
(require 2htdp/image)

(define (rand-color)
  (begin
    (define rand1 (random 11))
    (cond [(= rand1 0) "red"]
          [(= rand1 1) "blue"]
          [(= rand1 2) "green"]
          [(= rand1 3) "purple"]
          [(= rand1 4) "orange"]
          [(= rand1 5) "black"]
          [(= rand1 6) "gold"]
          [(= rand1 7) "lime"]
          [(= rand1 8) "SteelBlue"]
          [(= rand1 9) "DarkOrchid"]
          [else "WhiteSmoke"])))

(define-syntax sq
  (syntax-rules()
    [(sq)
     (square 10 "solid" (rand-color))]))

(define ws (square 10 "outline" "white")) 

(define-syntax character
  (syntax-rules()
    [(character)
     (above (beside  ws  (sq) (sq) (sq)  ws)
            (beside  ws  (sq) (sq) (sq)  ws)
            (beside  ws  (sq) (sq) (sq)  ws)
            (beside  ws   ws  (sq)  ws   ws)
            (beside  ws  (sq) (sq) (sq)  ws)
            (beside (sq) (sq) (sq) (sq) (sq))
            (beside (sq) (sq) (sq) (sq) (sq)) )]))