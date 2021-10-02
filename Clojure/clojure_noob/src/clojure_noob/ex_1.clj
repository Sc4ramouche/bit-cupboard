; ex2
(defn add-100
  [x]
  (+ x 100))

; ex3
(defn dec-maker [x]
  #(- % x))

; ex4
(defn mapset
  [f coll]
  (set (map f coll)))
