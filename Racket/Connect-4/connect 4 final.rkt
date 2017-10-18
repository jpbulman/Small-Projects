;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname |connect 4 final|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)

;;JP Bulman and Maya Sun

;; do not modify the constants
(define RED 1) 
(define BLACK 2)
(define BLANK 0)
(define ROWS 10)  
(define COLUMNS 10)
(define DEFAULT-DEPTH 2)

(define-struct world-state (position whose-turn settings other-info))
;; position is what checkers are on the board
;; whose-turn is the player who is about to move
;; settings and other-info are future functionality

;Generative Recursion template
#;(define (genrec p)
  (if (trivial? p)
   (trivial-answer p)
   (... p
        (genrec (reduce p)))))

;; --------------------------------

;; returns the checker color (RED, BLACK, or BLANK) of the specified position
;; on the board
(define (piece-at board row column)
  (get-nth column (get-nth row board)))

;; check-win:  world-state --> boolean
;; determines whether the game has ended with a victory for whoever just moved
(define (check-win? state)
  (local [
          ;; !!! should go back and fix these functions with piece-at function
          (define (up-column board color x y)
            (if (< y 3)
                false
                (local [(define column (get-nth x board))]
                  (= (get-nth  (- y 1) column)
                     (get-nth  (- y 2) column)
                     (get-nth  (- y 3) column)
                     color))))
          
          (define (right-row board color x y)
            (if (>= x (- COLUMNS 3))
                false
                (= (get-nth y (get-nth (+ 1 x) board))
                   (get-nth y (get-nth (+ 2 x) board))
                   (get-nth y (get-nth (+ 3 x) board))
                   color)))
          
          (define (up-right board color x y)
            (if (or (< y 3)
                    (>= x (- COLUMNS 3)))
                false
                (= (get-nth (- y 1) (get-nth ( + x 1) board))
                   (get-nth (- y 2) (get-nth ( + x 2) board))
                   (get-nth (- y 3) (get-nth ( + x 3) board))
                   color)))
          
          (define (down-right board color x y)
            (if (or (>= y (- ROWS 3))
                    (>= x (- COLUMNS 3)))
                false
                (= (get-nth (+ y 1) (get-nth ( + x 1) board))
                   (get-nth (+ y 2) (get-nth ( + x 2) board))
                   (get-nth (+ y 3) (get-nth ( + x 3) board))
                   color)))
          
          (define (victory? board x y)
            (let
                ([color (get-nth y (get-nth x board))])
              (if (= color BLANK)
                  false
                  (or
                   (up-column board color x y)
                   (right-row board color x y)
                   (up-right board color x y)
                   (down-right board color x y)))))
          
          (define (walk-column board col row)
            (cond
              [(= row ROWS) false]
              [else
               (or
                (victory? board col row)
                (walk-column board col (+ 1 row)))]))
          
          (define (walk-board board col)
            (cond
              [(= col COLUMNS) false]
              [else
               (or (walk-column board col 0)
                   (walk-board board (+ 1 col)))]))]
    (walk-board (world-state-position state) 0)))

;; Provided Code
;; Natural List --> Element
;; returns the nth element of a list.  for former LISP programmers learning Racket :-)
(define (get-nth n alist)
  (list-ref alist n))

;; Main was modified to take in a difficulty

