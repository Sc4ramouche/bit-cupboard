# [REST principles](https://ninenines.eu/docs/en/cowboy/2.0/guide/rest_principles/)

## REST is client-server

The client and server both have different set of concerns. *Server* stores and manipulates information while *client* takes that information and displays it to user. This style allows both client and server to evolve independently as it only requires interface stays the same.

## REST is stateless

Communication between the client and the server always contains all the information needed to perform the request. Session state is entirely client's concern.

## REST is cacheble

The client, the server and any intermediary components can all cache resources in order to improve performance.

## REST provides uniform interface

All components follow the same rules to speak to each other.

## REST is layered system

Individual components cannot see beyound the immediate layer with wich they are interacting. This implies extensibility and easy replacement.

## REST optionally provides code on demand

Code may be downloaded to extend client functionality.

### Resources

Resources is abstract concept. Basically any information that can be named may be a resource. Resource representation is a sequence of bytes associated with metadata. The metadata comes as the list of key-value pairs. In HTTP metadata is presented as set of request and response headers. Metadata comes in different forms: 

* Representational metadata - media type, date of last modification, etc.
* Resource metadata - could be link to related resources or info about additional representation.
* Control metadata - provides parameterizing to request or response. I.e. we may want to update resource only if it is more recent than the one we have in cache.

### Self-descriptive messages

Data format of representation must always come with its media type. This implies that the sender and recipient agree about what the media type refer to. You can even specify your own media types.

### Hypermedia as the engine of application state

The client does not need any prior knowledge of the service in order to use it, other than entry point and basic understanding of media type representations. Example: if your service works only with the `application/json` media type - it is not RESTful.

## Links

* [Roy T. Fielding's dissertation](https://www.ics.uci.edu/~fielding/pubs/dissertation/top.htm)