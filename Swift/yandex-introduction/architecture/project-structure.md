# Project Structure

## `AppDelegate`

This class is responsible for communication with the OS.

By default it contains `applicationDidFinishLaunchingWithOptions` method which is executed right application kick off.

## xcodeproj

That's not actually a file, it's a package. You can peek inside with right click. `pbxproj` – representation of the project that will be shown in the project navigator.

## Target

In terms of Xcode *target* is a separate product being built. You can examine it in the *Products* tab. Target links files needed to itself for build process.

## Scheme

Represent settings for build, testing and execute. Schemes could be shared. Testing and execution options are set via scheme.

# Package Managment

## CocoaPods

To use third party code in you app you can use package manager – CocoaPods is the most popular as for time of this note.

First you need to run `pod init` in your project root folder. **Important:** After that you should open you project via `project.xcworkspace`, not by `project.xcodeproj`.

If you look inside `Podfile`, you'll see `use_frameworks!` directive. This is used to manage frameworks dynamically or statically. Best practice is to use frameworks statically, i.e. include them as part of the app binary.
