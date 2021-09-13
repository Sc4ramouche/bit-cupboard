;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname ex_5) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)

(define crossed-circle (scene+line (ellipse 30 30 "outline" "maroon")
            0 15 30 15 "maroon"))

(define half-circle (underlay/align "middle" "top"
                                    crossed-circle
                                    (rectangle 30 15 "solid" "white")))

(define boat (scene+line half-circle
                         15 0  15 15 "maroon"))

boat