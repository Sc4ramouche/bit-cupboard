(ns clojure-noob.core
  (:gen-class))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))

(println "teapot is friend")

(defn train
  []
  (println "choo-choo"))

(+ 1 (* 2 3) 3 4)

(defn useless-func
  [input]
  (if (= input :yes)
    "Your decision: 'yes'"
    "Your decision: 'something else'"))

(def treasure {
                :lat 22 :lng 26 :code "you found it!"
                })

(defn tresure-decipher
  [{:keys [lat lng] :as location}]
  (println "coords:" lat lng)
  (println location))

(tresure-decipher treasure)

; Arity overloading
(defn overloaded
  ([lord power]
  (str "Dear " lord ", you got the power to " power))
  ([lord]
  (overloaded lord "tame cats")))

; Rest parameters
(defn favs
  [first second & rest]
  (println first second rest))

; Destructuring
(defn first-thing-only
  [[first]]
  (println first))

(defn not-just-first-thing
  [[first second & all-the-rest]]
  (println "first goes " first)
  (println "second goes " second)
  (println "and then goes all the rest: " all-the-rest))

(defn announce-tresure-location
  [{:keys [lat lng] :as trsr}]
  (println "The latitude is: " lat)
  (println "The longitude is: " lng)
  (println trsr))

(defn return-last
  []
  (+ 2 2)
  (* 5 5)
  (+ 9 1))

(def strange #(str "Hello." %1 %2 %&))

(defn inc-maker
  [x]
  #(+ x %))

(def inc-by-3 (inc-maker 3))