(define (main typeofAI)
  (local [
(define (main1 state AI)
  (local 
    [(define board 
       (make-list ROWS
                  (make-list COLUMNS 0)))
     
     (define PIECE-SIZE 30)
     
     (define RED-CHECKER (circle PIECE-SIZE "solid" "red"))
     (define BLACK-CHECKER (circle PIECE-SIZE "solid" "black"))
     (define BLANK-CHECKER (circle PIECE-SIZE "solid" "white"))
     
     (define OFFSET (/ PIECE-SIZE .66))
     (define WIDTH
       (+ (* COLUMNS 2.5 PIECE-SIZE) (* 0.5 PIECE-SIZE)))
     (define HEIGHT
       (+ (* ROWS 2.5 PIECE-SIZE) (* 0.5 PIECE-SIZE)))
     
     (define MTS 
       (rectangle WIDTH HEIGHT "solid" "yellow"))
     (define (place-checker state x y mouse-event)
       (local
         [(define move (map-coordinates x y))
          (define next-state (make-move state move))]
         (cond
           [(and (string=? mouse-event "button-down")
                 (member move (legal-next-moves state)))
            (if (check-win? next-state)  
                (cond
                  [(= (world-state-whose-turn state) RED)
                   "RED WINS"]
                  [else "BLACK WINS"])
                (local [(define result (computer-moves AI next-state))]
                  (if (check-win? result)
                      (cond
                        [(= (world-state-whose-turn next-state) RED)
                         "RED WINS"]
                        [else "BLACK WINS"])
                      result)))]
           [else state])))
     (define (display-column2 column x-offset y-offset image)
       x-offset)
     (define (display-column column x-offset y-offset image)
       (cond
         [(empty? column) image]
         [else
          (place-image
           (cond 
             [(= (first column) RED) RED-CHECKER]
             [(= (first column) BLACK) BLACK-CHECKER]
             [(= (first column) BLANK) BLANK-CHECKER])
           x-offset y-offset 
           (display-column (rest column) x-offset (+ y-offset (* 2.5 PIECE-SIZE)) image))]))
     
     (define (display-board-helper position x-offset image)
       (cond 
         [(empty? position) image]
         [else
          (display-board-helper
           (rest position)
           (+ x-offset (* 2.5 PIECE-SIZE))
           (display-column (first position)
                           x-offset
                           OFFSET image))]))
     
     (define (display-board position)
       (display-board-helper position OFFSET MTS))
     (define (render state)
       (display-board (world-state-position state)))
     
     (define (map-coordinate lower upper click pos)
       (cond
         [(and (> click lower) (< click upper)) pos]
         [(> pos (max ROWS COLUMNS)) -1]
         [else
          (map-coordinate (+ lower (* 2.5 PIECE-SIZE)) (+ upper (* 2.5 PIECE-SIZE)) click (+ 1 pos))]))
     
     (define (map-coordinates x y) 
       (list (map-coordinate (/ PIECE-SIZE 2) (+  (/ PIECE-SIZE 2) (* 2 PIECE-SIZE)) x 0)
             (map-coordinate (/ PIECE-SIZE 2) (+  (/ PIECE-SIZE 2) (* 2 PIECE-SIZE)) y 0)))]
    
    (big-bang state 
              (on-mouse place-checker) 
              (to-draw render))))] (main1 start-state typeofAI)))

;; *** this function permits you to make both legal and illegal moves
;; *** you do not need to use this function and probably should not.  someone thought of a reason
;; *** for it to exist and so i included it.  to be clear, your program is only permitted to 
;; *** make legal moves.
(define (make-hypothetical-move state move)
  (local [(define (update-column turn column current move)
            (cond
              [(empty? column) empty]
              [else
               (cons
                (cond
                  [(= current move)
                   turn]
                  [else (first column)])
                (update-column turn (rest column) (+ 1 current) move))]))
          
          (define (do-move board turn move-x move-y current-x)
            (cond
              [(empty? board) empty]
              [else
               (cons
                (cond
                  [(= move-x current-x) (update-column turn (first board) 0 move-y)]
                  [else (first board)])
                (do-move (rest board) turn move-x move-y (+ 1 current-x)))]))]
        (make-world-state
         (do-move (world-state-position state)
                  (world-state-whose-turn state) 
                  (first move) (second move) 0)
         (cond
           [(= (world-state-whose-turn state) RED) BLACK]
           [(= (world-state-whose-turn state) BLACK) RED])
         (world-state-settings state)
         (world-state-other-info state))))

(define (make-move state move)
   (if (member move (legal-next-moves state))
       (make-hypothetical-move state move)
       state))

;; world-state --> list
;; returns all of the legal moves for the current position
(define (legal-next-moves state)
  (local [
          (define (first-blank column pos)
            (cond
              [(empty? column) (- pos 1)]
              [(not (= (first column) BLANK))
               (- pos 1)]
              [else (first-blank (rest column) (+ 1 pos))]))
          (define (get-moves board-state column)
            (cond
              [(empty? board-state) empty]
              [else
               (local [(define blank (first-blank (first board-state) 0))]
                 (if (< blank 0)
                     (get-moves (rest board-state) (+ 1 column))
                     (cons
                      (list column (first-blank (first board-state) 0))
                      (get-moves (rest board-state) (+ 1 column)))))]))]
    (get-moves (world-state-position state)
               0)))

