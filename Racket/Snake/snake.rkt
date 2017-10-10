#lang racket
(require 2htdp/image)
(require 2htdp/universe)
(require lang/posn)

(define-struct wos (snake food))

(define-struct snake (image length x y dx dy))

(define-struct food (image x y))

(define score 0)
(set! score score)

(define snake-piece (square 20 "solid" "yellow"))

(define mainsnake (make-snake snake-piece 1 (+ 10 (* 20 (random 21))) (+ 10 (* 20 (random 21))) 0 0))

(define BKG (square 400 "solid" "DodgerBlue"))

(define basicfood (make-food (square 20 "solid" "orange") (+ 10 (* 20 (random 21))) (+ 10 (* 20 (random 21))))) 

(define basicws (make-wos mainsnake basicfood))


(define (main ws)
  (big-bang ws
            (on-tick tock)
            (to-draw render)
            (on-key keyhandle)))

(define (keyhandle ws key1)
  (cond [(string=? key1 "a") (begin (set! mainsnake (make-snake (snake-image (wos-snake ws)) (snake-length (wos-snake ws)) (snake-x (wos-snake ws)) (snake-y (wos-snake ws)) -5 0)) ws)]
        [(string=? key1 "d") (begin (set! mainsnake (make-snake (snake-image (wos-snake ws)) (snake-length (wos-snake ws)) (snake-x (wos-snake ws)) (snake-y (wos-snake ws)) 5 0)) ws)]))

(define (render ws)
  (place-images
   (list (snake-image (wos-snake ws))
         (food-image (wos-food ws)))
   (list (make-posn (snake-x (wos-snake ws)) (snake-y (wos-snake ws)))
         (make-posn (food-x (wos-food ws)) (food-y (wos-food ws))))
   BKG))

(define (tock ws)
  (begin (set! mainsnake (make-snake (snake-image (wos-snake ws)) (snake-length (wos-snake ws)) (+ (snake-dx (wos-snake ws)) (snake-x (wos-snake ws)))
                              (+ (snake-dy (wos-snake ws)) (snake-y (wos-snake ws))) (snake-dx (wos-snake ws)) (snake-dy (wos-snake ws))))
         ws))
  
  

(main basicws)
