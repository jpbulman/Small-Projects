#lang racket

(define (pal? num)
  (local [(define numstr (number->string num))]
    (if (even? (string-length numstr))
        (string=?  (substring numstr 0 (/ (string-length numstr) 2)) (reverse-string (substring numstr (/ (string-length numstr) 2) (string-length numstr))))
        (error ""))));!!! 989

(define (reverse-string str)
  (if (= (string-length str) 1)
      str
  (string-append (substring str (- (string-length str) 1) (string-length str)) (reverse-string (substring str 0 (- (string-length str) 1))))))