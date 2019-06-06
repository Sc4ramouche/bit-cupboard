# Architecture overwie

The basic building blocks of an Angulular application are *NgModules*, which provide a compilation context for components. NgModules collect related code into functional sets. An app always has at least a *root module*, and typically has many more *feature modules*.

Components define *views*, which are sets of screen elements.

Components use *services*, which provide specififc functionality not directly related to views. Service providers can be injected into components as dependencies.

## Modules

Angular modularity system is built on *NgModules* – containers for a cohesive block of code dedicated to an application domain, a workflow, or a closely related set of capabiliters. They contain components, service providers, and other code files whose scope is defined by the containing NgModule. They can import functionality from other NgModules, and export selected functionality for use by other NgModules.

### NgModule metadata

An NgModule is defined by a class decorated with `@NgModule()` – a function that takes a single metadata object, whose properties describe the module. The most important properties:

* `declarations`: the components, directives, and pipes that belong to this NgModule;
* `exports`: the subset of declarations that should be visible to others NgModules component templates;
* `imports`: other modules whose exported classes are needed by component templates declared in this NgModule;
* `providers`: creators of services that this NgModule contributes to the global collection of services;
* `bootstrap`: main application view (root component). Should be set only in **root NgModule**.

Example:

```JavaScript
import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
@NgModule({
    imports:      [ BrowserModule ],
    providers:    [ Logger ],
    declarations: [ AppComponent ],
    bootstrap:    [ AppComponent ],
})
export class AppModule { }
```

### NgModules and components

NgModules provide a *compilation context* for their components. The components that belong to an NgModule share a compilation context.

When you create a component, it's associated directly with a single view, called the *host view*. 

## Components

A component controls a patch of the screen called a *view*. You define a component's application logic – what it does to support the view – inside a class. The class interacts with the view through an API of properties and methods.