;; --------------------------------------------
;; Code

;; Signature: state --> state
;; Purpose: To have the computer make a move

(check-expect (computer-moves evaluation-function-complex computerstate1) computerwinstate)
(check-expect (computer-moves evaluation-function-complex humanteststate) humanteststate2)

(define (computer-moves AI st)
  (local
    [
     (define (index el ls ind)
       (cond [(empty? ls) false]
             [(= el (first ls)) ind]
             [else (index el (rest ls) (+ 1 ind))]))
     (define (hum-evaluation-function state)
       (cond
         [(n-in-a-row state 4 0 RED) 5]
         [(n-in-a-row state 3 1 RED) 4]
         [(n-in-a-row state 2 2 RED) 3]
         [else 0]))
     (define (one-move state player fn eval)
       (local [(define s (make-world-state
                          (world-state-position state)
                          player
                          (world-state-settings state)
                          (world-state-other-info state)))
               (define hum-moves (legal-next-moves s))]
         (list (apply fn (map (lambda (mv) (eval (make-move s mv))) hum-moves))
               (list-ref hum-moves
                         (index (apply fn (map (lambda (mv) (eval (make-move s mv))) hum-moves))
                                (map (lambda (mv) (eval (make-move s mv))) hum-moves)
                                0)))))
     (define (comp-moves AI1 state)
       (local [(define (first-func fn ls)
                 (if (odd? DEFAULT-DEPTH) (argmin fn ls)
                     (argmax fn ls)))
               (define (second-func ls)
                 (if (odd? DEFAULT-DEPTH) (apply max ls)
                     (apply min ls)))
               (define (third-func ls)
                 (if (odd? DEFAULT-DEPTH) (apply min ls)
                     (apply max ls)))
          
               (define (collecting-moves curr-state dep)
                 (cond
                   [(zero? dep) (AI1 curr-state)]
                   [(odd? dep) (second-func (map (lambda (mv) (collecting-moves (make-move curr-state mv) (- dep 1)))
                                                 (legal-next-moves curr-state)))]
                   [else (third-func
                          (map (lambda (mv)
                                 (collecting-moves (make-move curr-state mv) (- dep 1)))
                               (legal-next-moves curr-state)))]))
               (define (final-choice state dep)
                 (list (third-func (map (lambda (mv) (collecting-moves
                                                      (make-move state mv) dep)) (legal-next-moves state)))
                       (first-func (lambda (mv) (collecting-moves
                                                 (make-move state mv) dep)) (legal-next-moves state))))]
         (final-choice state (- DEFAULT-DEPTH 1))))
     ]
    (cond [(= -5 (first (one-move st BLACK min AI))) (make-move st (first (rest (one-move st BLACK min AI))))]
          [(= 5 (first (one-move st RED max hum-evaluation-function))) (make-move st (first (rest (one-move st RED max hum-evaluation-function))))]
          [else (make-move st (first (rest (comp-moves AI st))))]))) 
    
;; Signature: state --> integer
;; Purpose: To evaluate a board to see how good it is for a player
;; Test cases:
(check-expect (evaluation-function-complex computerwinstate) -5)
(check-expect (evaluation-function-complex humanwinstate) 5)
(check-expect (evaluation-function-complex start-state) 0)
(check-expect (evaluation-function-complex computerstate1) -4)
(check-expect (evaluation-function-complex teststate) -3)
 
(define (evaluation-function-complex state)
  (cond
    [(n-in-a-row state 4 0 BLACK) -5]
    [(n-in-a-row state 4 0 RED) 5]
    [(n-in-a-row state 3 1 BLACK) -4]
    [(n-in-a-row state 3 1 RED) 4]
    [(n-in-a-row state 2 2 BLACK) -3]
    [(n-in-a-row state 2 2 RED) 3]
    [(n-in-a-row state 2 1 BLACK) -2]
    [(n-in-a-row state 2 1 RED) 2]
    [(n-in-a-row state 1 1 BLACK) -1]
    [(n-in-a-row state 1 1 RED) 1]
    [else 0]
    ))

