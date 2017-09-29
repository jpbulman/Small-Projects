;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname graphs) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
(define-struct room (name exits))

(define H3
  (shared ((-0- (make-room "A" (list (make-room "B" (list (make-room "C" (list -0-)))))))) -0-))

(define H3.0
  (shared ((-A- (make-room "A" (list -B-)))
           (-B- (make-room "B" (list -C-)))
           (-C- (make-room "C" (list -A-)))) -A-))

;Structural recursion
;Encapsulated with local
;Tail recursive w/ worklist and w/ a context preserving accumulator

(define (fn-for-house r0)
  ;todo is a worklist accumulator
  ;visited is a context preserving accumulator
  (local [(define (fn-for-room r todo visited)
            (if (member (room-name r) visited)
                (fn-for-lor todo visited)
                (fn-for-lor (append (room-exits r) todo) (cons (room-name r) visited))))
            (define (fn-for-lor todo visited)
              (cond [(empty? todo) (...)]
                    [else
                     (fn-for-room (first todo) (rest todo) visited)]))]
(fn-for-room r0 empty empty)))


(define (reachable? r0 rn)
  ;todo is a worklist accumulator
  ;visited is a context preserving accumulator
  (local [(define (fn-for-room r todo visited)
            (if (string=? (room-name r) rn)
                true
                (if (member (room-name r) visited)
                    (fn-for-lor todo visited)
                    (fn-for-lor (append (room-exits r) todo) (cons (room-name r) visited)))))
          (define (fn-for-lor todo visited)
            (cond [(empty? todo) false]
                  [else
                   (fn-for-room (first todo) (rest todo) visited)]))]
    (fn-for-room r0 empty empty)))

