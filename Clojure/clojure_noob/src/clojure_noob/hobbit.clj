(def asym-hobbit-body-parts [{:name "head" :size 3}
                             {:name "left-eye" :size 1}
                             {:name "left-ear" :size 1}
                             {:name "mouth" :size 1}
                             {:name "nose" :size 1}
                             {:name "neck" :size 2}
                             {:name "left-shoulder" :size 3}
                             {:name "left-upper-arm" :size 3}
                             {:name "chest" :size 10}
                             {:name "back" :size 10}
                             {:name "left-forearm" :size 3}
                             {:name "abdomen" :size 6}
                             {:name "left-kidney" :size 1}
                             {:name "left-hand" :size 2}
                             {:name "left-knee" :size 2}
                             {:name "left-thigh" :size 4}
                             {:name "left-lower-leg" :size 3}
                             {:name "left-achilles" :size 1}
                             {:name "left-foot" :size 2}])
(defn matching-part
  [part]
  {:name (clojure.string/replace (:name part) #"^left-" "right-")
   :size (:size part)})

(defn symmetrize-body-parts
  "Expects a seq of maps that have a :name and :size"
  [asym-body-parts]
  (loop [remaining-asym-parts asym-body-parts final-body-parts []]
    (if (empty? remaining-asym-parts) final-body-parts
        (let [[part & remaining] remaining-asym-parts]
          (recur remaining
                 (into final-body-parts
                       (set [part (matching-part part)])))))))

; using reduce
(defn symmetrize-body-parts
  "Expects a seq of maps that have a :name and :size"
  [asym-body-parts]
  (reduce (fn [final-body-parts part]
            (into final-body-parts (set [part (matching-part part)])))
          []
          asym-body-parts))

;; playground below
(def dalmatians ["puppy 1" "puppy 2" "puppy 3" "puppy 4"])

(let [[first second & rest] dalmatians]
  (println first second rest))

(loop [iteration 0]
  (println (str "Iteration: " iteration))
  (if (> iteration 3)
    (println "Bye!")
    (recur (inc iteration))))

(defn recursive-fn
  ([]
   (recursive-fn 0))

  ([iteration]
   (println "Iteration: " iteration)
   (if (> iteration 3)
     (println "Bye!")
     (recursive-fn (inc iteration)))))

(recursive-fn)
