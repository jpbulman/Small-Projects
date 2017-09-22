;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname tailr) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
#;(define (sum lon0)
  (local [(define (sum lon acc)
            (cond [(empty? lon) (...acc)]
                  [else
                   (... acc
                        (first lon)
                        (sum (rest lon)
                             (.. acc)))]))]
    (sum lon0 ...a)))

;No primitive calls being built up here
;Tail recursive
(define (sum lon0)
  ; acc is a number that is the sum of the elements lon0 has seen so far
  ; (sum (list 2 4 5)  0)
  ; (sum (list   4 5)  2)
  ; (sum (list     5)  6)
  ; (sum (list      )  11)
  (local [(define (sum lon acc)
            (cond [(empty? lon) acc]
                  [else
                   ;(... acc
                   ;    (first lon)
                        (sum (rest lon)
                             (+ acc (first lon)))]))]
    (sum lon0 0)))