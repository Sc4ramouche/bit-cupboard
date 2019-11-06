# iOS Architecture

iOS is represented by hierarchy of several layers:

* Cocoa (Application)
* Media
* Core Services
* Core OS
* Kernel and Device Drivers

## Kernel and Device Drivers

This layer's main job is to interact with hardware. It usually allocates and frees memory, handles network request and communicates with file system.

## Core OS

Provides two types of services:

1. Low level services for working with hardware, network and threads
2. Highl level services – that's about security

You don't usually interact with second type of services. *Accelerate* framework is an example of the first type of services – it could be used to run heavy calculations or to execute trained machine learning models.

## Core Services

Allows to communicate to *Core OS*. Includes:

1. Social Media Integration (SSO stuff)
2. iCloud Storage
3. GCD – multithreading interface
4. Maps
5. Core Services Frameworks

## Media

Provides basic interfaces to build UI, work with microphone and speakers. This is foundation for *Cocoa*. Allows to develop animations, 2D and 3D graphics.

## Cocoa

That's where you create your custom UI. Here you have `UIKit` and everything related.
