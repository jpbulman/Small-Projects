#lang racket

(define hi 1)

;Aribitrary sized data can be represented with compound data
;Arbitrary is wasy with list

;Cons
;  (cons e list)
;  Puts e on the front of the list
;Constructor

;First
;(first list)
;Gets first item in a list

;Rest
;(rest list)
;Gets every element after first

;Data definition
;BSL
;Listof X is one of:
;    -empty
;    -(cons X listofX)


;List template
;Natural recursion

#;(define (fn-for-lox lox)
    (cond [(empty? lox) (...)]
          [else (... (first lox) (fn-for-lox (rest lox)))]))

;(listof str) str -> boolean
(define (containsstr? los str)
  (cond [(empty? los) false]
        [(string=? (first los) str) true]
        [else (containsstr? (rest los) str)]))

;The primitive version of list-ref
(define (getelement list0 num1)
  (local [(define (getel list num pos)
            (cond [(empty? list) false]
                  [(= pos num) (first list)]
                  [else (getel (rest list) num (+ 1 pos))]))] (getel list0 num1 0)))

;Summer
;Sums all of the elements in a list
;Primitive of foldr with + 0
;Signature: (listof numbers) -> number
(define (sum-lon lon)
  (cond [(empty? lon) 0]
        [else (+ (first lon) (sum-lon (rest lon)))]))

;More abstract
;This is the primitive version/definition of foldr
(define (fn-over-lox fn base lox)
  (cond [(empty? lox) base]
        [else (fn (first lox) (fn-over-lox fn base(rest lox)))]))

;Definition of map
;(listof X) -> (listof X)
(define (mymap fn lox)
  (cond [(empty? lox) empty]
        [else (cons (fn (first lox)) (mymap fn (rest lox)))]))

;Definition/primitive version of length
(define (mylength lox currentnum)
  (cond [(empty? lox) currentnum]
        [else (mylength (rest lox) (+ 1 currentnum))]))

;(define-struct x (e1 e2 ...))
;(make-x e1 e2 ...) make-x: constrcutor
;x-e1: selector

;x? (make-x etc) -> true
;x? - predicate

;Mutual recursion
#;(define (fn-for-x x)
  (...(x-e1 x)
      (x-e2 x)
      (...)
      (x-en x)
      (fn-for-lox (x-children x))))

#;(define (fn-for-lox lox)
    (cond [(empty? lox) (..)]
          [else (... (fn-for-x (first lox)) (fn-for-lox (rest lox)))]))

;Definiton/primitive form of filter
;(listof x) -> (listof x)
(define (myfilter fn lox)
  (cond [(empty? lox) empty]
        [(fn (first lox)) (cons (first lox) (myfilter fn (rest lox)))]
        [else (myfilter fn (rest lox))]))

;Definition of build-list
(define (mylistmake num0 fn0)
  (local [(define (mybuild num fn currentnum)
  (cond [(= currentnum num) (list (fn num))]
        [else (append (list (fn currentnum)) (mybuild num fn (+ 1 currentnum)))]))]
    (mybuild num0 fn0 1)))
  
;More basic/kosher version
;(I made the one above first, but it bothered me it didn't use cons like the others)
(define (mylistmake1 num0 fn0)
  (local [(define (mybuild num fn currentnum)
  (cond [(= currentnum num) (cons (fn num) empty)]
        [else (cons (fn currentnum) (mybuild num fn (+ 1 currentnum)))]))]
    (mybuild num0 fn0 1)))










