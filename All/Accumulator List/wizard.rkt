;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-reader.ss" "lang")((modname wizard) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;https://www.youtube.com/watch?v=lHF-hciV2H4&t=351s
;Data definitions
(define-struct wiz (name house kids))
;Wizard is a (make-wizard String String (listof Wizard))
;Interp. Name, house, list of kids

(define Wa (make-wiz "A" "S" empty))
(define Wb (make-wiz "B" "G" empty))
(define Wc (make-wiz "C" "R" empty))
(define Wd (make-wiz "D" "H" empty))
(define We (make-wiz "E" "R" empty))
(define Wf (make-wiz "F" "R" (list Wb)))
(define Wg (make-wiz "G" "S" (list Wa)))
(define Wh (make-wiz "H" "S" (list Wc Wd)))
(define Wi (make-wiz "I" "H" empty))
(define Wj (make-wiz "J" "R" (list We Wf Wg)))
(define Wk (make-wiz "K" "G" (list Wh Wi Wj)))

#; ;Template for mutal recursion/arbitrary arity tree
(define (fn-for-wiz w)
  (local [(define (fn-for-a-wiz w)
            (...(wiz-namew)
                (wiz-house w)
                (fn-for-low (wiz-kids w))))
          (define (fn-for-low low)
            (cond [(empty? low) (...)]
                  [else
                   (...(fn-for-a-wiz (first low))
                       (fn-for-low (rest low)))]))]
    (fn-for-a-wiz w)))


;In mutual recursion, when you have accumulators, you must put it in both functions
;Produces the name of every descendant placed in the same house as their parent within a tree
#; (define (fn-for-wiz w)
  (local [(define (fn-for-a-wiz w parent-house)
            (...parenthouse
                (wiz-namew)
                (wiz-house w)
                (fn-for-low (wiz-kids w)
                            (...parent-house))))
          (define (fn-for-low low parent-house)
            (cond [(empty? low) (...parent-house)]
                  [else
                   (...(fn-for-a-wiz (first low) (...parent-house))
                       (fn-for-low (rest low) (...parent-house)))]))]
    (fn-for-wiz w)))



(define (same-house-as-parent w)
  ;The house of this wizard's parent
  ;"" - root of tree
  ;(fn-for-wiz Wk "")
  ;(fn-for-wiz Wh "G")
  ;(fn-for-wiz Wc "S")
  ;(fn-for-wiz Wd "S")
  ;(fn-for-wiz Wi "G")
  (local [(define (fn-for-a-wiz w parent-house)
            (if (string=? parent-house (wiz-house w))
                (cons (wiz-name w) (fn-for-low (wiz-kids w) (wiz-house w))) ;Accumulator passes house becuase it is a parent
                (fn-for-low (wiz-kids w) (wiz-house w))))
          (define (fn-for-low low parent-house)
            (cond [(empty? low) empty]
                  [else
                   (append (fn-for-a-wiz (first low) parent-house)
                           (fn-for-low (rest low) parent-house))]))]
    (fn-for-a-wiz w "")))

(same-house-as-parent Wk)







;Consumes a wizard and produces the number of wizards in the tree, tail recursively
(define (count w)
  ;rsf is an accumulator (result so far), going to be a Natural
  (local [(define (fn-for-a-wiz w rest rsf)
            (fn-for-low (append rest (wiz-kids w)) (+ 1 rsf)))
          (define (fn-for-low low parent-house rsf)
            (cond [(empty? low) rsf];produces result
                  [else
                   (fn-for-a-wiz (first low) (rest low) rsf)]))]
    (fn-for-a-wiz w empty 0)));Seen 0 wizards at the start















