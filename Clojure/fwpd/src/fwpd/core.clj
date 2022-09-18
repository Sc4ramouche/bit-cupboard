(ns fwpd.core)
(def filename "suspects.csv")

(def vamp-keys [:name :glitter-index])

(defn str->int
  [str]
  (Integer. str))

(def conversions {:name identity
                  :glitter-index str->int})
(defn convert
  [vamp-key value]
  ((get conversions vamp-key) value))

(defn parse
  "Convert a CSV into rows of columns"
  [string]
  (map #(clojure.string/split % #",")
       (clojure.string/split string #"\n")))

(defn mapify
  ""
  [rows]
  (map (fn [unmapped-row]
         (reduce (fn [row-map [vamp-key value]]
                   (assoc row-map vamp-key (convert vamp-key value)))
                 {}
                 (map vector vamp-keys unmapped-row)))
       rows))

(defn glitter-filter
  [minimum-glitter records]
  (filter #(>= (:glitter-index %) minimum-glitter) records))

(def suspects-map (mapify (parse (slurp filename))))

                                        ; ex_1
(defn suspect-names
  [records]
  (map :name (glitter-filter 3 records)))

                                        ; ex_2
(defn append-suspect
  [new-suspect records]
  (conj records new-suspect))

                                        ; ex_3
(def validations {:name string?
                  :glitter-index int?})

(defn validate
  [val-map record]
  (every? (fn [rec]
            (println (get record rec))
            ((get val-map rec) (get record rec))) (keys val-map)))

                                        ; ex_4
(validate validations {:name "Vlid" :glitter-index 1})
(defn record-to-row
  [{:keys [name glitter-index]}]
  (clojure.string/join "," [name glitter-index]))

(defn map-to-csv
  [records]
  (clojure.string/join "\n" (map record-to-row records)))

(defn sum ([vals] (sum vals 0))
  ([vals accumulating-total]
   (if (empty? vals)
     accumulating-total
     (recur (rest vals) (+ (first vals) accumulating-total)))))


;; add a note on using `recur`.
;; add a note on using shortcuts on require, an example:
;;(require '[clojure.string as s])
((comp inc *) 2 3)