;; Signature: state --> integer
;; Purpose: To evaluate a board to see how good it is for a player, but simpler
;; Test cases:
(check-expect (evaluation-function-simple computerwinstate) -1)
(check-expect (evaluation-function-simple humanwinstate) 1)
(check-expect (evaluation-function-simple start-state) 0)
(check-expect (evaluation-function-simple computerstate1) 0)

(define (evaluation-function-simple state)
  (cond
    [(n-in-a-row state 4 0 BLACK) -1]
    [(n-in-a-row state 4 0 RED) 1]
    [else 0]))

;; Signature: state natural natural natural[1,2] --> boolean
;; Purpose: To determine if there are n in a row pieces for a player with 'blank' number of blanks on either side
;; Test cases:
(check-expect (n-in-a-row computerwinstate 4 0 BLACK) true)
(check-expect (n-in-a-row humanwinstate 4 0 RED) true)
(check-expect (n-in-a-row computerwinstate 4 0 RED) false)
(check-expect (n-in-a-row start-state 4 0 RED) false)
(check-expect (n-in-a-row computerstate1 4 0 RED) false)
(check-expect (n-in-a-row computerstate1 3 1 BLACK) true)

(define (n-in-a-row state num blanks player)
  (local [
          (define num-in-row (- num 1))
          (define board (world-state-position state))
                   
          (define (all-equal? r c do-row do-col do-row-blank do-col-blank range blanks-left lim)
            (if (= range -1) true
                (and
                 (or (= 0 blanks) (>= lim blanks-left) (= BLANK (piece-at board (do-row-blank r blanks-left) (do-col-blank c blanks-left))))
                 (= player (piece-at board (do-row r range) (do-col c range)))
                     (all-equal? r c do-row do-col do-row-blank do-col-blank (- range 1) (- blanks-left 1) lim))))

          (define (check-this-one r c false-cond do-row do-col do-row-blank do-col-blank range blanks-left lim)
            (if (false-cond r c) false
                (all-equal? r c do-row do-col do-row-blank do-col-blank range blanks-left lim)))
          
          (define (up-column-down-blanks c r) 
            (check-this-one r c (lambda (r c) (or (< r blanks) (>= r (- ROWS num-in-row))))
                            +
                            (lambda (c range) c)
                            -
                            (lambda (c blanks) c)
                            num-in-row
                            blanks
                            0))
          (define (up-column-up-blanks c r)
            (check-this-one r c (lambda (r c) (>= r (- ROWS num-in-row blanks)))
                            +
                            (lambda (c range) c)
                            +
                            (lambda (c blanks) c)
                            num-in-row
                            (+ num-in-row blanks)
                            num-in-row))
          (define (right-row-left-blanks c r)
            (check-this-one r c (lambda (r c) (or (< c blanks) (>= c (- COLUMNS num-in-row))))
                            (lambda (r range) r)
                            +
                            (lambda (r blanks) r)
                            -
                            num-in-row
                            blanks
                            0))
          (define (right-row-right-blanks c r)
            (check-this-one r c (lambda (r c) (>= c (- COLUMNS num-in-row blanks)))
                            (lambda (r range) r)
                            +
                            (lambda (r blanks) r)
                            +
                            num-in-row
                            (+ num-in-row blanks)
                            num-in-row))
          (define (down-right-down-blanks c r)
            (check-this-one r c (lambda (r c) (or (>= r (- ROWS num-in-row blanks)) (>= c (- COLUMNS num-in-row blanks))))
                            +
                            +
                            + 
                            +
                            num-in-row
                            (+ num-in-row blanks)
                            num-in-row))
          (define (down-right-up-blanks c r)
            (check-this-one r c (lambda (r c) (or (> blanks r) (> blanks c) (>= r (- ROWS num-in-row)) (>= c (- COLUMNS num-in-row))))
                            +
                            +
                            -
                            -
                            num-in-row
                            blanks
                            0))
          (define (up-right-up-blanks c r)
            (check-this-one r c (lambda (r c) (or (> (+ num-in-row blanks) r) (>= c (- COLUMNS num-in-row blanks))))
                            -
                            +
                            -
                            +
                            num-in-row
                            (+ num-in-row blanks)
                            num-in-row))
           (define (up-right-down-blanks c r)
            (check-this-one r c (lambda (r c) (or (> blanks c) (> num-in-row r) (>= c (- COLUMNS num-in-row)) (>= r (- ROWS blanks))))
                            -
                            +
                            + 
                            - 
                            num-in-row
                            blanks
                            0))
          (define (victory? c r)
            (if (= player BLANK)
                false
                (or
                 (up-column-up-blanks c r)
                 (up-column-down-blanks c r)
                 (right-row-right-blanks c r)
                 (right-row-left-blanks c r)
                 (down-right-down-blanks c r)
                 (down-right-up-blanks c r)
                 (up-right-up-blanks c r)
                 (up-right-down-blanks c r))))
          (define (walk-column col row)
            (cond
              [(= row ROWS) false]
              [else
               (or
                (victory? col row)
                (walk-column col (+ 1 row)))]))
          (define (walk-board col)
            (cond
              [(= col COLUMNS) false]
              [else
               (or (walk-column col 0)
                   (walk-board (+ 1 col)))]))]
    (walk-board 0)))

