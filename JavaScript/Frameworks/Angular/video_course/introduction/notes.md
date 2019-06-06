# Introduction

## What is Angular

Angular is not framework, it's platform as stated in the documentation. The reason for this is Angular includes Framework itself, but it also has Component Library and Tooling.

## Angular Features

* Dependency Injection
* Change Detection
* Two Approaches to Work with Forms
* Fully Featured Router
* Modules Lazy Loading
* RxJS Library
* Rendering Targets

## Angular Angular Architecture

### Angular Modules

`@NgModule` decorator is used to describe the class to which decorator is applied.

```TypeScript
@NgModule({
    declarations:    [ AppComponent ],     // components, directives, pipes
    providers:       [ Logger ],           // services
    imports:         [ BrowserModule ],    // modules
    exports          [ ],                  // public components
    entryComponents: [ ],                  // dynamic loaded components, elements
    bootstrap:       [ AppComponent ],     // root component
    schema:          [ ],                  // NO_ERRORS_SCHEMA, CUSTOM_ELEMENTS_SCHEMA
})
export class AppModule { }
```

`@NgModule` options:

* `declarations` – contains Components, Directives and Pipes which are belong to the module.
* `provides` – here we declare Service classes.
* `imports` – contain other modules used
* `exports` – directives and pipes that we declare publicly for other modules to use
* `entryComponents` – components that loaded imperatively (we're not referencing them in the template)
* `bootstrap` – contains root component
* `schema` – allows to use custom elements

### `main.ts`

`main.ts` is the entry point for the Angular app.

### Components

Components are a mix of three things: Class, Template and Data.

**Property Binding** allows to send Data from Class to Template, while **Event Binding** allows to inform Class about Template changes.

You can only use public methods of the Class in its Template.

### Data Binding

There are four main ways to transfer data between Template and Class:

* Interpolation:   `{{task.action}}`                Class ---> Template
* One Way Binding: `[task]="selectedTask"`          Class ---> Template
* Event Binding:   `(click)="onSelectTask(task)"`   Class <--- Template
* Two Way Binding: `[(ngModel)]="task.action"`      Class <--> Template

### Built-in Directive

Structural Directives:

* `*ngFor`
* `*ngIf`
* `ngSwitch`, `*ngSwitchCase`, `*ngSwitchDefault`

Attribute Directives:

* `ngModel`
* `ngStyle`
* `ngClass`
* `ngNonBindable`

### `*ngIf` Under the Hood

```TypeScript
// * Prefix
<app-hero-detail *ngIf="selectedHero" [hero]="selectedHero">
</app-hero-detail>

// Step 1
<app-hero-detail template="ngIf selectedHero" [hero]="selectedHero">
</app-task-detail>

// Step 2
<ng-template [ngIf]="selectedTask">
    <app-hero-detail [hero]="selectedHero"></app-hero-detail>
</ng-template>
```

### `*ngIf` Syntax

```TypeScript
// simple Form:
<div *ngIf="condition">/*...*/</div>

// with `else` block:
<div *ngIf="condition; else elseBlock">/*...*/</div>
<ng-template #elseBlock>/*...*/</ng-template>

// with a `then` and `else` block:
<div *ngIf="condition; then thenBlock else elseBlock"></div> // this div never reaches DOM
<ng-template #thenBlock>/*...*/</ng-template>
<ng-template #elseBlock>/*...*/</ng-template>

// storing the value locally:
<div *ngIf="condition as value; else elseBlock">{{value}}</div>
<ng-template #elseBlock>/*...*/</ng-template>
```

### `ngSwitch` Syntax

```TypeScript
<td [ngSwitch]="task.done">
    <span *ngSwitchCase="true">Yes</span>
    <span *ngSwitchDefault>No</span>
</td>
```

### Services

In general *Services* are just classes whose purpose is to implement some logic.

```TypeScript
import { Injectable } from '@angular/core';

@Injectable()
export class HeroService {
    getHeroes() {
        return [
            'Hulk',
            'Vision',
        ];
    }
}
```

We don't have to use `@Injectable` if Service has no `constructor`. By convention `@Injectable` is always applied.

### Dependency Injection

```TypeScript
import { HeroService } from './hero.service';

@Component ({
    /*...*/,
    providers: [HeroSevice]
})
export class HeroListComponent {
    // inject service
    constructor(private heroService: HeroService) {}
}
```

Injection here means the following: we create property `heroService` for instance of `HeroListComponent` class and then we initialize this property as `HeroService` instance. Note that we have explicitly state *modifier* (`private` in example above) here for this thing to work.

### Built-in Pipes

```TypeScript
<p>{{ expession | pipeName : param 1 : param 2}}</p>

// Example
<p>{{ 'Angular' | slice: 3 | uppercase }}</p> // 'Angular' --> 'ular' --> 'ULAR'
```

### Custom Pipes

Custom pipe is just a class that only contains `transform` method.

```TypeScript
import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
    name: 'age'
)}
export class AgePipe implements PipeTransfrom {
    transform(value: any, ...args?: any): any {
        return `${value} years old`;
    }
}
```

## Angular CLI & Angular Console

### Main Commands

* ng new
* ng generate | ng g
* ng lint | ng l
* ng build | ng b
* ng serve | ng s
* ng test | ng t
* ng e2e | ng e
