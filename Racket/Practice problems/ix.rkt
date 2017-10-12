#lang racket

;Return true if the given string begins with "mix", except the 'm' can be anything, so "pix", "9ix" .. all count.

;String->Boolean

(define (ixfun str)
  (if (string=? (substring str 1 3) "ix")
      true
      false))