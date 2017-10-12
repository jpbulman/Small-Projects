#lang racket

;Given a non-empty string and an int n, return a new string where the char at index n has been removed. The value of n will be a valid index of a char in the original string

(define (fn-for-string str n)
  (string-append (substring str 0 n) (substring str (+ 1 n) (string-length str))))