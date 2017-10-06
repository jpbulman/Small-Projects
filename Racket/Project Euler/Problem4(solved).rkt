#lang racket

;A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
;
;Find the largest palindrome made from the product of two 3-digit numbers.


;Checks if a number is a palindrome
;Was a little hard with odd digit numbers, but nothing impossible
(define (pal? num)
  (local [(define numstr (number->string num))]
    (cond
      [(< (/ num 10) 1) true]
        [(even? (string-length numstr))
        (string=?  (substring numstr 0 (/ (string-length numstr) 2)) (reverse-string (substring numstr (/ (string-length numstr) 2) (string-length numstr))))]
        [else (string=?  (substring numstr 0 (/ (- (string-length numstr) 1) 2)) (reverse-string (substring numstr (+ (/ (- (string-length numstr) 1) 2) 1) (string-length numstr))))])))

;Reverses a string
(define (reverse-string str)
  (if (= (string-length str) 1)
      str
  (string-append (substring str (- (string-length str) 1) (string-length str)) (reverse-string (substring str 0 (- (string-length str) 1))))))

;Gets a list of numbers that are n times all of the three digit numbers after it ex: (3dn-up 998) = '(998*998 998*999)
;3 digit num up
(define (3dn-up num)
  (build-list (- 1000 num) (lambda(x) (* num (+ x num))))) ;1000-num, non-inclusive of a 100, gets the number of 3 digit numbers from that point on

;All 3 digit numbers
(define 3digits (build-list (- 1000 100) (lambda(x) (+ 100 x))))

;Products of all 3 digit numbers
(define 3prod (foldr append empty (map 3dn-up 3digits)))

(first (sort (filter pal? 3prod) >))
