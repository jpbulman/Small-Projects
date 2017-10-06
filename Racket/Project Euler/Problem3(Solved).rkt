;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname |Problem3(Solved)|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;The prime factors of 13195 are 5, 7, 13 and 29.
;
;What is the largest prime factor of the number 600851475143 ?


(define (find-f2f num)
  (local 
    [(define (find-first-two-factors n acc)
       (if (integer? (/ n acc))
           (list acc (/ n acc))
           (find-first-two-factors n (- acc 1))))]
    (find-first-two-factors num (- num 1))))

(define (pf num)
  (local
    [(define (fn-for-factors n)
       (if (= 1 (first (find-f2f n)))
           (cons n empty)
           (fn-for-lof (find-f2f n))))
     (define (fn-for-lof lof)
       (cond [(empty? lof) empty]
             [else
              (append (fn-for-factors (first lof)) (fn-for-lof (rest lof)))]))] (fn-for-factors num)))

(first (pf 600851475143));First prime factor will be the largest,

