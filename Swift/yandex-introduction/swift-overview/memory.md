# Memory

Objective-C uses *MRC* (Manual Reference Counting) model to manage memory. Every Object inhereted from `NSObject` had reference count, which was incremented in case someone wanted to own this object and decremented if owner stated that he doesn't use this object anymore. This was achieved by calling `alloc`, `retain`, `copy`, `release`, and `autorelease` functions of the object [workflow example in the video](https://stepik.org/lesson/211133/step/3?unit=184610).

ARC stands for *Automatic Reference Counting*. In this model compiler manages calls to `alloc`, `release`, `autorelease` etc. This concept should not be confused with garbage collector as ARC works in a strictly determined way and on compilation stage only. Compiler analyzes program flow and detects when objects are being created, how these objects interact with other classes and when they should be destroyed.

This allows Swift programs not to waste time on collecting garbage. Another advantage is that objects are being destroyed when it's specified by program flow, not during garbage collector predetermined cleaning time frames.

## Retain cycle

There could be the case when several object reference each other and none of the other outer objects have any reference to that group. In this scenario ARC can't release those object as their *reference count* is not equal to zero. This causes a memory leak.

For this cycle to break you'd need to mark one of the references as `weak` reference. This concept depicts *hanging reference* – they don't affect reference count. In Swift `weak` reference are treated like `Optional` value.

Common case for the retain cycle to occur is parent-child relation, when parent has a reference to the child and child has a reference to the parent. In this case it's recommended to make child to parent reference as a `weak` one.