;; -----------------------------------

(define START-BOARD
  (make-list COLUMNS
             (make-list ROWS BLANK)))
(define start-state
  (make-world-state START-BOARD RED 5 empty))

(define humanw1
  (list 
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 2)
  (list 0 0 0 0 0 0 0 0 0 1)
  (list 0 0 0 0 0 0 0 0 0 1)
  (list 0 0 0 0 0 0 0 2 2 1)
  (list 0 0 0 0 0 0 0 2 1 1)))

(define humanwin1
  (list 
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 1)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 1)
  (list 0 0 0 0 0 0 0 2 2 1)
  (list 0 0 0 0 0 0 0 2 1 1)))

(define humanwin2
  (list 
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 1)
  (list 0 0 0 0 0 0 0 0 0 1)
  (list 0 0 0 0 0 0 0 0 0 1)
  (list 0 0 0 0 0 0 0 2 2 1)
  (list 0 0 0 0 0 0 0 2 1 1)))

(define computerb1
  (list 
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 1)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 2)
  (list 0 0 0 0 0 0 0 1 1 2)
  (list 0 0 0 0 0 0 0 1 2 2)))
(define testboard1
  (list 
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 2)
  (list 0 0 0 0 0 0 0 0 0 2)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 1)
  (list 0 0 0 0 0 0 0 0 0 2)
  (list 0 0 0 0 0 0 0 0 2 2)
  (list 0 0 0 0 0 0 0 1 2 1)
  (list 0 0 0 0 0 0 0 1 1 2)
  (list 0 0 0 0 0 0 0 0 0 2)))

(define computerbwin
  (list 
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 0)
  (list 0 0 0 0 0 0 0 0 0 1)
  (list 0 0 0 0 0 0 0 0 0 2)
  (list 0 0 0 0 0 0 0 0 0 2)
  (list 0 0 0 0 0 0 0 1 1 2)
  (list 0 0 0 0 0 0 0 1 2 2)))

(define humanteststate
  (make-world-state humanwin1 RED 5 empty))

(define humanteststate2
  (make-world-state humanwin2 BLACK 5 empty))

(define teststate
  (make-world-state testboard1 RED 5 empty))

(define humanwinstate
  (make-world-state humanw1 RED 5 empty))

(define computerstate1
  (make-world-state computerb1 BLACK 5 empty))

(define computerwinstate
  (make-world-state computerbwin RED 5 empty))

(define simple-player evaluation-function-simple)
(define complex-player evaluation-function-complex)

(main complex-player)



;1. With a 5 second limit, our computer player is able to use a max depth of 2 for the complex evaluation function. However, for the simple evaluation function, it is able to reach depth
;three in this time frame. The complex function is a better player because it sees many more board varieties.
;
;2. During testing, our program has proven to be fairly good at countering the human player. It is able to detect if the player is going for rows of pieces, and then attempts to counteract
;the human’s play. We found that it is very good at blocking and making sure that the human does not win, but sometimes overlooks times when it can win. This is one problem that we found
;in our program, and is something we would adjust if we were to keep working on the project.
