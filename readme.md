## neo4j-c-driver
A driver for neo4j for C, which uses the REST protocol. It is far from complete; development began 9/1/2012. 
The goals of the library are to provide some wrappers to libcurl and a json library to allow neo4j-specific
utility functions.

### dependencies

* libcurl >= 7.15
* json-c >= 0.9 (this might go away or change--still playing with it)
* libcheck >= 0.9 (for `make check` unit tests)

