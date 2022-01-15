# http_pleasant
A simple Fork of [http.h by mattiasgustavsson](https://github.com/mattiasgustavsson/libs) 

![Redownloading CodeBlocks from my site](https://raw.githubusercontent.com/pawbyte/http_pleasant/main/gfx/console_downloader_via_http.gif)

# Make Get and Post request over HTPP( https not supported, no SSL support "yet")

#Functions:

http_get
--------

    http_t* http_get( char const* url, void* memctx )

Sends a get request to a website via htpp.  If the request was invalid, `http_get` returns NULL.


http_post
---------

    http_t* http_post( char const* url, void const* data, size_t size, void* memctx )

  Sends a post request to a website via htpp.  If the request was invalid, `http_post` returns NULL.


http_process
------------

    http_status_t http_process( http_t* http )

  Call each game frame or in a while loop until file has successfully downloaded or failed.
   Access the current file download and meta-data.


http_release
------------

    void http_release( http_t* http )

  Call using the post and get functions.
  

Donate to make http_pleasant greater
=========================================
Work on open source projects like this is not possible without funding. The amount of time it takes to update the codebases, create examples, tutorials and more is quite expensive. Please consider either a one-time or monthly donation to keep this engine going and more frequently updated. 

We have a [Patron Page](https://www.patreon.com/pawbyte?ty=h) that you can help fund future open source projects and the updates to this one.

There is also a [PayPal](http://www.pawbyte.com/donate/) one time donation method as well. 

I appreciate your generousity and moving this project forward. 
