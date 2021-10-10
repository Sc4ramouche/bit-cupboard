(defn titleize
  [title]
  (str title " for Dummies"))

; map can work with different data structures
(map titleize ["TS" "Rust"]) ; vector
(map titleize '("FP" "OOP")) ; list
(map titleize #{"TDD" "UT"}) ; set
(map #(titleize (second %)) {:a "Agile" :b "Scrum"}) ; map

; map can also intake several collections at once
(map str ["a" "b" "c"] ["A" "B" "C"])
; => ("aA" "bB" "cC")

(take 3 [:a :b :c :d :f])
; => (:a :b :c)
(drop 3 [:a :b :c :d :f])
; => (:d :f)

;(some
; #(and (> (:critter %) 3) %) ; by using and we can access the element which produced "true"
; food-journal)
(take 3 (repeatedly (fn [] (rand-int 10))))
(take 3 (repeat "hey"))

(def seq-from-vector (map identity ["1" "2"]))
