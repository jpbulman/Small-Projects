;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-reader.ss" "lang")((modname hard) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Password maker
; String -> String
; To make a fancy password
(define (password s)
  (local
    [(define (pss str acc)
       (local
         [(define (currchar? ch) (string=? (substring str acc (add1 acc)) ch))]
         (cond [(= acc (string-length str)) ""]
               [(currchar? "a") (string-append (number->string (+ 1 (random 10))) (pss str (add1 acc)))]
               [(currchar? "b") (string-append (number->string (expt (add1 (random 5)) (add1 (random 10)))) (rand-char 1) (pss str (add1 acc)))]
               [(currchar? "c") (string-append (charlist 2) (pss str (add1 acc)))]
               [(currchar? "d") (string-append (number->string (floor (sqrt (add1 (random 100))))) (pss str (add1 acc)))]
               [(currchar? "e") (string-append (number->string (ceiling (sqrt (exp (sqrt (* 2 (add1 (random 10)))))))) (pss str (add1 acc)))]
               [(currchar? "f") (string-append (rand-char 1) (number->string (add1 (random 12))) (charlist (add1 (random 10))) (pss str (add1 acc)))]
               [(currchar? "g") (string-append (number->string (random (add1 (random 100)))) (pss str (add1 acc)))]
               [(currchar? "h") (string-append (charlist (random (add1 (random 8)))) (pss str (add1 acc)))]
               [(currchar? "i") (string-append (number->string (time (* 0 (factorial (+ 999 (random 10)))))) (pss str (add1 acc)))]
               [(currchar? "j") (string-append (rand-letter 1) (charlist 2) (rand-letter 1) (rand-char 1) (pss str (add1 acc)))]
               [(currchar? "k") 1]
               [(currchar? "l") 1]
               [(currchar? "m") 1]
               [(currchar? "n") 1]
               [(currchar? "o") 1]
               [(currchar? "p") 1]
               [(currchar? "q") 1]
               [(currchar? "r") 1]
               [(currchar? "s") 1]
               [(currchar? "t") 1]
               [(currchar? "u") 1]
               [(currchar? "v") 1]
               [(currchar? "w") 1]
               [(currchar? "x") 1]
               [(currchar? "y") 1]
               [(currchar? "z") (string-append  (pss str (add1 acc)))]
               [else 0])))]
    (pss s 0)))

; Generates a random character
(define (rand-char hi)
  (local [(define chars "abcdefghijklmnopqrstuvwxyz!@#$%^&*()-_=+[]{};:',<.>/?`~")
    (define rand (+ 1 (random 54)))]
    (substring chars rand (+ 1 rand))))

;Generates a random letter
(define (rand-letter hi)
  (local [(define letters "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
    (define rand (+ 1 (random 53)))]
    (substring letters rand (+ 1 rand))))

;Generates a random slew of 'num' characters
(define (charlist num)
  (foldl string-append "" (build-list num rand-char)))

(define (factorial n)
  (if (>= 0 n)
      1
      (* n (factorial (- n 1)))))