;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname fizbiz) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(define L1
  (build-list 999 add1))

;Signature: (lisof integer) -> (listof integer | string)
;Purpose: When /3, "fiz", /5 "biz", both "fizbiz"
;Tests:
(check-expect (fiz-biz (list 1)) (list 1))
(check-expect (fiz-biz (list 3)) (list "fiz"))
(check-expect (fiz-biz (list 15)) (list "fizbiz"))
(check-expect (fiz-biz (list 5)) (list "biz"))
(check-expect (fiz-biz (list empty)) (list empty))
 
(define (fiz-biz list)
  (map which? list))

(define (which? num)
  (cond [(empty? num) empty]
        [(and (integer? (/ num 3)) (integer? (/ num 5))) "fizbiz"]
        [(integer? (/ num 3)) "fiz"]
        [(integer? (/ num 5)) "biz"]
        [else num]))

;(fiz-biz L1)
