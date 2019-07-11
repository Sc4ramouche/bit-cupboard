# MVC pattern

Model-View-Controller (MVC) is object-oriented design pattern. Generally you devide all the objects into 3 camps respectively to the name.

## Model

Model is **what** your application is (but **not** how it is displayed). It's UI independent set of objects.

Example of the model:

```Swift
struct Card {
    var isFaceUp = false
    var isMatched = false
    var identifier: Int
}
```

It might be alluring to also store card's content (emoji in the context of Concentration game being developed in this course). But model is UI independend so it's not appropriate to place this information in the model.

## Controller

Controller is **how** your *Model* is presented to the user (UI logic).

## View

View is *Controller*'s minions. These are usually very generic UI elements: `UIButton`, `UILabel`, etc. *Controller* has to communicate with the *Model* to get the idea to the UI.

## Communication

MVC is all about managing communication between camps.

*Controllers* can always talk directly to their *Model*. *Controllers* can also talk directly to their *View*. In iOS development this concept is represented by *outlets*.

*Model* can not directly communicate with the *View*. There are two reason for that:

1. The *Model* is UI independent
2. *View* objects are generic objects. They have no idea about *Model*.

### View -> Controller Communication

*View* can't speak to it's controller. But it kinda has to, indication that button has been pressed etc. But this communication has to be *blind* and structured, because *Views* are generic objects and buttons don't know anything about your app controllers or if it even has one.

The *Controller* can drop a *target* on itself. Then it hands out an action to the *View*. The *View* sends the action when things happen in the UI.

But sometimes the *View* needs to synchronize with the *Controller*. For example when we're dealing with `ScrollView` – it kinda wants to know if it's okay to scroll further or we've already hit the bottom of the content. It needs to speak to the *Controller* as it's working to do its job. This can be achieved with predefined methods that `ScrollView` defines  as pard of its *Delegate*. The *Delegate* is just a `var` in `ScrollView` that contains some object in it. All we know about this object – it responds to a certain number of messages. Most of this messages start with the word 'will', 'should', or 'did'. Controller sets itslef as the `ScrollView`'s delegate and *View* knows that *Controller* has implementations of those `willYadaYada` and `shouldEtcEtc` methods. The delegate is set via a *Protocols* (i.e. it's *blind* to class).

Views do not own the data they display. They don't store the data as a part of their instance variables. In this scenarion *Controller* is playing role a data provider.

So in general *Controller's* job is to interpret and format model's information for the *View*. And it works in the other direction as well – it interprets the user actions into *Model*.

### Model -> Controller Communication

*Model* can't talk to *Controller* directly, as *Controller* is UI dependend, while Model is not fundamentally. But it has to tell the *Controller* that something might have been changed. So the *Model* starts something alike to broadcasting – *Controllers* are listening for the changes. And when something happens *Controller* needs to know about – it's just going to grab what in needs. In iOS development this way of communication is called *Notification* or *KVO* observing.

## MVC in use

Usually one MVC is used to control one screen on iPhone. It may control part of the app on bit iPad screen. You won't have more than one screen on iPhone controlled by single MVC. So MVC usually goes with a grouping of UI (again, it's usually one phone screen).

### MVCs working together

So if we have multiple MVCs, the higher MVC treats other MVCs as part of it's *View*.

# Structs and Classes

In Swift structs are very similar to Classes. But they have two major differences:

1. There is no *inheritance* for structs.
2. Structs are **value** types and Classes are **reference** types.

For the second statements: value types gets copied when it's passed around. This might sound inefficient, but in Swift it's not as it follows the *copy on write* semantics.

For the reference type, when you pass it around you just pass the pointer to it.

# Side Notes from the lecture

Array are structures in Swift, so they're value type. So there's several methods to add two identical things to array:

```Swift
let card = Card()
let matchingCard = card
cards.append(card)
cards.append(matchingCard)

/* we don't really need to create
 * matching card, as it's being
 * passed as a copy anyway
 */
let card = Card()
cards.append(card)
cards.append(card)

/* arrays support 'add' operation
 * so we easily put two copies in it
 */
let card = Card()
cards += [card, card]
```

## Static Functions and Properties

Static function is a function that belongs to the type itself. So we don't have this static things on instances themselves.

When you're working with static functions you don't have to prefix access to static properties with type:

```Swift
struct Card {
    /* ... */
    static var identifierFactory = 0
    static func getUniqueIdentifier() -> {
        identifierFactory += 1
        return identifierFactory
    }
}
```

## `lazy`

When you initialize some class and this initialization depends on other property of the same class, you'll get 'Cannot use instance membet %property% within property initializer'. Swift has workaround for this, which is `lazy` keyword. It postpones initialization for the moment someone actually uses this property:

```Swift
class ViewController: UIViewController {
    // you'd get error here without `lazy` because of `cardButtons`
    lazy var game = Concentration(numberOfPairsOfCards: (cardButtons.count + 1) / 2)

    @IBOutlet var cardButtons: [UIButton]!
}
```

But there's drawback of `lazy` – you can't have property observers with that, like `didSet` hook etc.

## Iterating through array

If you'd ever need to iterate through array with indices only there is pretty self describing way to do this:

```Swift
for index in 0..<array.count {
    /* explicit iterable range creation */
}

for index in array.indices {
    /* nice and readable */
}
```

## Elegant `nil` check

The following code returns one of the emoji `Dictionary` values in case it's not `nil`:

```Swift
return emoji[index] ?? "?"
```

## Back to back `if` statements

You can refactor nested `if` statements:

```Swift
if something == nil {
    if array.count > 0 {
        /* ... */
    }
}

// same thing
if something == nil, array.count > 0 {
    /* ... */
}
```
